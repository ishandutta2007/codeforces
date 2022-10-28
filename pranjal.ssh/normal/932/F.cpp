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

typedef long long LL;
const LL is_query=-(1LL<<62);
struct Line{
  LL m,b;//compare two lines by increasing slope
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs)const{
    if(rhs.b!=is_query)return m>rhs.m;//> for min
    const Line* s=succ();
    if(!s)return 0;
    return b-s->b>(s->m-m)*rhs.m;//> for min
  }};
struct HullDynamic:public multiset<Line>{
  bool bad(iterator y){//maintains upper hull for max
    auto z=next(y);
    if(y==begin()){
      if(z==end())return 0;
      return y->m == z->m && y->b >= z->b;//>= for min
    }auto x=prev(y);
    if(z==end())
      return y->m==x->m && y->b>=x->b; // >= for min
    return (x->b-y->b)*1.0L*(z->m-y->m)>=(y->b-z->b)*1.0L*(y->m-x->m);
  }
  void insert_line(LL m,LL b){
    auto y=insert({ m,b});
    y->succ=[=]{return next(y)==end()?0:&*next(y);};
    if(bad(y)){erase(y);return;}
    while(next(y)!=end() && bad(next(y)))erase(next(y));
    while(y!=begin() && bad(prev(y)))erase(prev(y));
  }
  LL eval(LL x){
    auto l=*lower_bound((Line){x,is_query});
    return l.m*x +l.b;
  }
};

const int N = 1e5+10;
HullDynamic T[4*N+10];
int num[4*N+10];
int a[N], b[N];
vi g[N];
ll ans[N];
int st[N], en[N];
int ctr;
void dfs(int i) {
	st[i] = ++ctr;
	for (int j : g[i]) {
		g[j].erase(find(all(g[j]), i));
		dfs(j);
	}
	en[i] = ctr;
}


int n;
#define mid ((l+r)>>1)
#define L (no<<1)
#define R ((no<<1)|1)




void upd(int no, int l, int r, int i) {
	T[no].insert_line(b[i], ans[i]);
	num[no]++;
	if (l == r) {
		return;
	}
	if (st[i] <= mid) upd(L, l, mid, i);
	else upd(R, mid+1, r, i);
}
ll qry(int no, int l, int r, int i) {
	if (num[no] == 0 or r < st[i] or l > en[i]) return 1e18;
	if (l >= st[i] and r <= en[i]) {
		return T[no].eval(a[i]);
	}
	return min(qry(L, l, mid, i) ,qry(R, mid+1, r, i));
}
void f(int i) {

	for (int j : g[i]) {
		
		f(j);
	}
	if (g[i].empty()) {
		ans[i] = 0;
		upd(1, 1, n, i);
		return;	
	}
	ll val = qry(1, 1, n, i);
	// ll val = 0;

	ans[i] = val;
	upd(1, 1, n, i);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);


	cin >> n;
	FOR (i, 1, n) cin >> a[i];
	FOR (i, 1, n) cin >> b[i];
	FOR (i, 1, n-1) {
		int x, y; cin >> x >> y;
		g[x].push_back(y), g[y].push_back(x);
	}


	dfs(1);

	f(1);
	FOR (i, 1, n) cout << ans[i] << " ";


	return 0;
}