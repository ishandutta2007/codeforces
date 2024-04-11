#include <bits/stdc++.h>

using namespace std;
int n;
long long t[500001];
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    if (n==1) {
        cout << t[1] << endl;
        return 0;
    }
    sort(t+1, t+n+1);
    sum-=t[1];
    sum+=t[n];
    for (int i=2; i<n; i++) {
        sum+=abs(t[i]);
    }
    cout << sum << endl;
    return 0;
}