#include <bits/stdc++.h>

using namespace std;
int n, db, si, x;
long long sum;
vector<int> e, v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, db=n;
    for (int i=1; i<=n; i++) {
        bool c=false;
        int x, a, b;
        cin >> x >> a, b=a;
        for (int i=1; i<x; i++) {
            int f;
            cin >> f;
            if (!c && f>b) {
                c=true;
                sum+=2*db-1;
                db--;
            }
            b=f;
        }
        if (!c) {
            e.push_back(a), v.push_back(b);
        }
    }
    si=e.size();
    e.push_back(1000001);
    sort(e.begin(), e.end()), sort(v.begin(), v.end());
    for (int i=0; i<si; i++) {
        while(x<si && v[i]>=e[x]) x++;
        sum+=si-x;
    }
    cout << sum << "\n";
    return 0;
}