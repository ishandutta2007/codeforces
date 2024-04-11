#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
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
        int n, m, k;
        cin >> n >> m >> k;
        int big = n % m, small = m - n % m;
        vector<int> b(n);
        for (int i = 0; i < k; i++){
            vector<int> ord(n);
            iota(ord.begin(), ord.end(), 0);
            sort(ord.begin(), ord.end(), [&](int i, int j){return b[i] < b[j];});
            int now = 0;
            for (int j = 0; j < big; j++){
                cout << n / m + 1 << ' ';
                for (int k = now; k < now + n / m + 1; k++){
                    cout << ord[k] + 1 << ' ';
                    b[ord[k]]++;
                }
                now += n / m + 1;
                cout << endl;
            }
            for (int j = 0; j < small; j++){
                cout << n / m << ' ';
                for (int k = now; k < now + n / m; k++){
                    cout << ord[k] + 1 << ' ';
                }
                now += n / m;
                cout << endl;
            }
        }
    }
    return 0;
}