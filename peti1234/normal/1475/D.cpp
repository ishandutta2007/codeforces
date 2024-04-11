#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, m, t[c], mini, sum;
vector<long long> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        sum=0, mini=2*c, a.clear(), b.clear();
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (x==1) {
                a.push_back(t[i]);
                sum+=t[i];
            } else {
                b.push_back(t[i]);
            }
        }
        sort(a.rbegin(), a.rend()), sort(b.rbegin(), b.rend());
        long long x=a.size(), y=b.size();
        while (x>0 && sum>=m) {
            mini=x;
            x--;
            sum-=a[x];
        }
        for (int i=0; i<y; i++) {
            sum+=b[i];
            while (x>0 && sum>=m) {
                mini=min(mini, x+2*i+2);
                x--;
                sum-=a[x];
            }
            if (sum>=m) {
                mini=min(mini, x+2*i+2);
            }
        }
        if (mini==2*c) {
            mini=-1;
        }
        //cout << "valasz ";
        cout << mini << "\n";
    }
    return 0;
}
/*
1
5 7
5 3 2 1 4
2 1 1 2 1
*/