#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> sz;
int main()
{
    cin >> n >> k;
    for (int i=2; i*i<=n; i++) {
        while (k>1 && n%i==0) {
            sz.push_back(i);
            n/=i;
            k--;
        }
    }
    if (n>1 && k==1) {
        sz.push_back(n);
        for (auto x:sz) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}