#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, q, pos, t[c];
void kerd(int ert) {
    cout.flush() << "? " << 1 << " " << ert << "\n";
    cin >> t[ert];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    while (q--) {
        cin >> pos;
        int lo=0, hi=n, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            kerd(mid);
            if (mid-t[mid]>=pos) {
                hi=mid;
            } else {
                lo=mid;
            }
        }
        cout.flush() << "! " << hi << "\n";
    }
    return 0;
}