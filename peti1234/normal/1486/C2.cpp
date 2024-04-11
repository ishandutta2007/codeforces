#include <bits/stdc++.h>

using namespace std;
int pos, n, l, r, mid;
int ask(int a, int b) {
    cout.flush() << "? " << a << " " << b << "\n";
    int x; cin >> x;
    return x;
}
int main()
{
    cin >> n;
    pos=ask(1, n);
    l=1, r=n;
    if (l==pos) {
        l++;
    }
    if (r==pos) {
        r--;
    }
    while (r-l>0) {

        mid=(l+r)/2;
        if (pos<=mid) {
           int uj=ask(min(pos, l), max(pos, mid));
            if (uj==pos) {
                r=mid;
            } else {
                l=mid+1;
            }
        } else {
            int uj=ask(min(pos, mid+1), max(pos, r));
            if (uj==pos) {
                l=mid+1;
            } else {
                r=mid;
            }
        }
        if (l==pos) {
            l++;
        }
        if (r==pos) {
            r--;
        }
    }
    cout << "! " << l << "\n";
    return 0;
}