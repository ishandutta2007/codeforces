#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        a[i]--;
    }
    while(!a.empty() && a.back() == a.size() - 1){
        a.pop_back();
    }
    int rr;
    ld prob;
    ld soln = 1;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> rr >> prob;
        if(a.empty()) continue;
        if(rr >= a.size())
            soln *= (1.0 - prob);
    }
    if(a.empty())
        soln = 1.0;
    else
        soln = 1.0 - soln;
    cout << fixed << setprecision(10) << soln << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
}