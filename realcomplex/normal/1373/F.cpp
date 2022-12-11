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
    vector<int> A(n), B(n);
    ll sa = 0, sb = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> A[i];
        sa += A[i];
    }
    for(int i = 0 ; i < n; i ++ ){
        cin >> B[i];
        sb += B[i];
    }
    if(sa > sb){
        cout << "NO\n";
        return;
    }
    for(int i = 0 ; i < n; i ++ ){
        A.push_back(A[i]);
        B.push_back(B[i]);
    }
    int m = 2 * n;
    ll high = B[m - 1]-A[m - 1];
    ll cur;
    for(int i = m - 2; i >= 0 ;i -- ){
        if(high + B[i] < 0){
            cout << "NO\n";
            return;
        }
        cur = B[i]-A[i];
        high = min(high + cur, cur);
    }
    cout << "YES\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ )
        solve();
    return 0;
}