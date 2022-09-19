#include <bits/stdc++.h>

using namespace std;
int n;
vector<long long> sz;
long long sum;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long a, b;
        cin >> a >> b;
        sum+=(n-1)*a;
        sz.push_back(b-a);
    }
    sort(sz.begin(), sz.end());
    reverse(sz.begin(), sz.end());
    for (int i=0; i<sz.size(); i++) {
        sum+=sz[i]*i;
    }
    cout << sum << endl;
    return 0;
}