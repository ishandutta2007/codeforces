#include <bits/stdc++.h>

using namespace std;
const int c=70005;
int w, n, n2, m, per[c], inv[c], cl[c], szint[c];
vector<int> sz[c];
bool v[c];
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        n2=(1<<n), m=n*n2/2;
        for (int i=0; i<n2; i++) {
            per[i]=0, inv[i]=0, cl[i]=0, szint[i]=0, v[i]=0;
            sz[i].clear();
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        q.push(0);
        int po=1;
        while (q.size()>0) {
            int a=q.front();
            v[a]=true;
            //cout << "fontos " << a << "\n";
            q.pop();
            if (szint[a]==1) {
                per[po]=a, inv[a]=po;
                po*=2;
            }
            if (szint[a]>1) {
                int ert=0;
                for (auto x:sz[a]) {
                    if (v[x] && szint[x]<szint[a]) {
                        ert|=inv[x];
                    }
                }
                per[ert]=a, inv[a]=ert;
            }
            for (auto x:sz[a]) {
                if (!v[x]) {
                    szint[x]=szint[a]+1;
                    v[x]=1;
                    q.push(x);
                }
                if (szint[x]<szint[a]) {
                    int dif=__builtin_ctz(abs(inv[x]-inv[a]));
                    //cout << "szin " << x << " " << a << " " << dif << "\n";
                    cl[a]=(cl[x]^dif);
                }
            }
        }
        for (int i=0; i<n2; i++) {
            cout << per[i] << " ";
        }
        cout << "\n";
        if (__builtin_popcount(n)>1) {
            cout << -1 << "\n";
        } else {
            for (int i=0; i<n2; i++) {
                cout << cl[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
/*
1
3
0 1
0 5
0 7
1 2
1 4
2 5
2 6
3 5
3 6
3 7
4 6
4 7
*/