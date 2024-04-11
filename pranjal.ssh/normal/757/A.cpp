#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll;typedef pair <int, int> ii;typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ ";for (auto& it : p) os << it << " ";return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ ";for (auto& it : p) os << it << " ";return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ ";for (auto& it : p) os << it << " ";return os << "]";}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a) cerr << ", ";cerr << *i;}cerr << "]\n";}

int main() 
{
   ios::sync_with_stdio(0); cin.tie(0);

   string s; cin >> s;
   vi f(500);
   for (char ch:s) f[ch]++;
   int ans = min({f['B'], f['u']/2, f['l'], f['b'], f['a']/2, f['s'], f['r']});
	cout << ans;

   return 0;
}