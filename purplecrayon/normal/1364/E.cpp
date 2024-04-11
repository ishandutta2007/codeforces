#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}

const int MAX_Q = 4296;
int cnt_q=0;
int n;

int qry(int i, int j){
    while (cnt_q == MAX_Q);
    cnt_q++;
    cout << "? " << (i+1) << ' ' << (j+1) << endl;
    int v; cin >> v; while (v == -1);
    return v;
}
void pr(vector<int> v){
    cout << "! ";
    for (auto& it : v) cout << it << ' ';
    cout << endl;
    exit(0);
}
void brute(){
    int r=-1;
    for (int i = 0; i < n; i++){
        vector<int> v; v.reserve(n-1);
        for (int j = 0; j < n; j++) if (j != i) v.push_back(qry(i, j));
        sort(v.begin(), v.end()); bool bad=0;
        for (int j = 0; j < n-1; j++) if (v[j] != j+1) bad=1;
        if (!bad){
            r=i;
            break;
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) if (i != r) ans[i] = qry(i, r);
    pr(ans);
}
void good(){
    set<int> cand;
    vector<int> pos;
    for (int i = 0; i < n; i++) cand.insert(i);
    {
        int c=rnd(0, n-1);
        cand.erase(c);
        pos.push_back(c);
    }
    while (sz(cand) > 1){
        shuffle(pos.begin(), pos.end(), rng);
        int c=pos.back(); pos.pop_back();

        vector<int> v(cand.begin(), cand.end()), r(sz(v));
        int mn=1e9;
        for (int i = 0; i < sz(v); i++) r[i] = qry(c, v[i]), mn=min(mn, r[i]);
        for (int i = 0; i < sz(v); i++) if (r[i] != mn) cand.erase(v[i]), pos.push_back(v[i]);
    }
    
    int r=*cand.begin();

    vector<int> ans(n);
    for (int i = 0; i < n; i++) if (i != r) ans[i] = qry(i, r);
    pr(ans);
}
void solve(){
    cin >> n;
    if (n*(n-1) + n-1 <= MAX_Q) brute();
    else good();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}