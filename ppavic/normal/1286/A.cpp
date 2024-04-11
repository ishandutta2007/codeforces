#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 105;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 << 18);

int n, a, b, aa, bb;
int p[N], dp[N][3][N][N];

int f(int i,int lst,int A, int B){
    if(A < 0 || B < 0) return INF;
    if(i == n) return 0;
    if(dp[i][lst][A][B] != -1) return dp[i][lst][A][B];
    if(p[i] != 2)
        return f(i + 1, p[i], A, B) + (p[i] != lst && lst != 2);
    return dp[i][lst][A][B] = min(f(i + 1, 0, A - 1, B) + (lst == 1),
               f(i + 1, 1, A, B - 1) + (lst == 0));
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%d", p + i);
        if(p[i] == 0) p[i] = 2;
        else{
            p[i] = p[i] % 2;
            if(p[i]) b++;
            else     a++;
        }
    }
    aa = (n / 2) - a;
    bb = ((n + 1) / 2) - b;
    printf("%d\n",  f(0, 2, aa, bb));
    return 0;

}