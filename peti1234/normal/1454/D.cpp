#include <bits/stdc++.h>

using namespace std;
long long w, n, m, st, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, m=n, st=m, db=1;
        for (long long i=2; i*i<=m; i++) {
            int ert=0;
            while(m%i==0) {
                m/=i, ert++;
            }
            if (ert>db) st=i, db=ert;
        }
        cout << db << "\n";
        for (int i=1; i<db; i++) {
            cout << st << " ";
            n/=st;
        }
        cout << n << "\n";
    }
    return 0;
}