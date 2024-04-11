#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll N,M,n,m,g,ans;
ll a[100005],b[100005];
vector<pair<ll,pll> > va[200005],vb[200005];

ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}

void exgcd(int x,int y,int &a,int &b){
	if(y==0) return (void)(a=1,b=0);
	exgcd(y,x%y,b,a);
	b-=a*(x/y);
}

int main(){
	N=readint(); M=readint();
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	m=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	g=gcd(N,M);
	N/=g,M/=g;
	int invn=0,invm=0;
	exgcd(N,M,invn,invm);
	while(invn<0) invn+=M;
	while(invm<0) invm+=N;
	if(g>n+m) return printf("-1\n"),0;
	for(int i=1;i<=n;i++) va[a[i]%g].push_back(mp(a[i]/g,mp(0,a[i])));
	for(int i=1;i<=m;i++) vb[b[i]%g].push_back(mp(b[i]/g,mp(0,b[i])));
	for(int i=0;i<g;i++){
		if(!va[i].size()&&!vb[i].size()) return printf("-1\n"),0;
		int vas=va[i].size(),vbs=vb[i].size();
		for(int j=0;j<vas;j++) vb[i].push_back(mp(va[i][j].fi%M,mp(1,va[i][j].se.se)));
		for(int j=0;j<vbs;j++) va[i].push_back(mp(vb[i][j].fi%N,mp(1,vb[i][j].se.se)));
		for(int j=0;j<va[i].size();j++) va[i][j].fi=1ll*va[i][j].fi*invm%N;
		for(int j=0;j<vb[i].size();j++) vb[i][j].fi=1ll*vb[i][j].fi*invn%M;
		sort(va[i].begin(),va[i].end());
		sort(vb[i].begin(),vb[i].end());
		if(va[i][0].se.fi==1) chkmax(ans,va[i][0].se.se);
		if(vb[i][0].se.fi==1) chkmax(ans,vb[i][0].se.se);
		for(int j=1;j<va[i].size();j++) if(va[i][j].fi!=va[i][j-1].fi&&va[i][j].se.fi==1) chkmax(ans,va[i][j].se.se);
		for(int j=1;j<vb[i].size();j++) if(vb[i][j].fi!=vb[i][j-1].fi&&vb[i][j].se.fi==1) chkmax(ans,vb[i][j].se.se);
		for(int j=1;j<va[i].size();j++) chkmin(va[i][j].se.se,va[i][j-1].se.se+(va[i][j].fi-va[i][j-1].fi)*(M*g));
		for(int j=1;j<vb[i].size();j++) chkmin(vb[i][j].se.se,vb[i][j-1].se.se+(vb[i][j].fi-vb[i][j-1].fi)*(N*g));
		if(va[i][va[i].size()-1].fi!=N-1||va[i][0].fi!=0) chkmax(ans,1ll*(va[i][0].fi+N-1-va[i][va[i].size()-1].fi)*(M*g)+va[i][va[i].size()-1].se.se);
		for(int j=1;j<va[i].size();j++) if(va[i][j].fi>va[i][j-1].fi+1) chkmax(ans,1ll*(va[i][j].fi-1-va[i][j-1].fi)*(M*g)+va[i][j-1].se.se);
		if(vb[i][vb[i].size()-1].fi!=M-1||vb[i][0].fi!=0) chkmax(ans,1ll*(vb[i][0].fi+M-1-vb[i][vb[i].size()-1].fi)*(N*g)+vb[i][vb[i].size()-1].se.se);
		for(int j=1;j<vb[i].size();j++) if(vb[i][j].fi>vb[i][j-1].fi+1) chkmax(ans,1ll*(vb[i][j].fi-1-vb[i][j-1].fi)*(N*g)+vb[i][j-1].se.se);
	}
	printf("%lld\n",ans);
	return 0;
}