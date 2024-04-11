                                /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Inf 100000000

int k, des, mx[20];
int dp[1000010];

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int mem(int idx){
    if(idx < des)
        return Inf;
    if(idx == des)
        return 0;
    if(dp[idx] != -1)
        return dp[idx];
    int &ref = dp[idx];
    ref = mem(idx - 1) + 1;
    for(int i = 2; i <= k; i++)
        ref = min(ref, mem(idx - idx % i) + 1);
    return ref;
}

int main(){
    mx[1] = 1;
    for(int i = 2; i <= 15; i++){
        int d = gcd(mx[i - 1], i);
        mx[i] = mx[i - 1] * i / d;
    }
    int64 a, b;
    cin >> a >> b >> k;
    int64 t = b / mx[k];
    b -= t * mx[k];
    a -= t * mx[k];
    if(a <= mx[k]){
        des = b;
        memset(dp, -1, sizeof dp);
        cout << mem(a) << endl;
    }
    else{
        des = 0;
        memset(dp, -1, sizeof dp);
        int64 res = mem(a % mx[k]);

        int64 tmp = a / mx[k];
        memset(dp, -1, sizeof dp);
        res += (tmp - 1) * mem(mx[k]);

        des = b;
        memset(dp, -1, sizeof dp);
        res += mem(mx[k]);
        cout << res << endl;
    }
    return 0;
}