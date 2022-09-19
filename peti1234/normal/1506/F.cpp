#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, sum, l[c], r[c];

vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sum=0, l[0]=r[0]=1;
        sz.clear();
        for (int i=1; i<=n; i++) {
            cin >> l[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> r[i];
        }
        for (int i=0; i<=n; i++) {
            sz.push_back({l[i], r[i]});
        }
        sort(sz.begin(), sz.end());
        for (int i=1; i<=n; i++) {
            int na=sz[i-1].first, ka=sz[i-1].second, nb=sz[i].first, kb=sz[i].second;
            bool par=1-(na+ka)%2;
            if (na-ka==nb-kb) {
                sum+=par*(nb-na);
            }
            else {
                int dif=nb-kb-na+ka;
                if (!par) {
                    sum+=(dif+1)/2;
                } else {
                    sum+=dif/2;
                }
            }
        }
        //cout << "valasz: ";
        cout << sum << "\n";
    }
    return 0;
}
/*
4
3
1 4 2
1 3 1
2
2 4
2 3
2
1 1000000000
1 1000000000
4
3 10 5 8
2 5 2 4
*/