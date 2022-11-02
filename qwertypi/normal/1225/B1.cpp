#include <bits/stdc++.h>
 
using namespace std;
 
int A[101];
void solve(){
    int n, k, d;
    cin >> n >> k >> d;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int ans = n;
    for(int i = 0; i <= n - d; i++){
        set<int> S;
        for(int j = i; j < i + d; j++){
            S.insert(A[j]);
        }
        ans = min(ans, (int) S.size());
    }
    cout << ans << endl;
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}