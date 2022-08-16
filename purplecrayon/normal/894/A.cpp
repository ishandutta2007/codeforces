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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int ans=0;
    for (int i = 0; i < sz(s); i++) for (int j = i+1; j < sz(s); j++) for (int k = j+1; k < sz(s); k++) {
        if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') ans++;
    }
    cout << ans << '\n';
}