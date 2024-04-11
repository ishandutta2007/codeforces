#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int o1 = s * v1 + 2 * t1;
    int o2 = s * v2 + 2 * t2;
    if (o1 < o2) cout << "First";
    if (o1 == o2) cout << "Friendship";
    if (o1 > o2) cout << "Second";
}