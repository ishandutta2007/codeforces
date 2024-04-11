#include <bits/stdc++.h>
 
using namespace std;
 
int A[100001], B[100001], C[100001], s[100001];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }
    for(int i = 0; i < n; i++){
        cin >> C[i];
    }
    s[0] = A[0];
    for(int i = 1; i < n - 1; i++){
        if(A[i] != s[i - 1]) s[i] = A[i];
        if(B[i] != s[i - 1]) s[i] = B[i];
        if(C[i] != s[i - 1]) s[i] = C[i];
    }
    if(s[n - 2] != A[n - 1] && s[0] != A[n - 1]) s[n - 1] = A[n - 1];
    if(s[n - 2] != B[n - 1] && s[0] != B[n - 1]) s[n - 1] = B[n - 1];
    if(s[n - 2] != C[n - 1] && s[0] != C[n - 1]) s[n - 1] = C[n - 1];
    for(int i = 0; i < n; i++){
        cout << s[i] << ' ';
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