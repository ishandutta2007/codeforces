#include <bits/stdc++.h>

using namespace std;

#define int long long

int A[300001];

void sub(){
    int n, s = 0, res1 = 0, ans = (1LL << 60); cin>> n;
    for(int i=0;i<n;i++) cin >> A[i], A[i] %= 2, s += A[i];
    if(s == n / 2){
        int j = 1; for(int i = 0; i < n; i++){
            if(A[i]) res1 += abs(i - j), j += 2;
        }
        
        ans = min(ans, res1);
        res1 = 0;
    }
    if(s == n/ 2 + n % 2){
        int j = 0; for(int i=0;i<n;i++){
            if(A[i]) res1 += abs(i - j), j += 2;
        }
        ans = min(ans, res1);
    }

    res1 = 0;
    cout << (ans == (1LL << 60) ? -1 : ans) << endl;
}
int32_t main() {
    int t; cin >>t;for(int j=0;j<t;j++) sub();
}