// NOT MY CODE: https://codeforces.com/blog/entry/105160
 
#include <bits/stdc++.h>
using namespace std;
 
#define N 100000
 
long long int cost(vector<long long int> &a, int i) { return max(0LL, max(a[i-1]-a[i], a[i+1]-a[i])+1); }
 
void solve() {
    int n;
    cin >> n;
    vector<long long int> a(n);
    int i;
    for(i=0; i<n; i++) cin >> a[i];
    long long int rj=0;
    if(n&1) {
        for(i=1; i<n; i+=2) rj+=cost(a, i);
        cout << rj << '\n';
        return;
    }
    long long int t=0;
    for(i=1; i<n-1; i+=2) t+=cost(a, i);
    rj=t;
    for(i=n-2; i>0; i-=2) {
        t-=cost(a, i-1);
        t+=cost(a, i);
        rj=min(rj, t);
    }
    cout << rj << '\n';
}
 
int main() {
    cin.sync_with_stdio(false); cin.tie(0);
    unsigned int t; 
    cin >> t; 
    for(; t--;) solve();
    return 0;
}