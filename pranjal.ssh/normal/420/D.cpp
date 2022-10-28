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

const int N = 1e6 + 10;
int cnt[8*N+10];
int VAL[8*N + 10];
int done[N];
int ans[N];
int n, m;

void build(int no, int l, int r) {
	if (l == r) {
		if (l > m) {
			cnt[no] = 1;
			VAL[no] = -(l - m);
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	cnt[no] = cnt[2*no]+cnt[2*no+1];
}

int get(int no, int l, int r, int pos) {

	if (l == r) {
		assert(pos == 1);
		cnt[no] = 0;
		int ans = VAL[no];
		VAL[no] = 0;
		return ans;
	}
	int mid = (l + r) >> 1;
	int ans = -1;
	if (pos <= cnt[2*no]) ans = get(2*no, l, mid, pos);
	else ans = get(2*no+1, mid+1, r, pos - cnt[2*no]);
	cnt[no] = cnt[2*no] + cnt[2*no+1];
	return ans;
}

void put(int no, int l, int r, int pos, int val) {
	if (l == r) {
		VAL[no] = val;
		cnt[no] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) put(2*no, l, mid, pos, val);
	else put(2*no+1, mid+1, r, pos, val);
	cnt[no] = cnt[2*no] + cnt[2*no+1];
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;


	build(1, 1, n + m);

	int can = 1;
	FOR (_, 0, m - 1) {
		int x, y; cin >> x >> y;
		int val = get(1, 1, n + m, y);
		
		if (val < 0 and done[x]) {
			can = 0;
			break;
		}
		if (val > 0 and val != x) {
			can = 0;
			break;
		}
		if (val < 0) {
			ans[-val] = x;
			done[x] = 1;
		}
		put(1, 1, n + m, m - _, x);
	}
	if (not can) {
		cout << "-1\n";
	} else {
		vi lft;
		FOR (i, 1, n) if (!done[i]) lft.push_back(i);
		reverse(all(lft));
		FOR (i, 1, n) {
			if (ans[i] == 0) ans[i] = lft.back(), lft.pop_back();
			cout << ans[i] << " ";
		}
	}

	return 0;
}