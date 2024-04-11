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
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void input(vector<ar<int, 26>>& v, int amt){
    while (amt--){
        string s; cin >> s;
        ar<int, 26> cur={};
        for (auto c : s) cur[c-'a']++;
        v.push_back(cur);
    }
}
void solve(){
    int n; cin >> n;
    if (n == 1){
        cout << "? 1 1\n"; cout.flush();
        string s; cin >> s;
        cout << "! " << s << '\n'; cout.flush(); return;
    }
    cout << "? 1 " << n << "\n"; cout.flush();
    vector<ar<int, 26>> v1; input(v1, n*(n+1)/2);
    cout << "? 1 " << n-1 << "\n"; cout.flush();
    vector<ar<int, 26>> v2; input(v2, n*(n-1)/2);
    multiset<ar<int, 26>> tot; for (auto it : v1) tot.insert(it);
    for (auto it : v2) tot.erase(tot.find(it));
    vector<ar<int, 26>> suff(tot.begin(), tot.end());
    sort(suff.begin(), suff.end(), [&](ar<int, 26> a, ar<int, 26> b){
        int s1=0, s2=0; 
        for (auto it : a) s1 += it;
        for (auto it : b) s2 += it;
        return s1 < s2;
        
    });
    // for (int i = 0; i < sz(suff); i++) {
    //     for (auto it : suff[i]) cout << it << ' ';
    //     cout << '\n';
    // }
    vector<int> ans; ans.reserve(n);
    for (int i = n-1; i >= 0; i--){
        if (i){
            for (int j = 0; j < 26; j++) suff[i][j] -= suff[i-1][j];
        }
        int lst=-1;
        for (int j = 0; j < 26; j++) if (suff[i][j]) lst=j;
        ans.push_back(lst);
    }
    cout << "! "; for (auto it : ans) cout << char('a'+it);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t; 
    while (t--) solve();
}