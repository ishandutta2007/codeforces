#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

bool prime(int v){
    for (int i = 2; i * i <= v; i++){
        if (v % i == 0) return 0;
    }
    return 1;
}

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
        int n, sum = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if (!prime(sum)){
            cout << n << endl;
            for (int i = 1; i <= n; i++){
                cout << i << ' ';
            }
            cout << endl;
        }
        else{
            for (int i = 0; i < n; i++){
                if (!prime(sum - a[i])){
                    cout << n - 1 << endl;
                    for (int j = 0; j < n; j++){
                        if (j != i){
                            cout << j + 1 << ' ';
                        }
                    }
                    cout << endl;
                    break;
                }
            }
        }
    }
    return 0;
}