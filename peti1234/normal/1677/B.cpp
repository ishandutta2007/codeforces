#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int w, n, m, sor[c], oszlop[c], ut, van[c];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> m;
        ut=-m;
        for (int i=0; i<n*m; i++) {
            char c;
            cin >> c;
            if (i) oszlop[i]=oszlop[i-1];
            if (i>=m) sor[i]=sor[i-m];
            if (c=='1') {
                if (!van[i%m]) {
                    van[i%m]=1;
                    oszlop[i]++;
                }
                ut=i;
            }
            if (i-ut<m) sor[i]++;
        }
        for (int i=0; i<n*m; i++) {
            cout << sor[i]+oszlop[i] << " ";
        }
        cout << "\n";
        for (int i=0; i<n*m; i++) {
            sor[i]=0, oszlop[i]=0, van[i]=0;
        }
    }
    return 0;
}
/*
1
4 2
11001101
*/