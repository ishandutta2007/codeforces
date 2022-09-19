#include <bits/stdc++.h>

using namespace std;
int w, n, m, k;
vector<int> sz[2];
set<int> s[2];
map<unsigned long long, int> mm;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            s[0].insert(x);
        }
        for (int i=1; i<=m; i++) {
            int y;
            cin >> y;
            s[1].insert(y);
        }

        long long ans=0;


        for (int i=1; i<=k; i++) {
            int a, b;
            cin >> a >> b;
            unsigned long long x[2], y[2], s1=23342, s2=363453, s3=232131, s4=3434543, g;
            auto lb=s[0].lower_bound(a);
            x[1]=*lb;
            if (x[1]==a) {
                x[0]=x[1];
            } else {
                lb--;
                x[0]=*lb;
            }

            lb=s[1].lower_bound(b);
            y[1]=*lb;
            if (y[1]==b) {
                y[0]=y[1];
            } else {
                lb--;
                y[0]=*lb;
            }
            x[0]++, x[1]++, y[0]++, y[1]++;
            g=x[0]*x[0]*x[0]*x[0]*s1+x[1]*x[1]*x[1]*s2+y[0]*y[0]*s3+y[1]*s4;
            ans-=mm[g]++;
            sz[0].push_back(a), sz[1].push_back(b);
        }
        //cout << "vege " << ans << "\n";
        mm.clear();

        for (int d=0; d<2; d++) {
            int si=sz[d].size();
            sort(sz[d].begin(), sz[d].end());
            for (int i=0; i<si; i++) {
                int x=sz[d][i];
                int lo=i, hi=si, mid;
                auto lb=s[d].lower_bound(x);
                //cout << "ertek " << x << " " << *lb << "\n";
                while (hi-lo>1) {
                    mid=(hi+lo)/2;
                    if (sz[d][mid]<*lb) {
                        lo=mid;
                    } else {
                        hi=mid;
                    }
                }
                ans+=lo-i;
            }

            sz[d].clear(), s[d].clear();
            //break;
        }

        cout << ans << "\n";
    }
    return 0;
}
/*
1
5 4 9
0 1 2 6 1000000
0 4 8 1000000
4 4
2 5
2 2
6 3
1000000 1
3 8
5 8
8 8
6 8
*/