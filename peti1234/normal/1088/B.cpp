#include <bits/stdc++.h>

using namespace std;
int n, k;
int t[100001];
vector<int> v;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    v.push_back({0});

    for (int i=1; i<=n; i++) {
        if (t[i]!=v.back()) {
            v.push_back(t[i]);
        }
    }
    int q=v.size()-1;
    for (int i=0; i<min(k, q); i++) {
        cout << v[i+1]-v[i] << endl;
    }
    for (int i=v.size()-1; i<k; i++) {
        cout << 0 << endl;
    }
    return 0;
}