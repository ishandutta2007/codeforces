#include <bits/stdc++.h>

using namespace std;
int n, t[105], dif[105], ans=2e9;
int main()
{
    cin >> n;
    n*=2;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<n; i++) {
        dif[i]=t[i+1]-t[i];
    }
    for (int i=1; i<=n; i+=2) {
        for (int j=i+1; j<=n; j+=2) {
            int sum=0;
            for (int a=1; a<i; a+=2) {
                sum+=dif[a];
            }
            for (int a=i+1; a<j; a+=2) {
                sum+=dif[a];
            }
            for (int a=j+1; a<n; a+=2) {
                sum+=dif[a];
            }
            ans=min(ans, sum);
        }
    }
    cout << ans << "\n";
    return 0;
}