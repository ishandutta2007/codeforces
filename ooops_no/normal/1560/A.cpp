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
#define int long long
#define ll long long

mt19937 rnd(51);

bool check(int a){
    if (a % 10 == 3) return 1;
    int sum = 0;
    while(a > 0){
        sum += a % 10;
        a /= 10;
    }
    return (sum % 3 == 0);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    int now = 1;
    while(a.size() < 1000){
        if (check(now)){
            now++;
            continue;
        }
        a.pb(now);
        now++;
    }
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        cout << a[k - 1] << endl;
    }
    return 0;
}