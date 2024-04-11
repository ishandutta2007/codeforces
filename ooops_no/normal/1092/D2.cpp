#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include<deque>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    deque<pair<int,int>> q;
    for (int i = 0; i < n; i++){
        if (q.size() == 0){
            q.pb({a[i], 1});
        }
        else{
            if (q.back().first == a[i]){
                q.back().second++;
                if (q.size() > 1 && q[q.size() - 2].first >= q.back().first){
                    int now = q.back().second;
                    q.pop_back();
                    q.back().second += now;
                }
            }
            else if (q.back().first > a[i]){
                q.pb({a[i], 1});
            }
            else{
                if (q.back().second % 2 == 1){
                    cout << "NO\n";
                    return 0;
                }
                else{
                    q.pb({a[i], 1});
                }
            }
        }
    }
    while (q.size() > 1 && ((q[q.size() - 2].second % 2 == 0 && q[q.size() - 2].first < q.back().first) || (q.back().second % 2 == 0 && q.back().first < q[q.size() - 2].first))){
        int now = q.back().second;
        int mx = max(q.back().first, q[q.size() - 2].first);
        q.pop_back();
        q.back().first = mx;
        q.back().second += now;
    }
    if (q.size() == 1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}