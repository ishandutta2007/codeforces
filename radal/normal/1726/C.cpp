#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 3e5+15,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}

int lst[N],nxt[N],par[N],pr[N],lm[N];

int getpar(int v){
	if (par[v] == v) return v;
	return par[v] = getpar(par[v]);
}

bool mg(int u,int v){
	if (getpar(u) == getpar(v)) return 0;
	par[par[u]] = par[v];
	return 1;
}

void solve(){
	int n;
	string s;
	cin >> n >> s;
	n *= 2;
	lst[0] = -1;
	rep(i,1,n+1){
		par[i] = i;
		pr[i] = pr[i-1];
		if (s[i-1] == '(') pr[i]++;
		else pr[i]--;
		lst[i] = -1;
		nxt[i] = -1;
	}
	stack<int> st;
	repr(i,n,1){
		while (!st.empty() && pr[st.top()] >= pr[i]) st.pop();
		if (st.empty()) lm[i] = n+1;
		else lm[i] = st.top();
		st.push(i);
	}
	int cmp = n;
	repr(i,n,1){
		if (s[i-1] ==  ')'){
			lst[pr[i]] = i;
			continue;
		}
		int j = lst[pr[i-1]];
		cmp -= mg(i,j);
		if (j < n && s[j] == '(') cmp -= mg(i,j+1);
		lst[pr[i]] = i;
	}
	cout << cmp << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--){
		solve();
	}
    return 0;
}