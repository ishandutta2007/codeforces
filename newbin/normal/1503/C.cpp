#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long> > city;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        long long a, c;
        cin >> a >> c;
        city.push_back({a, c});
        ans += c;
    }
    sort(city.begin(), city.end());
    priority_queue<pair<long long, int>> Q;
    vector<bool> vis(n, false);
    Q.push({0, 0});
    while(!Q.empty()) 
	{
        long long d; int i;
        tie(d, i) = Q.top();//
		Q.pop();
        if(vis[i]) continue;
        vis[i] = true;
        if(i == n - 1) {
            ans -= d;
            break;
        }
        if(i > 0) {
            Q.push({d, i - 1});
        }
        int j = lower_bound(city.begin(), city.end(), make_pair(city[i].first + city[i].second, LLONG_MAX)) - city.begin() - 1;
        //LLONG_MAXlimits.h,long long int 
		Q.push({d, j});
        if(j + 1 < n) {
            Q.push({d - city[j + 1].first + city[i].first + city[i].second, j + 1});
        }
    }
    cout << ans << '\n';
}