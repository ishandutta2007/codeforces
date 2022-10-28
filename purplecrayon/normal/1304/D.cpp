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
const int MAXN = 2e5+10, MAXM = 50+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MAXP = 2e5+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int p[MAXN];
void solve(){
    int n; string s; cin >> n >> s;
    iota(p, p+n, 1); reverse(p, p+n);
    for (int i=0; i<n-1; ){
        int j=i;
        while (s[j] == '<') j++;
        reverse(p+i, p+j+1);
        i = j+1;
    }
    for (int i = 0; i < n; i++) cout << p[i] << ' ';
    cout << '\n';
    iota(p, p+n, 1);
    for (int i = 0; i < n-1; ){
        int j=i;
        while (s[j] == '>') j++;
        reverse(p+i, p+j+1);
        i = j+1;
    }
    for (int i = 0; i < n; i++) cout << p[i] << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t;
    while (t--) solve();
}