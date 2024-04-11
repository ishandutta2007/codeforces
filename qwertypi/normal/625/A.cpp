#include <bits/stdc++.h>
 
using namespace std;
 
int32_t main(){
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    long long ans = 0;
    if(b - c < a){
        long long t = max(0LL, (n - c) / (b - c));
        n -= (b - c) * t;
        ans += t;
    }
    ans += n / a;
    cout << ans << endl;
}