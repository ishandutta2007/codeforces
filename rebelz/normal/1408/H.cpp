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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[500005];
vector<int> vec[500005];
set<int> s[2];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		vector<int> v0(0);
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=0;i<=n;i++) vec[i].clear();
		for(int i=1;i<=n;i++) vec[a[i]].pb(i);
		if(!vec[0].size()){
			printf("0\n");
			continue;
		}
		int pl=vec[0][vec[0].size()/2];
		vector<pii> pr(0);
		for(int i=1;i<=n;i++){
			if(!vec[i].size()) continue;
			int lf=0,rg=n+1;
			for(auto r:vec[i]){
				if(r<=pl) chkmax(lf,r);
				else chkmin(rg,r);
			}
			pr.pb(mp(lf,rg));
		}
		s[0].clear(),s[1].clear();
		for(int i=1;i<=n;i++){
			if(a[i]) continue;
			if(i<=pl) s[0].insert(i);
			else s[1].insert(i);
		}
		sort(pr.begin(),pr.end(),[&](pii x,pii y){return x.se>y.se;});
		int ans=0;
		for(auto r:pr){
			auto it0=s[0].lower_bound(r.fi);
			if(it0!=s[0].begin()){
				it0--;
				ans++;
				s[0].erase(it0);
			}
			else{
				auto it1=s[1].lower_bound(r.se);
				if(it1!=s[1].end()){
					ans++;
					s[1].erase(it1);
				}
			}
		}
		printf("%d\n",min(ans,(int)vec[0].size()/2));
	}
	return 0;
}