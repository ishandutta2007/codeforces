#include <bits/stdc++.h>

using namespace std;
int w;
long long a, b;
vector<int> x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        bool baj=0;
        if (a>b) {
            baj=1;
        }
        x.clear(), y.clear();
        int ert=1;
        while (a>0 || b>0) {
            if (a%2) {
                x.push_back(ert);
            }
            if (b%2) {
                y.push_back(ert);
            }
            ert++;
            a/=2, b/=2;
        }
        int sy=y.size(), sx=x.size();
        if (sy>sx) {
            baj=1;
        } else {
            for (int i=0; i<sy; i++) {
                if (x[i]>y[i]) {
                    baj=1;
                }
            }
        }
        cout << (baj? "NO" : "YES") << "\n";
    }
    return 0;
}
/*
1
1023
5955
*/