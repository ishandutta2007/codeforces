#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e6 + 10;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> pr(N);
    for (int i = 1; i < N; i++){
        pr[i] = pr[i - 1] ^ i;
    }
    while(t--){
        int a, b;
        cin >> a >> b;
        int val = pr[a - 1];
        if (val == b){
            cout << a << endl;
        }
        else{
            if ((val ^ b) == a){
                cout << a + 2 << endl;
            }
            else cout << a + 1 << endl;
        }
    }
    return 0;
}