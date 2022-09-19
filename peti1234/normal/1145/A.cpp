#include <bits/stdc++.h>

using namespace std;
int n;
int t[17];
int solve(int a, int b)
{
    bool x=true;
    for (int i=a+1; i<=b; i++) {
        if (t[i-1]>t[i]) {
            x=false;
        }
    }
    if (x) {
        return b-a+1;
    }
    else return max(solve(a, (a+b)/2), solve((a+b)/2+1, b));
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    cout << solve(1, n);
    return 0;
}