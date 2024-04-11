#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, q, pos, t[c], lp[c];
bool v[c];
int lsb(int a) {
    return (a & (-a));
}
void add(int a, int b) {
    while (a<=n) {
        lp[a]+=b;
        a+=lsb(a);
    }
}
int ask(int a) {
    int sum=0;
    while (a) {
        sum+=lp[a];
        a-=lsb(a);
    }
    return sum;
}
int kerd(int ert) {
    if (!v[ert]) {
        cout.flush() << "? " << 1 << " " << ert << "\n";
        cin >> t[ert];
        t[ert]-=ask(ert);
        v[ert]=1;
    }
    return ert-t[ert]-ask(ert);
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
            if (kerd(mid)>=pos) {
                hi=mid;
            } else {
                lo=mid;
            }
        }
        cout.flush() << "! " << hi << "\n";
        add(hi, 1);
    }
    return 0;
}