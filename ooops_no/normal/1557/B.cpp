#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>

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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int,int> ind;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++){
            ind[b[i]] = i;
        }
        for (int i = 0; i < n; i++){
            a[i] = ind[a[i]];
        }
        int i = 0, ans = 0;
        while(i < n){
            ans++;
            if (i == n - 1) break;
            for (int j = i + 1; j < n; j++){
                if (a[j] != a[j - 1] + 1){
                    i = j;
                    break;
                }
                if (j == n - 1) i = n;
            }
        }
        cout << (ans <= k ? "Yes" : "No") << endl;
    }
    return 0;
}