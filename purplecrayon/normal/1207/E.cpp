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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
int qry(vector<int> a){
    cout << "? ";
    for (auto it : a) cout << it << ' ';
    cout << endl;

    int c; cin >> c;
    return c;
}
void solve(){
    vector<int> a, b;
    for (int i = 1; sz(a) < 100; i++) a.push_back(i<<7);
    for (int i = 0; sz(b) < 100; i++) b.push_back(i);
    int x=qry(a), y=qry(b);
    int ans=0;
    ans = x&((1<<7)-1);
    for (int i = 7; i < 14; i++) ans |= ((y>>i)&1)<<i;
    cout << "! " << ans << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}