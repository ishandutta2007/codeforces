#include <bits/stdc++.h>

using namespace std;
int w, n, kezd, veg;
long long s, x, sum;
deque<pair<long long, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        q.push_back({0, 1});
        for (int i=1; i<=n; i++) {
            cin >> x;
            sum+=x;
            q.push_back({sum, i+1});
            while (q.front().first-sum>s) q.pop_front();
            if (i-q.front().second>=veg-kezd) veg=i, kezd=q.front().second;
        }

        if (!veg) cout << -1 << "\n";
        else cout << kezd << " " << veg << "\n";

        kezd=0, veg=0, s=0, x=0, sum=0;
        q.clear();
    }
    return 0;
}
/*
1
1 0
0
*/