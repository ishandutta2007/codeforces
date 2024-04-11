#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct matrix{
	int n;
	ll a[75][75];
	matrix(){memset(a,0x3f,sizeof(a));for(int i=1;i<=70;i++)a[i][i]=0;n=0;}
	matrix operator*(const matrix c)const{
		matrix ret;
		ret.n=n;
		memset(ret.a,0x3f,sizeof(ret.a));
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) ret.a[i][j]=min(ret.a[i][j],a[i][k]+c.a[k][j]);
		return ret;
	}
	matrix operator^(int c)const{
		matrix ret,tmp=*this;
		ret.n=n;
		for(;c;c>>=1,tmp=tmp*tmp) if(c&1) ret=ret*tmp;
		return ret;
	}
};

int x,k,n,q,num;
int c[30],bel[300];
pii b[30];

int calc(int x){
	int num;
	for(num=0;x;x&=(x-1)) num++;
	return num;
}

int main(){
	matrix t,res;
	memset(res.a,0x3f,sizeof(res.a));
	x=readint(); k=readint(); n=readint(); q=readint();
	for(int i=1;i<=k;i++) c[i]=readint();
	for(int i=0;i<(1<<k);i++) if(calc(i)==x) bel[i]=++num;
	res.n=t.n=num;
	res.a[1][bel[(1<<x)-1]]=0;
	for(int i=1;i<=q;i++) b[i].fi=readint(),b[i].se=readint();
	sort(b+1,b+q+1);
	memset(t.a,0x3f,sizeof(t.a));
	for(int i=0;i<(1<<k);i++){
		if(!bel[i]) continue;
		int tmp=i;
		if(i&1){
			tmp>>=1;
			for(int j=0;j<k;j++) if(!((tmp>>j)&1)) t.a[bel[i]][bel[tmp|(1<<j)]]=c[j+1];
		}
		else t.a[bel[i]][bel[i>>1]]=0;
	}
	int lst=1; ll ans=0;
	for(int i=1;i<=q;i++){
		if(b[i].fi>n-x){
			ans+=b[i].se;
			continue;
		}
		res=res*(t^(b[i].fi-lst)),lst=b[i].fi;
		for(int j=1;j<(1<<k);j+=2)
			if(bel[j])
				res.a[1][bel[j]]+=b[i].se;
	}
	res=res*(t^(n-x+1-lst));
	cout<<res.a[1][bel[(1<<x)-1]]+ans<<endl;
	return 0;
}