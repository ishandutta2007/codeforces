#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, s, t[c];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n >> s;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        int maxi=-1, sum=0, pos=1;
        for (int i=1; i<=n; i++) {
            sum+=t[i];
            while (sum>s) {
                sum-=t[pos];
                pos++;
            }
            if (sum==s) {
                maxi=max(maxi, i-pos+1);
            }
        }
        if (maxi==-1) {
            cout << -1 << "\n";
        } else {
            cout << n-maxi << "\n";
        }
    }
    return 0;
}
/*
1
16 2
1 1 0 0 1 0 0 1 1 0 0 0 0 0 1 1
*/