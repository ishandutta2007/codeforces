#include <bits/stdc++.h>

using namespace std;
long long n, m, s, f, k, sum, ans;
vector<long long> a, b;
void solve(int i)
{
    int x=-1, y=m;
    while(y-x>1) {
        int c=(x+y)/2;
        if (b[c]>=a[i]) {
            y=c;
        } else {
            x=c;
        }
    }
    y+=k-i;
    if (y>=m) {
        sum=10000000000;
    } else {
        sum=max(sum, b[y]+f);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s >> f >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        x+=s;
        a.push_back(x);
    }
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    if (k>=n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=0; i<k+1; i++) {
        solve(i);
    }
    if (sum==10000000000) {
        sum=-1;
    }
    cout << sum << endl;
    return 0;
}