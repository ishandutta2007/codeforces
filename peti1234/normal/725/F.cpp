#include <bits/stdc++.h>

using namespace std;
long long n, ans;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long e=a+b, f=c+d;
        if (e>=f) {
            ans-=b+d;
            sz.push_back(e), sz.push_back(f);
        } else {
            if (a+c>b+d && a>d) {
                ans+=a-d;
            }
            if (a+c<b+d && b>c) {
                ans-=b-c;
            }
        }
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<sz.size(); i+=2) {
        ans+=sz[i];
    }
    cout << ans << "\n";
    return 0;
}