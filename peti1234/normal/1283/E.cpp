#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, t[c], kis[c], kdb, nagy[c], ndb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        t[i]++;
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        if (abs(t[i]-kis[i-1])<=1) {
            kis[i]=kis[i-1];
        } else {
            kis[i]=t[i]+1;
            kdb++;
        }
        if (t[i]>nagy[i-1]+1) {
            nagy[i]=t[i]-1;
            ndb++;
        } else {
            if (t[i]==nagy[i-1]+1) {
                nagy[i]=t[i];
                ndb++;
            } else {
                if (t[i]==nagy[i-1]) {
                    nagy[i]=t[i]+1;
                    ndb++;
                } else {
                    nagy[i]=t[i]+1;
                }
            }
        }
    }
    cout << kdb << " " << ndb << "\n";
    return 0;
}