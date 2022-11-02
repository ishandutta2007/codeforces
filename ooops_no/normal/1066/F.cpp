#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    map<int, vector<pair<int,int>>> mp;
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        mp[max(v[i].first, v[i].second)].pb({v[i].first, v[i].second});
    }
    pair<int,int> mn_last = {0, 0}, mx_last = {0, 0};
    int mn_ans = 0, mx_ans = 0;
    for (auto to : mp){
        sort(to.second.begin(), to.second.end(), cmp);
        pair<int,int> nw_mn = to.second[0], nw_mx = to.second.back();
        int nw_mn_ans = min(dist(mn_last, nw_mx) + dist(nw_mx, nw_mn) + mn_ans, dist(mx_last, nw_mx) + dist(nw_mx, nw_mn) + mx_ans);
        int nw_mx_ans = min(dist(mn_last, nw_mn) + dist(nw_mx, nw_mn) + mn_ans, dist(mx_last, nw_mn) + dist(nw_mx, nw_mn) + mx_ans);
        mn_last = nw_mn, mx_last = nw_mx;
        mn_ans = nw_mn_ans;
        mx_ans = nw_mx_ans;
    }
    cout << min(mn_ans, mx_ans) << endl;
    return 0;
}