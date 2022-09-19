#include <bits/stdc++.h>

using namespace std;
int n, k, ert, cnt;
int main()
{
    cin >> k >> n;
    for (int i=1; i<=n; i++) {
        if (__gcd(n, i)>1) continue;
        int a=n, b=i, l=0, db=0;
        while (b>0) {
            l+=a/b;
            db++;
            a%=b;
            swap(a, b);
        }
        if (l==k && db>cnt) {
            ert=i;
            cnt=db;
        }
    }
    if (n>1) cnt++;
    if (!ert) {
        cout << "IMPOSSIBLE\n";
    } else {
        string ans;
        int a=n, b=ert, kezd=cnt%2;
        while (b>0) {
            ans+=(kezd%2 ? "T" : "B");
            a-=b;
            if (a<=b) {
                swap(a, b);
                kezd=1-kezd;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << k-cnt << "\n" << ans << "\n";
    }
    return 0;
}