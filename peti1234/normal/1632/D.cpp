#include <bits/stdc++.h>

using namespace std;

int n, ans, t[200005], ert;
vector<int> sz, sz2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    sz.push_back(0);
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        ert=0;
        sz.push_back(i);
        int el=i;
        while (true) {
            int id=sz.back(), s=__gcd(ert, t[id]);
            //out << "fontos " << i-el+1 << " " << ert << " " << i-id+1 << "\n";
            if (i-el+1<=ert && ert<i-id+1) t[i]=1e9+7;
            if (id) sz.pop_back();
            if (s!=ert) sz2.push_back(id);
            ert=s, el=id;
            if (id==0) break;
        }
        while (sz2.size()>0) {
            sz.push_back(sz2.back());
            sz2.pop_back();
        }
        if (t[i]==1e9+7) {
            ans++;
        }

        cout << ans << " ";
    }
    return 0;
}