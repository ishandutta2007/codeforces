#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int now = 1;
        for (int i = 0; i < n; i++){
            if (a[i] == 0){
                if (i > 0 && a[i - 1] == 0){
                    now = -1;
                    break;
                }
            }
            else{
                if (a[i - 1] == 1){
                    now += 5;
                }
                else{
                    now++;
                }
            }
        }
        cout << now << endl;
    }
    return 0;
}