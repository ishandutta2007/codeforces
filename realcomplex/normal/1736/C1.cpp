#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);



void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        a[i] = i - a[i] + 1;
        a[i] = max(a[i], 0);
        if(i > 0) a[i] = max(a[i], a[i - 1]);
    }
    ll res = 0;
    for(int i = 0 ; i < n; i ++ ){
        res += (i - a[i] + 1);
    }
    cout << res << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}