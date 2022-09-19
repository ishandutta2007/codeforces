#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int t[2000001];
vector<int> sol;
int n, q;
int ans(int a, int b)
{
    int x=b/a;
    if (x*a==b) {
        return x;
    }
    if ((a-1)*(x+1)>b) {
        return n+1;
    }
    return x+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=1; i<=q; i++) {
        for (int i=0; i<v.size(); i++) {
            t[v[i]]=0;
        }
        v.clear();
        sol.clear();
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            t[x]++;
            if (t[x]==1) {
                v.push_back(x);
            }
        }
        for (int i=0; i<v.size(); i++) {
            sol.push_back(t[v[i]]);
        }
        long long mini=n;
        sort(sol.begin(), sol.end());
        for (int i=sol[0]+1; i>=2; i--) {
            long long db=0;
            for (int j=0; j<sol.size(); j++) {
                db+=ans(i, sol[j]);
            }
            mini=min(mini, db);
        }
        cout << mini << "\n";
    }
    return 0;
}
/*
1
11
1 5 1 5 1 5 1 1 1 1 5
*/