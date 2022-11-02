#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

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
        string s;
        cin >> s;
        vector<int> col(3);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'R') col[0]++;
            else if (s[i] == 'S') col[1]++;
            else col[2]++;
        }
        int mx = max({col[0], col[1], col[2]});
        char c;
        if (mx == col[0]) c = 'P';
        else if (mx == col[1]) c = 'R';
        else c = 'S';
        for (int i = 0; i < s.size(); i++) cout << c;
        cout << endl;
    }
    return 0;
}