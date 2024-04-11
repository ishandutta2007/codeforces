#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        deque<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (a.back() != n && a.front() != n){
            cout << -1 << endl;
            continue;
        }
        deque<int> p;
        while(a.size() > 0){
            if (a.back() > a.front()){
                p.pb(a.back());
                a.pop_back();
            }
            else{
                p.push_front(a.front());
                a.pop_front();
            }
        }
        for (auto to : p){
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}