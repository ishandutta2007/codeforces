#include <bits/stdc++.h>

using namespace std;
bool v[5202][5202];
int n;
bool x[5201];
bool y[5201];
bool ker(int a)
{
    for (int i=1; i<=n; i++) {
        if (i%a!=0) {
            if (x[i] || y[i]) {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int p=1; p<=n; p++) {
        int k=5;
        string s;
        cin >> s;
        for (int i=0; i<s.size(); i++) {
            char c=s[i];
            int x;
            if (c=='A') {
                x=10;
            } else if (c=='B') {
                x=11;
            } else if (c=='C') {
                x=12;
            } else if (c=='D') {
                x=13;
            } else if (c=='E') {
                x=14;
            }else if (c=='F') {
                x=15;
            } else {
                x=c-'0';
            }
            for (int j=1; j<=4; j++) {
                v[p][k-j]=(x%2!=0);
                x/=2;
            }
            k+=4;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (v[i][j]!=v[i+1][j]) {
                x[i]=true;
            }
            if (v[i][j]!=v[i][j+1]) {
                y[j]=true;
            }
        }
    }
    for (int i=n; i>=1; i--) {
        if (n%i==0) {
            bool c=ker(i);
            if (c) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}