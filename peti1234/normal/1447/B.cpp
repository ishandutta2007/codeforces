#include <bits/stdc++.h>

using namespace std;
int w, n, m, sum;
vector<int> a;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> m, sum=0, a.clear();
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int x; cin >> x;
                sum+=x;
                a.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        for (int i=1; i<a.size(); i+=2) {
            sum-=min(0, 2*(a[i]+a[i-1]));
        }
        cout << sum << "\n";
    }
    return 0;
}