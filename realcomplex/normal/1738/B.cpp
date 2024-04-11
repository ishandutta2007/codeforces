#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
ll s[N];
ll a[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = n - k + 1; i <= n; i ++ ){
        cin >> s[i];
    }
    for(int i = n - k + 2; i <= n; i ++ ){
        a[i] = s[i] - s[i - 1];
    }
    for(int i = n - k + 2; i < n; i ++ ){
        if(a[i] > a[i + 1]){
            cout << "No\n";
            return;
        }
    }
    if(k == 1){
        cout << "Yes\n";
        return;
    }
    else{
        ll lim = a[n - k + 2];
        ll sigma = s[n - k + 1];
        if(sigma <= lim * 1ll * (n - k + 1)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}