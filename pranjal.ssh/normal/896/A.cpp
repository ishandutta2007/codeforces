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

const int N = 1e5;
string a = "What are you doing at the end of the world? Are you busy? Will you save us?";
string b = "What are you doing while sending \"0\"? Are you busy? Will you send \"1\"?";
ll len[N+1];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	len[0] = a.length();

	FOR (i, 1, N) {
		len[i] = b.length() - 2LL + 2 * len[i - 1];
		len[i] = max(len[i], len[i-1]);
	}
	int p0 = b.find('0'), p1 = b.find('1');
	int q; cin >> q; while (q--) {
		int n; ll k; cin >> n >> k;
		while (1) {
			if (n == 0) {
				if (k > sz(a)) cout << ".";
				else cout << a[k - 1];
				break;
			}
			if (k <= p0) {
				cout << b[k - 1];
				break;
			}
			k -= p0;
			if (k <= len[n-1]) {
				--n;
				continue;
			}
			k -= len[n-1];
			if (k <= p1-p0-1) {
				cout << b[p0+k];
				break;
			}
			k -= p1-p0-1;
			if (k <= len[n-1]) {
				--n;
				continue;
			}
			k -= len[n-1];
			if (k <= sz(b)-1-p1) {
				cout << b[p1+k];
				break;
			}
			cout << ".";
			break;
		}
	}

	return 0;
}