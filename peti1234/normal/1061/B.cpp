#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[100001];
long long sum=0;
int e;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    sort(t+1, t+n+1);
    reverse(t+1, t+n+1);

    e=t[1];
    for (int i=1; i<=n; i++) {
        e=min(t[i]-1, e-1);
        if (e==0) {
            cout << sum-t[1]-n+i;
            return 0;
        }
    }
    cout << sum-t[1];
    return 0;
}