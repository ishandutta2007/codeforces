#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector < int > vi;
typedef vector < ll > vll;
typedef pair < int,int> pii;
typedef pair < double, double> pdd;
typedef pair < ll, ll > pll;

const int N = 55;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const ld EPS = 1e-10;
const ld PI = 3.1415926535897932384626433832795028;

ll must = 0;
ll a[N], dp[N][N], sum[N][N];
int n, k;

bool dinamika(){
    for(int i = 0;i<n;i++){
        if((sum[0][i] & must) == must) dp[i][1] = 1;
        else                           dp[i][1] = 0;
    }
    for(int i = 0;i<n;i++){
        for(int kk = 2;kk<=k;kk++){
            dp[i][kk] = 0;
            for(int j = 1;j<=i;j++){
                if((sum[j][i] & must) == must)
                    dp[i][kk] |= dp[j - 1][kk - 1];
            }
        }
    }
    return dp[n - 1][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    for(int l = 0;l<n;l++){
        for(int r = l;r<n;r++){
            for(int i = l;i<=r;i++)
                sum[l][r] += a[i];
        }
    }
    for(int j = 60;j>=0;j--){
        must ^= (1LL << (ll)j);
        if(!dinamika()){
            must ^= (1LL << (ll)j);
        }
    }
    cout << must << endl;
    return 0;
}