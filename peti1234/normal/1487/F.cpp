#include <bits/stdc++.h>

using namespace std;
const int c=252, g=52, f=25, sok=1e5;
int regi[c][c][g], uj[c][c][g], n, t[52], most;
string s;
int mod(int sum) {
    if (sum<0) {
        sum+=sok;
    }
    return sum%10;
}
int per(int ert) {
    return (ert+sok)/10-1e4;
}
void calc(int a, int b, int c) {
    c+=per(a-b);
    uj[a][b][c+f]=min(uj[a][b][c+f], most);
}
int main()
{
    cin >> s;
    reverse(s.begin(), s.end());
    n=s.size();
    for (int i=0; i<n; i++) {
        t[i]=s[i]-'0';
    }
    n++;
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            for (int k=0; k<g; k++) {
                regi[i][j][k]=uj[i][j][k]=sok;
                int dif=mod(i-j);
                if (dif==t[0] && per(i-j)+f==k) {
                    regi[i][j][k]=0;
                }
            }
        }
    }
    for (int p=1; p<n; p++) {
        for (int i=0; i<c; i++) {
            for (int j=0; j<c; j++) {
                for (int k=-f; k<=f; k++) {
                    most=regi[i][j][k+f];
                    if (most==sok) {
                        continue;
                    }
                    most+=i+j;
                    int kul=mod(i-j-t[p]+mod(k)), tovabb=-per(t[p]-k);
                    if (i>=kul) {
                        calc(i-kul, j, tovabb);
                    }
                    if (j>=10-kul) {
                        calc(i, j-10+kul, tovabb);
                    }
                }
            }
        }
        for (int i=0; i<c; i++) {
            for (int j=0; j<c; j++) {
                for (int k=0; k<g; k++) {
                    regi[i][j][k]=uj[i][j][k];
                    uj[i][j][k]=sok;
                }
            }
        }
    }
    int mini=sok;
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            for (int k=-f; k<=f; k++) {
                int most=regi[i][j][k+f];
                if (per(i-j)+k==0) {
                    mini=min(mini, most+i+j);
                }
            }
        }
    }
    cout << mini << "\n";
    return 0;
}