#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> a[4];
    rep(i, n){
        int x;
        cin >> x;
        a[x].pb(i + 1);
    }
    int t = min(a[1].size(), min(a[2].size(), a[3].size()));
    cout << t << endl;
    for(int i = 0; i < t; i++)
        cout << a[1][i] << ' ' << a[2][i] << ' ' << a[3][i] << endl;
    return 0;
}