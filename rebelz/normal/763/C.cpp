#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cys;
int a[100005];
bool vs[200005];
map<int,int> b,vis;

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	cys=readint(); n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	if(n==1) return printf("%d %d\n",a[1],0),0;
	bool fl=0;
	if(n*2>cys){
		fl=1;
		int cnt=0;
		for(int i=1;i<=n;i++) vs[a[i]]=1;
		for(int i=0;i<cys;i++) if(!vs[i]) a[++cnt]=i;
		n=cnt;
		if(n==0) return printf("1 1\n"),0;
		else if(n==1) return printf("%d 1\n",(a[1]+1)%cys),0;
	}
	int tmp=(a[2]-a[1]+cys)%cys; ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=b[(a[i]-tmp+cys)%cys]+b[(a[i]+tmp)%cys];
		b[a[i]]++;
	}
	if(ans>n) return printf("-1\n"),0;
	ans=n-ans;
	ll d=qpow(ans,cys-2)*tmp%cys;
	for(int i=1;i<=n;i++) vis[a[i]]=1;
	int now=a[1],cnt=-1;
	while(vis.count(now)&&vis[now]){
		cnt++;
		vis[now]=0;
		now=(now+d)%cys;
	}
	now=a[1],vis[a[1]]=1;
	while(vis.count(now)&&vis[now]){
		cnt++;
		vis[now]=0;
		now=(now+cys-d)%cys;
	}
	if(cnt==n){
		if(fl) printf("%lld %lld\n",(now+(n+1)*d)%cys,d);
		else printf("%lld %lld\n",(now+d)%cys,d);
	}
	else printf("-1\n");
	return 0;
}