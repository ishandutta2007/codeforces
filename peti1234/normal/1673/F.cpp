#include <bits/stdc++.h>

using namespace std;
const int c=32;
int ert[c][c], sor=1, oszlop=1, po=1, xo, n, k;
int main()
{
    for (int s=1; s<=5; s++) {
        for (int i=0; i<sor; i++) {
            for (int j=0; j<oszlop; j++) {
                ert[2*sor-1-i][j]=ert[i][j]+po;
            }
        }
        sor*=2;
        po*=2;
        for (int i=0; i<sor; i++) {
            for (int j=0; j<oszlop; j++) {
                ert[i][2*oszlop-1-j]=ert[i][j]+po;
            }
        }
        oszlop*=2;
        po*=2;
    }
    /*for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cout << ert[i][j] << " ";
        }
        cout << "\n";
    }*/
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        for (int j=1; j<n; j++) {
            cout << (ert[i][j]^ert[i][j-1]) << " ";
        }
        cout.flush() << "\n";
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << (ert[i][j]^ert[i-1][j]) << " ";
        }
        cout.flush() << "\n";
    }
    while (k--) {
        int x;
        cin >> x;
        xo=xo^x;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (ert[i][j]==xo) {
                    cout.flush() << i+1 << " " << j+1 << endl;
                }
            }
        }
    }
    return 0;
}