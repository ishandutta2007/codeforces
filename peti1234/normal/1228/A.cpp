#include <bits/stdc++.h>

using namespace std;
bool jo(int a)
{
    vector<int> v;
    while(a>0) {
        v.push_back(a%10);
        a/=10;
    }
    sort(v.begin(), v.end());
    for (int i=1; i<v.size(); i++) {
        if (v[i]==v[i-1]) {
            return false;
        }
    }
    return true;
}
int main()
{
    int l, r;
    cin >> l >> r;
    for (int i=l; i<=r; i++) {
        if (jo(i)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}