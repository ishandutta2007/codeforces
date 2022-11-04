#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 300;

pair <int, int> arr[MAXN + 1];
map <string, int> mp;

map < pair <int, int>, int > cst;

string str1, str2;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a, b, k, f;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> k >> f;
    int cur = 0;
    for(i = 1; i <= n; i++) {
        cin >> str1 >> str2;
        if(mp[str1] == 0) {
            mp[str1] = ++cur;
        }
        if(mp[str2] == 0) {
            mp[str2] = ++cur;
        }
        arr[i] = {mp[str1], mp[str2]};
    }
    arr[0].second = -1;
    int ans = 2e9;
    for(int card = 0; card <= k; card++) {
        cst.clear();
        int tot = 0;
        for(i = 1; i <= n; i++) {
            if(arr[i].first == arr[i - 1].second) {
                cst[{min(arr[i].first, arr[i].second), max(arr[i].first, arr[i].second)}] += b;
                tot += b;
            }
            else {
                cst[{min(arr[i].first, arr[i].second), max(arr[i].first, arr[i].second)}] += a;
                tot += a;
            }
        }
        vector <int> mx;
        for(auto it : cst) {
            mx.push_back(it.second);
        }
        sort(mx.begin(), mx.end(), greater<int>());
        int sum = 0, sz = min(card, (int) mx.size());
        for(i = 0; i < sz; i++) {
            sum += mx[i];
        }
        ans = min(ans, tot - sum + f * card);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}