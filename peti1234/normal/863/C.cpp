#include <bits/stdc++.h>

using namespace std;
long long k, x, y;
int a, b;
pair<pair<int, int>, pair<long long, long long> > sz[61][4][4];
int main()
{

    cin >> k >> a >> b;
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            cin >> sz[0][i][j].first.first;
        }
    }
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            cin >> sz[0][i][j].first.second;
            if ((j+1)%3==i%3) {
                sz[0][i][j].second.first++;
            }
            if ((i+1)%3==j%3) {
                sz[0][i][j].second.second++;
            }
        }
    }
    for (int p=0; k>0; p++) {
        if (k%2) {
            auto s=sz[p][a][b];
            a=s.first.first, b=s.first.second;
            x+=s.second.first, y+=s.second.second;
        }
        for (int i=1; i<=3; i++) {
            for (int j=1; j<=3; j++) {
                auto s=sz[p][i][j];
                int ii=s.first.first, jj=s.first.second;
                auto s2=sz[p][ii][jj];
                sz[p+1][i][j]={{s2.first.first, s2.first.second}, {s.second.first+s2.second.first, s.second.second+s2.second.second}};
            }
        }
        k/=2;
    }
    cout << x << " " << y << "\n";
    return 0;
}