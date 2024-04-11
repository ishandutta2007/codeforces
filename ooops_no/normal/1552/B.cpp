#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> r(n, vector<int>(5));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 5; j++){
                cin >> r[i][j];
            }
        }
        int j = 0;
        for (int i = 0; i < n; i++){
            if (i == j) continue;
            int cnt = 0;
            for (int k = 0; k < 5; k++){
                if (r[i][k] < r[j][k]){
                    cnt++;
                }
            }
            if (cnt >= 3) j = i;
        }
        for (int i = 0; i < n; i++){
            if (i == j) continue;
            int cnt = 0;
            for (int k = 0; k < 5; k++){
                if (r[i][k] < r[j][k]){
                    cnt++;
                }
            }
            if (cnt >= 3) {
                j = -2;
                break;
            }
        }
        cout << j + 1 << endl;
    }
    return 0;
}