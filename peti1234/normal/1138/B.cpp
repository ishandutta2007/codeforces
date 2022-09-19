#include <bits/stdc++.h>

using namespace std;
int n;
string a, b;
vector<int> k[4];
int p, q, r, s;
int pp, ss;
int main()
{
    cin >> n >> a >> b;
    for (int i=0; i<n; i++) {
        if (a[i]=='1') {
            if (b[i]=='1') {
                k[3].push_back(i+1);
                s++;
            } else {
                k[2].push_back(i+1);
                r++;
            }
        } else {
            if (b[i]=='1') {
                k[1].push_back(i+1);
                q++;
            } else {
                k[0].push_back(i+1);
                p++;
            }
        }
    }
    for (int i=0; i<=n/2; i++) {
        for (int j=0; j<=n/2; j++) {
            ss=(q+s-(i+j))/2;
            if (2*ss+i+j!=q+s) {
                continue;
            }
            pp=n/2-i-j-ss;
            if (pp<=p && i<=q && j<=r && ss<=s && pp>=0 && ss>=0) {
                for (int i=0; i<pp; i++) {
                    cout << k[0][i] << " ";
                }
                for (int j=0; j<i; j++) {
                    cout << k[1][j] << " ";
                }
                for (int i=0; i<j; i++) {
                    cout << k[2][i] << " ";
                }
                for (int i=0; i<ss; i++) {
                    cout << k[3][i] << " ";
                }
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}