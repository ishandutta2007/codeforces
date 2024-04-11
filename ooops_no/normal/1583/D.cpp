#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

int ask(vector<int> a){
    cout << "? ";
    for (auto to : a) cout << to << ' ';
    cout << endl;
    int p;
    cin >> p;
    return p;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ans(n);
    int now = n, cnt = 2;
    while(1){
        if (cnt > n) break;
        vector<int> a(n, 1);
        a.back() = cnt++;
        int val = ask(a);
        if (val == 0) break;
        now--;
    }
    ans.back() = now;
    for (int i = 1; i <= n; i++){
        if (i == now) continue;
        vector<int> a(n);
        for (int j = 0; j < n - 1; j++){
            a[j] = (n + 1) - i;
        }
        a.back() = (n + 1) - now;
        int val = ask(a);
        ans[val - 1] = i;
    }
    cout << "! ";
    for (auto to : ans) cout << to << ' ';
    cout << endl;
    return 0;
}