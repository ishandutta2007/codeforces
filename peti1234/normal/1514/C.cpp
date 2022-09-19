#include <bits/stdc++.h>

using namespace std;
long long n, pr=1;
vector<int> ans;
int main()
{
    cin >> n;
    for (long long i=1; i<n; i++) {
        if (__gcd(i, n)==1) {
            ans.push_back(i);
            pr*=i, pr%=n;
        }
    }
    if (pr!=1) {
        ans.pop_back();
    }
    cout << ans.size() << "\n";
    for (int x:ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}