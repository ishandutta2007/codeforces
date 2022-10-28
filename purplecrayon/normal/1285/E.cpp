#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int tt=0;
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    map<int, vector<pair<int, int>>> ev;
    map<int, vector<int>> st;
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        ev[v[i].first].push_back({0, i}); st[v[i].first].push_back(i);
        ev[v[i].second].push_back({1, i});
    }
    // if (tt == 185){
    //     cout  << n << '\n';
    //     for (auto it : v) cout  << it.first << ' ' << it.second << '\n';
    //     exit(0);
    // }
    for (auto& it : ev) sort(it.second.begin(), it.second.end());
    vector<int> costs(n, 0);
    int cur=0;
    set<int> s;
    for (auto& x : ev){
        int ssz=sz(s), stsz = sz(st[x.first])-1, totsz = ssz+stsz;
        // cerr << x.first << ' ' << totsz << '\n';
        for (auto it : x.second){ //all i's that start at x.first
            if (it.first == 0){ //start of an interval
                if (totsz == 0 || ssz == 0 && x.second[0].second == it.second){
                    costs[it.second]--; //removing this is bad -> already contributes
                    cur++;
                } else if (totsz == 1 || (ssz == 1 && x.second[0].second == it.second) || (ssz == 0 && stsz > 1 && x.second[1].second == it.second)){
                    if (ssz == 0 && stsz > 1 && x.second[1].second == it.second){
                        costs[x.second[0].second]++;
                    } else if (stsz == 1 && totsz == 1){ //smth else starts here
                        int other = (st[x.first][0]==it.second);
                        costs[st[x.first][other]]++;
                    } else if (ssz == 1) { // it is from some prev interval
                        costs[*s.begin()]++;
                    }
                }
                //insert interval
            }      
        }
        for (auto it : x.second) 
            if (it.first == 0) s.insert(it.second);
            else s.erase(it.second);
    } 
    int ans=0;
    for (auto it : costs) ans = max(ans, cur+it);//, cout << it << ' ';
    // cout << '\n';
    // if (tt <= 3) cout << ans << '\n';
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; 
    while (t--) tt++, solve();
}