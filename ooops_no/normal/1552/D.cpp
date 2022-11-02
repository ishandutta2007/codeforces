#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
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
        vector<int> a(n);
        map<int,int> cnt;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int j = 0; j < (1 << n); j++){
            int sum = 0;
            for (int k = 0; k < n; k++){
                if (j & (1 << k)){
                    sum += a[k];
                }
            }
            cnt[sum]++;
        }
        bool x = 0;
        for (auto to : cnt){
            x |= to.second >= 2;
        }
        cout << (x ? "YES" : "NO") << endl;
    }
    return 0;
}