#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int> pii;
typedef pair < int, pii> pip;
typedef pair < pii, int> ppi;

const int N =  500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

int n,k;
int s[N][N];

int main(){
    scanf("%d%d",&n,&k);
    if(k > 2 * (n - 2)) {
        printf("NO\n");
        return 0;
    }
    if (k == 1){
        s[1][(n - 1) / 2] = 1;k--;
        for(int i = 0;i<4;i++){
            for(int j = 0;j<n;j++){
                if(!(k == 0 || (i == 0 || i == 3 || j == 0 || j == n - 1) || s[i][j])){
                    s[i][j] = 1,k--;
                }
            }
        }
    }
    else if(k % 2 == 0){
        for(int j = 0;j<n;j++){
            for(int i = 0;i<4;i++){
                if(!(k == 0 || (i == 0 || i == 3 || j == 0 || j == n - 1 || s[i][j]))){
                    s[i][j] = 1,k--;
                }
            }
        }
    }
    else{
        s[1][n / 2] = 1;k--;
        for(int j = 0;j<n;j++){
            for(int i = 0;i<4;i++){
                if(!(k == 0 || j == n - j - 1 || (i == 0 || i == 3 || j == 0 || j == n - 1 || s[i][j]))){
                    s[i][j] = 1,k--;
                    s[i][n - j - 1] = 1,k--;
                }
            }
        }
    }
/*+
    else if(k >= 4){
        s[1][1] = 1;s[2][1] = 1;
        s[1][n - 2] = 1;s[2][n - 2] = 1;
        k -= 4;
        for(int i = 0;i<4;i++){
            for(int j = 0;j<n;j++){
                if(!(k == 0 || (i == 0 || i == 3 || j == 0 || j == n - 1) || s[i][j])){
                    s[i][j] = 1,k--;
                }
            }
        }
    }
**/
    printf("YES\n");
    for(int i = 0;i<4;i++){
        for(int j = 0;j<n;j++)
            printf((s[i][j] ?  "#" : "."));
        printf("\n");
    }
}