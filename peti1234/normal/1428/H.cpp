#include <bits/stdc++.h>

using namespace std;
const int c=102;
int n, m, pos[c], el, ert=2005, keszdb, mod;
bool kesz[c];
void valt(int a, int b) {
    cout.flush() << "? " << a << " " << b << "\n";
    pos[a]+=b;
    int x;
    cin >> x;
    el=ert, ert=x;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<n; i++) {
        bool nagy=0;
        while (!nagy) {
            valt(0, 1);
            if (ert>el) {
                nagy=1;
            }
        }
        while (nagy) {
            valt(0, 1);
            if (ert<=el) {
                nagy=0;
            }
        }
        valt(0, -1);
        vector<int> bal, jobb;
        for (int i=1; i<n; i++) {
            if (!kesz[i]) {
                bal.push_back(i);
            }
        }
        int spec=-1;
        while (bal.size()>1) {
            while (bal.size()>jobb.size()) {
                jobb.push_back(bal.back());
                bal.pop_back();
            }
            for (auto x:jobb) {
                valt(x, spec);
            }
            valt(0, -1);
            if ((ert>=el) == (spec==-1)) {
                bal=jobb;
            }
            jobb.clear();
            spec=(ert>=el ? 1 : -1);
            valt(0, 1);
        }
        int uj=bal[0];
        kesz[uj]=1, pos[uj]=pos[0]-(spec==1);
        for (int i=0; i<m; i++) {
            valt(uj, -1);
        }
        if (spec==-1) {
            valt(uj, -1);
        }
        valt(0, -1), valt(0, -1);
    }
    cout << "! ";
    for (int i=1;i<n; i++) {
        cout << (pos[i]-pos[0]+10*n*m)%(n*m) << " ";
    }
    cout << "\n";
    return 0;
}