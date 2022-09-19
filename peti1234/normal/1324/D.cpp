#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, x, a[c], dif[c];
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        cin >> dif[i];
        dif[i]-=a[i];
    }
    sort(dif+1, dif+n+1);
    x=n;
    for (int i=1; i<=n; i++) {
        while(x && dif[i]+dif[x]>=0) x--;
        sum+=x;
        if (x>=i) sum--;
    }
    cout << sum/2 << "\n";
    return 0;
}