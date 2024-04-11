#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5e3 + 50;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int dp[N][N],pref[N][N];
char s[N];
int n,q,slozenost;

int get(int i1,int j1,int i2,int j2){
    int sol = pref[i2][j2];
    if(i1) sol -= pref[i1-1][j2];
    if(j1) sol -= pref[i2][j1-1];
    if(i1&&j1) sol += pref[i1-1][j1-1];
    return sol;
}

int f(int i,int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i  + 1 == j && s[i] == s[j]) return dp[i][j] = 1;
    if(i + 1 == j) return dp[i][j] = 0;
    if(i == j) return 1;
    if(s[i] == s[j]){
        return dp[i][j] = f(i + 1, j - 1);
    }
    return dp[i][j] = 0;
}

int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%s",&s);
    n = strlen(s);
    scanf("%d",&q);
    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(f(i,j) != INF){
                cnt += f(i,j);
            }
            pref[i][j] = cnt;
            if(i) pref[i][j] += pref[i-1][j];
        }
    }
    for(int i = 0;i<q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",get(x-1,x-1,y-1,y-1));
    }
}