#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int MOD = 998244353, N = 5010;
int c[N][N];

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b){
    return (a * b % MOD);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j++){
            c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    int n, k, ans = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    int one = 0;
    for (auto to : s){
        if (to == '1') one++;
    }
    if (one < k){
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++){
        int cnt = 0, sum = 0;
        for (int j = i; j < s.size() && cnt <= k; j++){
            sum++;
            if (s[j] == '1') cnt++;
        }
        if (cnt > k){
            cnt--;
            sum--;
        }
        if (s[i] == '0'){
            if (cnt > 0){
                ans = add(ans, c[sum - 1][cnt - 1]);
            }
        }
        else{
            if (sum - cnt > 0){
                ans = add(ans, c[sum - 1][sum - cnt - 1]);
            }
        }
    }
    cout << add(ans, 1) << endl;
    return 0;
}