#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, k, t[c], h[c], ans;
map<pair<int, int>, int> m;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        int f=t[i], len=0, mar=f%k;
        while (f) {
            f/=10;
            len++;
        }
        h[i]=len;
        m[{len, mar}]++;
    }
    for (int i=1; i<=n; i++) {
        long long mar=t[i]%k;
        m[{h[i], t[i]%k}]--;
        for (int i=1; i<=10; i++) {
            mar=10*mar%k;
            long long s=(k-mar)%k;
            if (m.find({i, s})!=m.end()) {
                ans+=m[{i, (k-mar)%k}];
            }
        }
        m[{h[i], t[i]%k}]++;
    }
    cout << ans << "\n";
    return 0;
}
/*
2 2
1 1
*/