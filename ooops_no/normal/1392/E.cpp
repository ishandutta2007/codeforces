#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0) cout << " ";
            if (j % 2 == 1){
                cout << (1LL << (i + j));
            }
            else{
                cout << 0;
            }
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while(q--)
    {
        int i = 0, j = 0, sum;
        cin >> sum;
        vector<pair<int,int>> ans;
        ans.emplace_back(i, j);
        for (int qq = 0; qq < 2 * (n - 1); ++qq)
        {
            if (i == n - 1){
                ++j;
                ans.emplace_back(i, j);
                continue;
            }
            if (j == n - 1){
                ++i;
                ans.emplace_back(i, j);
                continue;
            }
            if (((sum >> (qq + 1)) & 1) == (j & 1)){
                ++i;
            }
            else ++j;
            ans.emplace_back(i, j);
        }
        for (auto to : ans)
            cout << to.first + 1 << " " << to.second + 1 << endl;
    }
    return 0;
}