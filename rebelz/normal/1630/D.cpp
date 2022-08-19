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

int n,m;
int a[1000005];
vector<int> vec[1000005][2];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		int g=0;
		for(int i=1;i<=m;i++) g=__gcd(g,readint());
		for(int i=0;i<g;i++) vec[i][0].clear(),vec[i][1].clear();
		for(int i=1;i<=n;i++){
			if(a[i]<0) vec[i%g][0].pb(a[i]);
			else vec[i%g][1].pb(a[i]);
		}
		for(int i=0;i<g;i++){
			sort(vec[i][0].begin(),vec[i][0].end());
			reverse(vec[i][0].begin(),vec[i][0].end());
			sort(vec[i][1].begin(),vec[i][1].end());
		}
		ll ans1=0;
		for(int i=0;i<g;i++){
			if(vec[i][0].size()%2==0){
				for(auto r:vec[i][0]) ans1+=-r;
				for(auto r:vec[i][1]) ans1+=r;
			}
			else{
				for(auto r:vec[i][0]) ans1+=-r;
				for(auto r:vec[i][1]) ans1+=r;
				if(vec[i][1].size()) ans1-=2*min(-vec[i][0][0],vec[i][1][0]);
				else ans1-=2*(-vec[i][0][0]);
			}
		}
		ll ans2=0;
		for(int i=0;i<g;i++){
			if(vec[i][0].size()%2==1){
				for(auto r:vec[i][0]) ans2+=-r;
				for(auto r:vec[i][1]) ans2+=r;
			}
			else{
				for(auto r:vec[i][0]) ans2+=-r;
				for(auto r:vec[i][1]) ans2+=r;
				if(vec[i][1].size()&&vec[i][0].size()) ans2-=2*min(-vec[i][0][0],vec[i][1][0]);
				else if(vec[i][0].size()) ans2-=2*(-vec[i][0][0]);
				else ans2-=2*vec[i][1][0];
			}
		}
		printf("%lld\n",max(ans1,ans2));
	}
	return 0;
}