#include <bits/stdc++.h>

using namespace std;
int n;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> sum(n+1, 0), ans(n, 0);
    cin >> a >> b;
    for (int i=0; i<n; i++) {
        sum[i]+=(a[n-i-1]-'a'+b[n-i-1]-'a');
        if (sum[i]>=26) {
            sum[i]-=26, sum[i+1]++;
        }
    }
    for (int i=0; i<n; i++) {
        ans[i]=(sum[i]/2);
        if (sum[i+1]%2) ans[i]+=13;
    }
    for (int i=n-1; i>=0; i--) {
        cout << (char)('a'+ans[i]);
    }
    cout << "\n";
    return 0;
}