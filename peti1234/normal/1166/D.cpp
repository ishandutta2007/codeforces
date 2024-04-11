#include <bits/stdc++.h>

using namespace std;
long long w, x, y, ut, n, a, b, maxi;
vector<long long> kis, sol;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> n, x=a, y=a, ut=0, kis.clear(), sol.clear();
        if (a==b) sol.push_back(a);
        else while(x<=b) {
            if (y>=b) {
                ut=b;
                int le=0;
                while(kis.size()>0) {
                    sol.push_back(ut), kis.pop_back();
                    if (ut%2) {
                        if (le%2) ut++;
                        le++;
                    }
                    ut/=2;
                }
                sol.push_back(a);
                break;
            }
            kis.push_back(x);
            if (kis.size()==1) x++, y+=n;
            else x*=2, y*=2;
        }
        int si=sol.size();
        if (si) {
            cout << si << " ";
            for (int i=si-1; i>=0; i--) cout << sol[i] << " ";
            cout << "\n";
        } else cout << -1 << "\n";
    }
    return 0;
}