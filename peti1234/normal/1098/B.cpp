#include <bits/stdc++.h>

using namespace std;
vector<int> v[300001];
int se[300001][5];
int so[300001][5];
int oe[300001][5];
int oo[300001][5];
int maxi=0;
int n, m;
int f;
int ker(int a, int b, int c, int d, int e)
{
    int sum=0;
    if (e<=6) {
        for (int i=0; i<n; i++) {
            int x=0, y=0;
            if (i%2==0) {
                x=se[i][a]+so[i][b];
                y=se[i][b]+so[i][a];
            } else {
                x=se[i][c]+so[i][d];
                y=se[i][d]+so[i][c];
            }
            sum+=max(x, y);
            if (f==e) {
                for (int j=0; j<m; j++) {
                    if (i%2==0) {
                        if ((j%2==0) == (x>y)) {
                            v[i][j]=a;
                        } else {
                            v[i][j]=b;
                        }
                    } else {
                        if ((j%2==0) == (x>y)) {
                            v[i][j]=c;
                        } else {
                            v[i][j]=d;
                        }
                    }
                }
            }
            x=0, y=0;
        }
    } else {
        for (int i=0; i<m; i++) {
            int x=0, y=0;
            if (i%2==0) {
                x=oe[i][a]+oo[i][b];
                y=oe[i][b]+oo[i][a];
            } else {
                x=oe[i][c]+oo[i][d];
                y=oe[i][d]+oo[i][c];
            }
            sum+=max(x, y);
            if (f==e) {
                for (int j=0; j<n; j++) {
                    if (i%2==0) {
                        if ((j%2==0) == (x>y)) {
                            v[j][i]=a;
                        } else {
                            v[j][i]=b;
                        }
                    } else {
                        if ((j%2==0) == (x>y)) {
                            v[j][i]=c;
                        } else {
                            v[j][i]=d;
                        }
                    }
                }
            }
            x=0, y=0;
        }
    }
    if (sum>maxi) {
        f=e;
    }
    maxi=max(maxi, sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<s.size(); j++) {
            if (s[j]=='A') {
                v[i].push_back(1);
            }
            if (s[j]=='T') {
                v[i].push_back(2);
            }
            if (s[j]=='C') {
                v[i].push_back(3);
            }
            if (s[j]=='G') {
                v[i].push_back(4);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x=v[i][j];
            if (j%2==0) {
                se[i][x]++;
            } else {
                so[i][x]++;
            }
            if (i%2==0) {
                oe[j][x]++;
            } else {
                oo[j][x]++;
            }
        }
    }
    ker(1, 2, 3, 4, 1);
    ker(1, 3, 2, 4, 2);
    ker(1, 4, 2, 3, 3);
    ker(2, 3, 1, 4, 4);
    ker(2, 4, 1, 3, 5);
    ker(3, 4, 1, 2, 6);
    ker(1, 2, 3, 4, 7);
    ker(1, 3, 2, 4, 8);
    ker(1, 4, 2, 3, 9);
    ker(2, 3, 1, 4, 10);
    ker(2, 4, 1, 3, 11);
    ker(3, 4, 1, 2, 12);
    ker(1, 2, 3, 4, 1);
    ker(1, 3, 2, 4, 2);
    ker(1, 4, 2, 3, 3);
    ker(2, 3, 1, 4, 4);
    ker(2, 4, 1, 3, 5);
    ker(3, 4, 1, 2, 6);
    ker(1, 2, 3, 4, 7);
    ker(1, 3, 2, 4, 8);
    ker(1, 4, 2, 3, 9);
    ker(2, 3, 1, 4, 10);
    ker(2, 4, 1, 3, 11);
    ker(3, 4, 1, 2, 12);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x=v[i][j];
            if (x==1) {
                cout << 'A';
            }
            if (x==2) {
                cout << 'T';
            }
            if (x==3) {
                cout << 'C';
            }
            if (x==4) {
                cout << 'G';
            }
        }
        cout << endl;
    }
    //cout << maxi << " " << f << endl;
    return 0;
}