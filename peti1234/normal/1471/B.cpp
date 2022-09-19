#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > sz;
long long w, n, x, y, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> x, sum=0, sz.clear();
        for (int i=1; i<=n; i++) {
            cin >> y;
            sum+=y;
            int z=y, db=0;
            while(z%x==0) {
                z/=x, db++;
            }
            sz.push_back({y, db});
        }
        for (int i=0; i<sz.size(); i++) {
            int fi=sz[i].first, se=sz[i].second;
            if (!se) {
                break;
            }
            sum+=fi;
            sz.push_back({fi, se-1});
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
1
1 2
12
*/