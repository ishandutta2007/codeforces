#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, cnt[c][c], db[c], ki[2*c];
bitset<c> b[c];
vector<int> spec;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        for (int j=1; j<=x; j++) {
            int y;
            cin >> y;
            db[y]++;
            b[y][i]=1;
        }
    }
    if (n==2) {
        cout << 1 << " " << 2 << "\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cnt[i][j]=(b[i] & b[j]).count();
        }
    }
    for (int i=1; i<=n; i++) {
        if (db[i]==n) {
            spec.push_back(i);
        }
    }

    if (spec.size()==n) {
        for (int i=1; i<n; i++) {
            cout << i << " " << n << "\n";
        }
        return 0;
    }
    if (spec.size()==2) {
        int a=spec[0], b=spec[1];
        int s=(a>1 ? 1 : b>2 ? 2 : 3);
        cout << a << " " << b << "\n";
        for (int i=1; i<=n; i++) {
            if (i!=a && i!=b) {
                if (cnt[i][s]>2) {
                    cout << i << " " << a << "\n";
                } else {
                    cout << i << " " << b << "\n";
                }
            }
        }
        return 0;
    }

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (cnt[i][j]==1) {
                if (spec.size()==1) {
                    unio(i, spec[0]);
                    unio(i+n, spec[0]+n);
                }
                unio(i, j);
                unio(i+n, j+n);
            }
            if (cnt[i][j]==2) {
                unio(i, j+n);
                unio(i+n, j);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (holvan(i)!=holvan(j) && cnt[i][j]>=3) {
                cout << i << " " << j << "\n";

            }
        }
    }


    return 0;
}
/*
6
5 1 2 3 4 5
6 1 2 3 4 5 6
5 1 2 3 5 6
3 1 2 4
4 1 2 3 5
3 2 3 6
*/