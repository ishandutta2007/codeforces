//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

char s[300],t[300], virus[300];

int next[300][27];

int dp[110][110][110];
int p[110][110][110];


void update(int ni,int nj,int nk,int fi, int fj, int fk, int tp){
    if (dp[ni][nj][nk] < dp[fi][fj][fk] + (tp >= 0)){
//      if (tp >= 0) eprintf("%d %d %d -> %d %d %d\n", fi, fj, fk, ni, nj, nk);
        dp[ni][nj][nk] = dp[fi][fj][fk] + (tp >= 0);
        p[ni][nj][nk] = tp;
    }
}

void go(int i,int j,int k){
    if (!i || !j) return;
    int tp = p[i][j][k];
    if (tp == -2) go(i-1,j,k);
    else if (tp == -3) go(i,j-1,k);
    else {
//      eprintf("%d %d %d %d\n", i,j,k, tp);
        assert(tp >= 0);
        go(i-1,j-1,tp);
        assert(s[i-1] == t[j-1]);
        printf("%c", s[i-1]);
    }
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    
    while (gets(s)){
        gets(t);
        gets(virus);

        for (int i = 0; virus[i]; i++){
            for (char c = 'A' ; c <= 'Z'; c++){
                next[i][c - 'A'] = 0;
                for (int j = i; j >= 0; j--)    
                    if (string(virus, virus + j + 1) == (string(virus + i - j, virus + i) + c)){
                        next[i][c - 'A'] = j+1;
                        break;
                    }
            }
        }


        memset(p,-1,sizeof(p));
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        p[0][0][0] = 0;

        for (int i = 0; s[i]; i++)
            for (int j = 0; t[j]; j++)
                for (int k = 0; virus[k]; k++)
                    if (p[i][j][k] != -1){
                        update(i+1,j, k, i,j,k,-2);
                        update(i,j+1, k, i,j,k,-3);
                        if (s[i] == t[j])
                            update(i+1, j+1, next[k][s[i]-'A'], i, j, k, k);
                    }

        int besti, bestj, bestk;
        besti = 0, bestj = strlen(t), bestk = 0;

        for (int i = 0; !i || s[i-1]; i++)
            for (int j = 0; !j || t[j-1]; j++)
                for (int k = 0; virus[k]; k++)
                   if (dp[besti][bestj][bestk] < dp[i][j][k])
                       besti = i, bestj = j, bestk = k;

        eprintf("%d %d %d %d\n", besti, bestj, bestk, dp[besti][bestj][bestk]);

        if (dp[besti][bestj][bestk])
            go(besti, bestj, bestk);
        else
            printf("0");
        puts("");
        break;
    }  
    TIMESTAMP(end);
  return 0;
}