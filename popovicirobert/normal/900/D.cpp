#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MOD = (int) 1e9 + 7;

map <int, int> dp;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int check(int y) {
    if(dp[y] > 0)
        return dp[y];
    if(y == 1)
        return dp[y] = 1;
    int ans = lgput(2, y - 1);
    for(int i = 1; i * i <= y; i++) {
        if(y % i == 0) {
            ans -= check(i);
            if(ans < 0)
                ans += MOD;
             mod(ans);
             if(i > 1 && i * i != y)
                ans -= check(y / i);
             if(ans < 0)
                ans += MOD;
             mod(ans);
        }
    }
    return dp[y] = ans;
}

void sleepcp(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}

int main() {
    //ifstream cin("D.in");
    //ofstream cout("D.out");
    int i, x, y;
    ios::sync_with_stdio(false);
    cin >> x >> y;
    if(y % x > 0) {
        cout << 0;
        return 0;
    }
    y /= x;
    cout << check(y);
	//40
	sleepcp(1000);
    return 0;
}