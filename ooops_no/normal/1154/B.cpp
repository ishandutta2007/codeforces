#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back


signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            bool x = true;
            for (auto to : v){
                if (to + i == j || to == j || to - i == j){
                    continue;
                }
                else{
                    x = false;
                    break;
                }
            }
            if (x){
                cout << i;
                return 0;
            }
        }
    }
    cout << -1;
}