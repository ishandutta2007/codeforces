#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n;
vector<int> loc[ALP];
string s;

void solve(){
    cin >> n >> s;
    int ans=0;
    while (sz(s)){
        pair<int, int> rem{-1, -1};
        for (int i = 0; i < sz(s); i++){
            bool e=0;
            if (i&&s[i-1]==s[i]-1) e=1;
            if (i<sz(s)&&s[i+1]==s[i]-1) e=1;
            if (e) rem = max(rem, {s[i]-'a', i});
        }
        if (rem.second==-1) break;
        ans++; s.erase(rem.second, 1);
    }    
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}