#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

int k,pa,pb;
int dp[1011][1011];
int ab,ob, oa;
int expo(int n, int m){
	int ans=1;
	while(m){
		if(m&1)ans=(ans*1LL*n)%inf;
		n=(n*1LL*n)%inf;
		m>>=1;
	}
	return ans;
}



int f(int a, int kk) {
	if (kk >= k) return 0;
	if (a >= k) {
		int ans = (a+pa-a*1LL*pa)%inf;
		ans = (ans+inf)%inf;
		ans = (ans*1LL*oa)%inf;
		ans = (ans*1LL*oa)%inf;
		ans = (ans*1LL*pb)%inf;
		return ans;
	}
	int &ans = dp[a][kk];
	if (~ans) return ans;

	
	ans = (pa*1LL*f(a+1,kk)+pb*1LL*(a+f(a,kk+a)))%inf;
	
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin>>k>>pa>>pb;
	memset(dp, -1,sizeof dp);

	ab=expo(pa+pb,inf-2);
	pa=(pa*1LL*ab)%inf;
	pb=(pb*1LL*ab)%inf;
	oa=expo((1-pa+inf)%inf, inf-2);

	cout << f(1,0) << "\n";

	return 0;
}