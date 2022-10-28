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

map<int, int> mp;
int qry(int i){
    i++; if (mp.count(i)) return mp[i];
    cout << "? " << i << endl;
    int x; cin >> x;
    return x;
}
void pr(int i){
    i++;
    cout << "! " << i << endl;
    exit(0);
}
void solve(){
    int n; cin >> n;

    mp[0]=mp[n+1]=1e9;

    int lo=0, hi=n-1;
    while (lo < hi){
        int mid=(lo+hi)/2;

        int v1=qry(mid-1), v2=qry(mid), v3=qry(mid+1);
        if (v1 > v2 && v2 < v3) pr(mid);

        if (v2 < v3) hi=mid;
        else lo=mid+1;
    }
    assert(lo==hi);
    pr(lo);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}