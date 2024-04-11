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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        string s;
        cin >> s;
        vector<int> arr, arr2;
        for (int i = 0; i < n; i++){
            if (s[i] == 'B'){
                arr.pb(a[i]);
            }
            else{
                arr2.pb(a[i]);
            }
        }
        sort(arr.begin(), arr.end());
        sort(arr2.rbegin(), arr2.rend());
        bool x = 1;
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] <= i) x = 0;
        }
        for (int i = 0; i < arr2.size(); i++){
            if (arr2[i] > n - i) x = 0;
        }
        cout << (x ? "YES" : "NO") << endl;
    }
    return 0;
}