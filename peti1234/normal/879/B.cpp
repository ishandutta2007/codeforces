#include <bits/stdc++.h>

using namespace std;
long long n, k;
int t[501];
int ak=1;
int h;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=2; i<=n; i++) {
        if (h>=k) {
            cout << t[ak] << endl;
            return 0;
        }
        if (t[ak]>t[i]) {
            h++;
        } else {
            ak=i;
            h=1;
        }
    }
    cout << n << endl;
    return 0;
}