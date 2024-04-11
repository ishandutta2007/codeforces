#include <bits/stdc++.h>

using namespace std;
long long solve2(int ert, int l) {
    int ans=0, o=0;
    for (int i=0; l>0; i++) {
        if (l & (1<<i)) {
            l-=(1<<i);
            if ((l & ert)==0) {
                ans+=(1<<o);
            }
        }
        if ((ert & (1<<i))==0) {
            o++;
        }
    }
    return ans;
}
long long solve(int l, int r) {
    if (r==l+1) {
        return (l==0 ? 1 : 0);
    }
    if (l%2) {
        l--;
        return 2*(solve2(l, l+1)-solve2(l, r))-(l==0 ? 1 : 0)+solve(l, r);
    }
    if (r%2) {
        return 2*(solve2(r, l)-solve2(r, r))+solve(l, r+1);
    }
    return 3*solve(l/2, r/2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r+1) << "\n";
    }
    return 0;
}