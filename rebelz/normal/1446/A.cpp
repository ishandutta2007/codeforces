#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,w;
pll a[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); w=readint();
		for(int i=1;i<=n;i++) a[i]=mp(readint(),i);
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		ll now=0,fl=0;
		vector<int> ans(0);
		for(int i=1;i<=n;i++){
			if(now+a[i].fi<=w) ans.pb(a[i].se),now+=a[i].fi;
			if(now*2>=w){
				fl=1;
				sort(ans.begin(),ans.end());
				printf("%d\n",ans.size());
				for(auto r:ans) printf("%d ",r);
				printf("\n");
				break;
			}
		}
		if(!fl) printf("-1\n");
	}
	return 0;
}