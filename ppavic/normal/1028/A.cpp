#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define TRACE(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << 20);
const double EPS = 1e-9;
const double PI = 3.1415926535;

char s[N][N];
int mxx, mix = INF, mxy, miy = INF,n,m;

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);
    scanf("%d%d", &n, &m);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf(" %c", &s[i][j]);
            if(s[i][j] == 'B'){
                mix = min(mix, i);
                miy = min(miy, j);
                mxx = max(mxx, i);
                mxy = max(mxy, j);
            }
        }
    }
    printf("%d %d\n", (mix + mxx) / 2, (miy + mxy) / 2);
    return 0;
}