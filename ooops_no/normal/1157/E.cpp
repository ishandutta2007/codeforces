#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    multiset<int> s;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    for (int i = 0; i < n; i++){
        auto j = s.lower_bound(n - v[i]);
        if (s.end() == j){
            j = s.begin();
        }
        cout << (v[i] + *j) % n << " ";
        s.erase(j);
    }
}