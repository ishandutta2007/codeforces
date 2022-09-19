#include <bits/stdc++.h>

using namespace std;
int n, m, k;
int t[100001];
vector<int> v;
long long sum;
int main()
{
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (i>1) {
            v.push_back(t[i]-t[i-1]);
        }
    }
    sort(v.begin(), v.end());
    for (int i=1; i<=n-k; i++) {
        sum+=v[i-1]-1;
    }
    sum+=n;
    cout << sum << endl;
    return 0;
}