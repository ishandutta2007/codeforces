#include <bits/stdc++.h>

using namespace std;

int A[100001];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n / 2; i++){
        cout << A[i * 2 + 1] << ' ' << -A[i * 2] << ' ';
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}