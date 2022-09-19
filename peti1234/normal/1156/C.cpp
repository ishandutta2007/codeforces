#include <bits/stdc++.h>

using namespace std;
int n, z;
int x, y;
int t[200001];
int sum;
int main()
{
    cin >> n >> z;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    int a=n/2+1;
    x=1, y=a;
    sort(t+1, t+n+1);
    while(x<a && y<=n) {
        if (t[y]-t[x]>=z) {
            sum++;
            x++;
        }
        y++;
    }
    cout << sum << endl;
    return 0;
}