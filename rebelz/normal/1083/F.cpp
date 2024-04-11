// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,q,num,cnt;
int a[200005],b[200005],val[200005],pl[200005],lf[200005],rg[200005],dfn[200005];

namespace block{
	int m,blo;
	int lf[1005],rg[1005],tag[1005],hv[1005][17000],a[200005],bl[200005];
	void init(){
		blo=sqrt(n+1);
		for(int i=1;i<=n+1;i+=blo) lf[++m]=i,rg[m]=min(i+blo-1,n+1);
		for(int i=1;i<=m;i++) for(int j=lf[i];j<=rg[i];j++) bl[j]=i;
		for(int i=1;i<=m;i++) for(int j=lf[i];j<=rg[i];j++) hv[i][a[j]]++;
	}
	void change(int l,int r,int x){
		int lb=bl[l],rb=bl[r];
		if(lb==rb){
			for(int i=l;i<=r;i++){
				hv[lb][a[i]]--;
				a[i]^=x;
				hv[lb][a[i]]++;
			}
			return;
		}
		for(int i=l;i<=rg[lb];i++){
			hv[lb][a[i]]--;
			a[i]^=x;
			hv[lb][a[i]]++;
		}
		for(int i=lf[rb];i<=r;i++){
			hv[rb][a[i]]--;
			a[i]^=x;
			hv[rb][a[i]]++;
		}
		for(int i=lb+1;i<=rb-1;i++) tag[i]^=x;
	}
	int getans(){
		int ret=0;
		for(int i=1;i<=m;i++) ret+=hv[i][tag[i]];
		return ret;
	}
}

int getans(){
	if(num) return -1;
	else return n+1-block::getans();
}

int main(){
	n=readint(); k=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) b[i]=readint();
	for(int i=1;i<=k;i++){
		lf[i]=cnt+1;
		for(int j=i;j<=n+1;j+=k) dfn[j]=++cnt,pl[j]=i;
		rg[i]=cnt;
	}
	for(int i=1;i<=n+1;i++) val[dfn[i]]=a[i]^b[i]^a[i-1]^b[i-1];
	for(int i=1;i<=k;i++) for(int j=lf[i]+1;j<=rg[i];j++) val[j]^=val[j-1];
	for(int i=1;i<=k;i++) if(val[rg[i]]) num++;
	for(int i=1;i<=n+1;i++) block::a[i]=val[i];
	block::init();
	printf("%d\n",getans());
	char opt[5]; int x,y;
	while(q--){
		scanf("%s",opt); x=readint(); y=readint();
		int bef=a[x]^b[x];
		if(opt[0]=='a') a[x]=y;
		else b[x]=y;
		int aft=a[x]^b[x];
		block::change(dfn[x],rg[pl[x]],bef^aft);
		if(val[rg[pl[x]]]) num--;
		val[rg[pl[x]]]^=bef^aft;
		if(val[rg[pl[x]]]) num++;
		block::change(dfn[x+1],rg[pl[x+1]],bef^aft);
		if(val[rg[pl[x+1]]]) num--;
		val[rg[pl[x+1]]]^=bef^aft;
		if(val[rg[pl[x+1]]]) num++;
		printf("%d\n",getans());
	}
	return 0;
}