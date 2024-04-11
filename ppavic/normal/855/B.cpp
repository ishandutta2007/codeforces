#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long int llint;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;

llint mx,mi;

llint a,b,c,x,sol;
llint dp[N];
vector < llint > v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> c;
    cin >> mx;
    mi = mx;
    v.push_back(mx);
    dp[0] = mx * (a + b);
    for(int i = 1;i<n;i++){
        cin >> x;
        if(x > mx) mx = x;
        if(x < mi) mi = x;
        v.push_back(x);
        dp[i] = x * b;
        if(a > 0){
            dp[i] += mx * a;
        }
        else{
            dp[i] += mi * a;
        }
        dp[i] = max(dp[i - 1], dp[i]);
    }
    sol = (a + b + c) * v[0];
    for(int i = 0;i<n;i++){
        sol = max(c * v[i] + dp[i] , sol);
    }
    cout << sol << endl;
}