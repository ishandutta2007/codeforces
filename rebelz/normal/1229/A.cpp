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

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
pll a[7005];
vector<ll> v;
bool vis[7005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint();
	for(int i=1;i<=n;i++) a[i].se=readint();
	sort(a+1,a+n+1);
	a[0].fi=a[n+1].fi=-1;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].fi==a[i-1].fi){
			ans+=a[i].se,vis[i]=true;
			if(a[i-1].fi!=a[i-2].fi) ans+=a[i-1].se,vis[i-1]=true;
			if(a[i].fi!=a[i+1].fi) v.push_back(a[i].fi);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			for(auto x:v){
				if((a[i].fi&x)==a[i].fi){
					ans+=a[i].se;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}