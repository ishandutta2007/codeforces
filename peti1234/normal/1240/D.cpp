#include <bits/stdc++.h>

using namespace std;
unsigned long long s1=34213123433, s2=867853426765, ert;
map<unsigned long long, int> m;
vector<long long> sz;
long long ans, w, n, x, x2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        m[0]++;
        for (int i=1; i<=n; i++) {
            cin >> x;
            x2=x;
            long long si=sz.size();
            bool spec=(si==0 || sz.back()!=x);

            x=s1+x*x+(si+spec)*(si+spec)*(si+spec);
            unsigned long long  add=s1*x+s2*x*x*x;
            if (spec) {
                ert+=add;
                sz.push_back(x2);
            } else {
                ert-=add;
                sz.pop_back();
            }
            ans+=m[ert]++;
        }
        cout << ans << "\n";
        ans=0, ert=0;
        m.clear(), sz.clear();
    }
    return 0;
}