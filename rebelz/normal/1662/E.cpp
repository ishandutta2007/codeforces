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

int n;
int a[200005],p[200005],val[200005];

void add(int x,int c){
	for(;x<=n;x+=(x&(-x))) val[x]+=c;
}

int ask(int x){
	int ret=0;
	for(;x;x-=(x&(-x))) ret+=val[x];
	return ret;
}

int find(int x){
	int now=0;
	for(int i=17;i>=0;i--){
		if(now+(1<<i)>n) continue;
		if(x>val[now+(1<<i)]) now+=1<<i,x-=val[now];
	}
	return now+1;
}

void solve(){
	n=readint();
	for(int i=1;i<=n;i++) val[i]=0;
	for(int i=1;i<=n;i++) a[i]=readint(),p[a[i]]=i;
	add(p[n],1);
	int pl=p[n];
	ll ans=0;
	for(int i=n-1;i>=1;i--){
		int num=0;
		if(pl<p[i]) num=ask(p[i])-ask(pl-1);
		else num=ask(n)-ask(pl-1)+ask(p[i]);
		ans+=1ll*(n-i-num)*i;
		add(p[i],1);
		if(num==n-i) pl=p[i];
		else{
			if(pl<p[i]) pl=find(ask(pl-1)+num+1);
			else{
				int tmp=ask(n)-ask(pl-1);
				if(tmp>=num+1) pl=find(ask(pl-1)+num+1);
				else pl=find(num+1-tmp);
			}
		}
	}
	printf("%lld\n",ans);
}

int main(){
	int T=readint();
	while(T--) solve();
	return 0;
}