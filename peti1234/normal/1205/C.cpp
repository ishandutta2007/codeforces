#include <bits/stdc++.h>

using namespace std;
const int c=502;
int n;
bool v[c][c];
bool ask(int a, int b, int c, int d) {
    bool f=(c<a);
    if (f) {
        swap(a, c), swap(b, d);
    }
    cout.flush() << "? " << a << " " << b << " " << c << " " << d << "\n";
    bool ans;
    cin >> ans;
    return ans;
}
void add(int a, int b, int c, int d) {
    bool ans=ask(a, b, c, d);
    v[c][d]=1^ans^v[a][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    v[1][1]=1;
    add(1, 2, 3, 2),
    add(3, 2, 2, 1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i+j>=4) {
                if (i==1) {
                    add(i, j-2, i, j);
                } else if (j==1) {
                    add(i-2, j, i, j);
                } else {
                    add(i-1, j-1, i, j);
                }
            }
        }
    }
    for (int i=1; i<=n-2; i++) {
        if (v[i][i]!=v[i+2][i+2]) {
            int kezdi=i, kezdj=i, vegi=i+2, vegj=i+1;
            if (v[i][i]^v[i+1][i]^v[i+1][i+1]^v[i+2][i+1]) {
                kezdi++, vegj++;
            }
            bool ans=ask(kezdi, kezdj, vegi, vegj);
            if (1^ans^v[kezdi][kezdj]^v[vegi][vegj]) {
                for (int i=1; i<=n; i++) {
                    for (int j=1; j<=n; j++) {
                        if ((i+j)%2) {
                            v[i][j]=!v[i][j];
                        }
                    }
                }
            }
            break;
        }
    }
    cout << "!\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    return 0;
}