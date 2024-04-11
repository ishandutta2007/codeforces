#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iostream>
#include <ctime>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vll;
typedef pii pt;

const int N = 1500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BASE = 31337;
const int LOG = 18;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, a, b, c = 0;
int mat[N][N];

int main(){
    scanf("%d%d%d",&n,&a,&b);
    if(a != 1 && b != 1){
        printf("NO\n");
        return 0;
    }
    if(a == 1 && b == 1 && n == 2){
        printf("NO\n");
        return 0;
    }
    if(a == 1 && b == 1 && n == 3){
        printf("NO\n");
        return 0;
    }
    if(a == 1 && b == 1){
        printf("YES\n");
        for(int i = 2;i<=n;i++)
            mat[i][i - 1] = 1, mat[i - 1][i] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    if(a != 1){
        for(int i = 1;i<=n - a + 1;i++){
            for(int j = 1;j<=n - a + 1;j++){
                if(i != j) mat[i][j] = 1, mat[j][i] = 1;
            }
        }
        printf("YES\n");
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    if(b != 1){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j) continue;
                mat[i][j] = 1;
            }
        }
        for(int i = 1;i<=n - b + 1;i++){
            for(int j = 1;j<=n - b + 1;j++){
                if(i != j) mat[i][j] = 0, mat[j][i] = 0;
            }
        }
        printf("YES\n");
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    return 0;
}