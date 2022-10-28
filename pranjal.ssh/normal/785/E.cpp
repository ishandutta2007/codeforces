#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef int __T;typedef tree<__T, null_type, less<__T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

struct BIT1	// Point update,query
{
	vector<int> t;int n;BIT1(){n=0;}
	BIT1(int sz){ n=sz; t=vector<int>(sz+1,0);}
	void upd(int i, int val){ while(i<=n) t[i]+=val, i+=i&-i;}
	int qry(int i){int ans=0; while(i>0) ans+=t[i],i-=i&-i; return ans;}
};
struct node {
	vi elms;
	BIT1 bt;
};

const int N = 2e5 + 10;
node T[4*N];
ii QRY[N];

void build(int no, int l, int r) {
	sort(all(T[no].elms));
	T[no].bt = BIT1(sz(T[no].elms) + 5);
	FOR (i, l, r) 
		T[no].bt.upd(lower_bound(all(T[no].elms),i)-T[no].elms.begin()+1,1);
	if (l == r) 
		return;
	int mid = ((l + r) >> 1);
	build(2*no, l, mid);
	build(2*no + 1, mid + 1, r);
}
int ql, qr, x;
int n, q;
int qry(int no, int l, int r) {
	if (r < ql or l > qr) return 0;
	if (l >= ql and r <= qr) {
		return T[no].bt.qry(lower_bound(all(T[no].elms),x)-T[no].elms.begin());
	}
	int mid = ((l + r) >> 1);
	return qry(no<<1, l, mid) + qry((no<<1)|1,mid+1,r);
}
int qry() {
	if (ql > qr) return 0;
	return qry(1, 1, n);
}
int val, pos;
void rem(int no, int l, int r) {
	T[no].bt.upd(lower_bound(all(T[no].elms),val)-T[no].elms.begin()+1,-1);
	if (l == r) return;
	int mid = ((l + r) >> 1);
	if (pos <= mid) rem(no<<1, l, mid);
	else rem((no<<1)|1,mid+1,r);
}
void ins(int no, int l, int r) {
	T[no].bt.upd(lower_bound(all(T[no].elms),val)-T[no].elms.begin()+1,1);
	if (l == r) return;
	int mid = ((l + r) >> 1);
	if (pos <= mid) ins(no<<1, l, mid);
	else ins((no<<1)|1,mid+1,r);
}
void mark(int no, int l, int r) {
	T[no].elms.push_back(val);
	if (l == r) return;
	int mid = ((l + r) >> 1);
	if (pos <= mid) mark(no<<1, l, mid);
	else mark((no<<1)|1,mid+1,r);
}
int a[N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	
	ll ans = 0;
	FOR (i, 1, n) a[i] = i;
	FOR (i, 1, n)pos=i,val=i,mark(1,1,n);
	FOR (i, 0, q - 1) {
		cin >> QRY[i].F >> QRY[i].S;
		pos=QRY[i].F,val=a[QRY[i].S],mark(1,1,n);
		pos=QRY[i].S,val=a[QRY[i].F],mark(1,1,n);
		swap(a[QRY[i].F], a[QRY[i].S]);
	}
	FOR (i, 1, n) a[i] = i;
	build(1,1,n);
	FOR (i, 0, q - 1) {
		int l, r;
		l = QRY[i].F, r = QRY[i].S;
		if (l == r) {
			cout << ans << "\n";
			continue;
		}
		if (l > r) swap(l, r);
		int t;
		ql = 1, qr = r - 1, x = a[r], t = qry(), ans -= r - 1 - t;
		ql = r + 1, qr = n, x = a[r],  ans -= x - 1 - t;
		val = a[r], pos = r, rem(1,1,n);

		ql = 1, qr = l - 1, x = a[l], t = qry(), ans -= l - 1 - t;
		ql = l + 1, qr = n, x = a[l], ans -= x - 1 - t - (a[r] < a[l]);
		val = a[l], pos = l, rem(1,1,n);

		ql = 1, qr = r - 1,x = a[l],t = qry(), ans += r - 1 - t - 1;
		ql = r + 1, qr = n,x = a[l], ans += x - 1 - t - (a[r] < a[l]);
		val = a[l], pos = r, ins(1,1,n);

		ql = 1, qr = l - 1,x = a[r], t = qry(), ans += l - 1 - t;
		ql = l + 1, qr = n,x = a[r], ans += x - 1 - t;
		val = a[r], pos = l, ins(1,1,n);

		swap(a[l], a[r]);
		cout << ans << "\n";
	}


	return 0;
}