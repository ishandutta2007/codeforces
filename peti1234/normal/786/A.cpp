#include <bits/stdc++.h>

using namespace std;
int n, a, b;
vector<int> e, m;
int l[7002][2], ans[7002][2], h[7002][2];
queue<pair<bool, pair<int, bool> > > sz;
void v(int a) {
    if (a==-1) cout << "Lose ";
    if (a==0) cout << "Loop ";
    if (a==1) cout << "Win ";
}
int main()
{
    cin >> n;
    cin >> a;
    for (int i=1; i<=a; i++) cin >> l[i][0];
    cin >> b;
    for (int i=1; i<=b; i++) cin >> l[i][1];

    sz.push({0, {0, 0}}), sz.push({0, {0, 1}});
    while(sz.size()>0) {
        bool x=sz.front().first, p=sz.front().second.second, q=!p;
        int id=sz.front().second.first, si=a;
        if (q) si=b;
        sz.pop();
        if (!ans[id][p]) {
            if (x) ans[id][p]=1;
            else ans[id][p]=-1;
            for (int i=1; i<=si; i++) {
                //cout << "faszom " << id << " " << l[i][q] << " " << n << "\n";
                int ert=(id-l[i][q]+n)%n;
                if (!ans[ert][q]) {
                    h[ert][q]++;
                    if (!x) sz.push({1, {ert, q}});
                    else if (h[ert][q]==si) sz.push({0, {ert, q}});
                }
            }
        }
    }
    for (int i=1; i<n; i++) v(ans[i][0]);
    cout << "\n";
    for (int i=1; i<n; i++) v(ans[i][1]);
    return 0;
}
/*
8
2 6 2
2 3 6
*/