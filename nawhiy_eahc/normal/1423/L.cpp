#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 11092019;
const long long hashmod = 100003;
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,Q,ans;
bitset <1002> in[35];
unordered_map <bitset <1002>,int> s;

void dfs(int x,const bitset <1002> &bit,int val) {
	if(x == m-m/3+1) {
		auto it = s.find(bit);
		if(it != s.end()) it->y = min(it->y,val);
		else s[bit] = val;
		return;
	}
	dfs(x+1,bit,val), dfs(x+1,bit^in[x],val+1);
}

void dfs2(int x,const bitset <1002> &bit,int val) {
	if(x == m+1) {
		auto it = s.find(bit);
		if(it != s.end()) ans = min(ans,it->y+val);
		return;
	}
	dfs2(x+1,bit,val), dfs2(x+1,bit^in[x],val+1);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> Q;
	for(int i = 1;i <= m;i++) {
		int cn; cin >> cn;
		while(cn--) {
			int x; cin >> x;
			in[i].flip(x);
		}
	}
	dfs(1,0,0);
	for(int i = 1;i <= Q;i++) {
		int cn; cin >> cn;
		bitset <1002> q;
		while(cn--) {
			int x; cin >> x;
			q.flip(x);
		}
		ans = INF;
		dfs2(m-m/3+1,q,0);
		cout << (ans == INF ? -1 : ans) << '\n';
	}
}