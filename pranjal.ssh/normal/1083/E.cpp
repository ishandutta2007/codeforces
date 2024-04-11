#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int N = 1e6 + 10;
pair<ii, ll> a[N];
ll dp[N];

const static int LX = -(1e9), RX = 1e9;
struct Dynamic_Hull { /* Max hull */
  struct Line{
    ll m, c; // slope, intercept
    Line(ll mm=0, ll cc=-1e18) { m = mm; c = cc; }
    ll operator[](const int&x){ return m*x+c; }  };
  struct node {
    node *lt,*rt; Line ln;
    node(const Line &l){lt=rt=nullptr; ln=l;}
  };
  node *root=nullptr;
  void add(Line l,node*&it,int lx=LX,int rx=RX){
    if(it==nullptr)it=new node(l);
    if(it->ln[lx]>=l[lx] and it->ln[rx]>=l[rx]) return;
    if(it->ln[lx]<=l[lx] and it->ln[rx]<=l[rx]) {it->ln=l; return;}
    int mid = (lx+rx)>>1;
    if(it->ln[lx] < l[lx]) swap(it->ln,l);
    if(it->ln[mid] >= l[mid]) add(l,it->rt,mid+1,rx);
    else { swap(it->ln,l); add(l,it->lt,lx,mid); }
  }
  void add(const ll &m,const ll &c) { add(Line(m,c),root); }
  ll get(int &x,node*&it,int lx=LX,int rx=RX){
    if(it==NULL) return -1e18; // Max hull
    ll ret = it->ln[x];
    int mid = (lx+rx)>>1;
    if(x<=mid) ret = max(ret , get(x,it->lt,lx,mid));
    else ret = max(ret , get(x,it->rt,mid+1,rx));
    return ret;
  }
  ll get(int x){ return get(x,root); }
};


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    FOR (i, 1, n) {
        cin >> a[i].F.F >> a[i].F.S >> a[i].S;
    }
    sort(a+1, a+n+1);
    dp[0] = 0;
    Dynamic_Hull H;
    H.add(0, 0);
    FOR (i, 1, n) {
        dp[i] = H.get(a[i].F.S) + a[i].F.F*1LL*a[i].F.S - a[i].S;
        H.add(-a[i].F.F, dp[i]);
    }
    cout << *max_element(dp, dp+n+1) << "\n";
    
    return 0;
}