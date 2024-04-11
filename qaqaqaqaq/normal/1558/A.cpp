#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=1000007;
const int mod=998244353;

int a,b;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _;
	cin>>_;
	while (_--){
		cin>>a>>b;
		int s=a+b;
		set<int> ok;
		ok.clear();
		auto solve=[&](int u,int of){
			rep(i,u+1) ok.insert(2*i+of);
		};
		if (s&1){
			int l=s/2, r=s/2+1;
			int of=l-min(a,b);
			solve(min(a,b),of);
			solve(min(a,b),of+1);
		}
		else{
			int of=s/2-min(a,b);
			solve(min(a,b),of);
		}
		cout<<sz(ok)<<"\n";
		for (auto c:ok) cout<<c<<" ";
		cout<<"\n";
	}
	return 0;
}