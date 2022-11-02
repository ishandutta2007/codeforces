#include <bits/stdc++.h>
using namespace std;
long long n, k, A, B, m, sum;
vector<int> a;

int main(){
    cin >> n >> k >> m;
    sum = 0;
    double ans = 0.0;
    a.resize(n);

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for(int i = 1; i<=n; i++){
        sum += a[i - 1];
        if(n - i <= m){
            ans = max(ans, (sum + min(m - n + i, i*k) + 0.0)/i);
        }
    }

    cout << setprecision(10) << ans;

}