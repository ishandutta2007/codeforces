#include <bits/stdc++.h>

using namespace std;
int w, n, k, m, el, dif, regi, uj;
bool pr;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w;
    while(w--) {
        cin >> n >> k >> m, k/=2, el=0, pr=0, regi=0, uj=n-m;
        for (int i=1; i<=m; i++) {
            int x; cin >> x;
            dif=x-el-1, el=x;
            uj-=dif;
            if (regi<k && uj<k) {
                pr=1;
            }
            regi+=dif;
        }
        if (regi<k) {
            pr=1;
        }
        if ((n-m)%(2*k)) {
            pr=1;
        }
        cout << (pr? "NO" : "YES") << endl;
    }
    return 0;
}