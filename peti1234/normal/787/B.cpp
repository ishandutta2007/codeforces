#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> poz;
vector<int> neg;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int k;
        cin >> k;
        int c=0;
        for (int i=1; i<=k; i++) {
            int x;
            cin >> x;
            if (x>0) {
                poz.push_back(x);
            }
            else {
                neg.push_back(x*-1);
            }
        }
        sort(poz.begin(), poz.end());
        sort(neg.begin(), neg.end());
        int a=0, b=0;
        while (a<poz.size() && b<neg.size()) {
            if (poz[a]==neg[b]) {
                c=1;
            }
            if (poz[a]<neg[b]) {
                a++;
            } else {
                b++;
            }
        }
        if (c==0) {
            cout << "YES" << endl;
            return 0;
        }
        poz.clear();
        neg.clear();
    }
    cout << "NO" << endl;
    return 0;
}