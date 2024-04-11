#include <bits/stdc++.h>

using namespace std;
vector<int> sz;
int w, n;
int main()
{
    for (int i=1; i<=9; i++) {
        int ert=0;
        for (int j=1; j<=9; j++) {
            ert+=i;
            sz.push_back(ert);
            if (j<9) {
                ert*=10;
            }
        }
    }
    cin >> w;
    while (w--) {
        cin >> n;
        int db=0;
        for (int x:sz) {
            if (x<=n) {
                db++;
            }
        }
        cout << db << "\n";
    }
    return 0;
}