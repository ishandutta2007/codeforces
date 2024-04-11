#include <bits/stdc++.h>

using namespace std;
long long n, sum, a, b, t[200005];
vector<int> ans;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        b=max(b, t[i]);
        if (b>a) swap(a, b);
        sum+=t[i];
    }
    for (int i=1; i<=n; i++) {
        if (t[i]!=a && 2*a==sum-t[i] || t[i]!=b && 2*b==sum-t[i] || a==b && 2*a==sum-t[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x << " ";
    }
    return 0;
}