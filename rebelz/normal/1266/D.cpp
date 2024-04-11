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

int n,m;
ll a[100005];
vector<pll> s;
vector<pair<pll,ll> > ans;

int main(){
	n=readint(); m=readint();
	ll x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		a[y]-=z,a[x]+=z;
	}
	for(int i=1;i<=n;i++) if(a[i]<0) s.push_back(mp(-a[i],i));
	int now=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			while(a[i]){
				if(a[i]>=s[now].fi){
					a[i]-=s[now].fi,ans.push_back(mp(mp(i,s[now].se),s[now].fi));
					now++;
				}
				else{
					ans.push_back(mp(mp(i,s[now].se),a[i]));
					s[now].fi-=a[i];
					a[i]=0;
				}
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%lld %lld %lld\n",x.fi.fi,x.fi.se,x.se);
	return 0;
}