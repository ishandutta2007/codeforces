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
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}


struct BIT	// Point update,query
{
	vector<int> t;int n;BIT(){n=0;}
	BIT(int sz){ n=sz; t=vector<int>(sz+1,0);}
	void upd(int i, int val){ while(i<=n) t[i]+=val, i+=i&-i;}
	int qry(int i){int ans=0; while(i>0) ans+=t[i],i-=i&-i; return ans;}
	int qry(int i, int j) {if(i>j or j<=0)return 0;return qry(j) - qry(i-1);}
};



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;

	BIT btk(n+10), btnmk(n+10);

	int x = 1;
	ll ans = 1;
	FOR (it, 1, n) {
		int intr = 0;
		int to = x + k;
		if (to <= n) {
			intr += btk.qry(max(x+1,to-k+1),to-1);
			intr += btnmk.qry(max(x+1,to-(n-k)+1),to-1);
			intr += btk.qry(max(1,x+1-k),min(x-1,to-1-k));
			intr += btnmk.qry(max(1,x+1-(n-k)),min(x-1,to-1-(n-k)));
			btk.upd(x, 1);
		} else {
			to -= n;
			swap(x,to);
			intr += btk.qry(max(x+1,to-k+1),to-1);
			intr += btnmk.qry(max(x+1,to-(n-k)+1),to-1);
			intr += btk.qry(max(1,x+1-k),min(x-1,to-1-k));
			intr += btnmk.qry(max(1,x+1-(n-k)),min(x-1,to-1-(n-k)));
			btnmk.upd(x, 1);
			swap(x,to);
		}
		ans += intr + 1;
		cout << ans << " ";
		x = to;
	}

	return 0;
}