#include <bits/stdc++.h>

using namespace std;
int n;
int k;
vector<int> v;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(y);
    }
    cin >> k;
    for (int i=0; i<v.size(); i++) {
        if (k>v[i]) {
            n--;
        }
    }
    cout << n << "\n";
    return 0;
}