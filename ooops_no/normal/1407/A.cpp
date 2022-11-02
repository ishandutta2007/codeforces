#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<deque>

using namespace std;

#define pb push_back
#define int long long
#define ld long double

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n), cnt(2);
        for (int i = 0; i < n; i++){
            cin >> v[i];
            cnt[v[i]]++;
        }
        if (cnt[0] >= n / 2){
            cout << cnt[0] << endl;
            for (int i = 0; i < cnt[0]; i++){
                cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        else{
            if (cnt[1] % 2 == 1) cnt[1]--;
                cout << cnt[1] << endl;
                for (int i = 0; i < cnt[1]; i++){
                    cout << 1 << " ";
                }
                cout << endl;
        }
    }
    return 0;
}