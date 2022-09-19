#include <bits/stdc++.h>

using namespace std;
long long w, n, maxi, ks, ns;
vector<long long> kis, nagy;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, maxi=-1e18, kis.clear(), nagy.clear();
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (x<0) kis.push_back(x);
            else nagy.push_back(x);
        }
        ks=kis.size(), ns=nagy.size();
        sort(kis.rbegin(), kis.rend()), sort(nagy.begin(), nagy.end());
        for (int i=0; i<=5; i++) {
            int p=5-i;
            if (ks>=i && ns>=p) {
                long long pr=1;
                if (i%2==0) {
                    for (int j=ks-1; j>ks-1-i; j--) pr*=kis[j];
                    for (int j=ns-1; j>ns-1-p; j--) pr*=nagy[j];
                } else {
                    for (int j=0; j<i; j++) pr*=kis[j];
                    for (int j=0; j<p; j++) pr*=nagy[j];
                }
                maxi=max(maxi, pr);
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}
/*
1
6
-9 -7 -5 -3 -2 1
*/