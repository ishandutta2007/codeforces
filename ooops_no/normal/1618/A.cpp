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
        vector<int> a(7);
        for (int i = 0; i < 7; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int b = a[0], c = a[1];
        bool f = 0;
        for (int i = 2; i < 7; i++){
            if (a[i] != b + c || f){
                cout << b << ' ' << c << ' ' << a[i] << endl;
                break;
            }
            f = 1;
        }
    }
    return 0;
}