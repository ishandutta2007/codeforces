#include <bits/stdc++.h>

using namespace std;
long long w, n, kezd, veg, l, k, r, x, p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k >> l, kezd=k, veg=3*k-1, r=0;
        while(n--) {
            cin >> x, x=l-x, p=2*k-x;
            if (x<0) r++;
            else if (x>=k) kezd=k, veg=3*k-1;
            else {
                if (kezd<p && p<=veg+1) kezd=p, veg=p+2*x;
                else if (veg<p) r++;
                else kezd++, veg=p+2*x;
            }
            if (kezd>veg) r++;
        }
        if (!r) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}