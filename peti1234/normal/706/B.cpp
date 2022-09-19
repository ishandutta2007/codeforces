#include <bits/stdc++.h>

using namespace std;
int n, q;
vector<int> sz;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    sort(sz.begin(), sz.end());
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int lo=-1, hi=n, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            (x>=sz[mid] ? lo=mid : hi=mid);
        }
        cout << lo+1 << "\n";
    }
    return 0;
}