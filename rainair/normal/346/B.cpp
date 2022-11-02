#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define RFOR(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100 + 5;
char str1[MAXN],str2[MAXN],virus[MAXN];
int N,M,K;
int f[MAXN][MAXN][MAXN],next[MAXN];
int pre[MAXN][MAXN][MAXN][3];

inline void get(int i,int j,int k,int x,int y,int z,int pos){
    // DEBUG(x);DEBUG(y);DEBUG(z);DEBUG(f[x][y][z]);
    // system("Sleep 1");
    if(f[x][y][z] + pos > f[i][j][k]){
        f[i][j][k] = f[x][y][z] + pos;
        pre[i][j][k][0] = x;
        pre[i][j][k][1] = y;
        pre[i][j][k][2] = z;
    }
}

inline void init(){
    next[1] = next[0] = 0;
    FOR(i,1,K-1){
        int j = next[i];
        while(j > 0 && virus[i] != virus[j]) j = next[j];
        next[i+1] = (virus[i] == virus[j]) ? j+1 : 0;
    }
}

int main(){
    scanf("%s%s%s",str1,str2,virus);
    N = strlen(str1);M=strlen(str2);K=strlen(virus);
    CLR(f,-1);
    CLR(pre,-1);
    init();
    f[0][0][0] = 0;
    FOR(i,0,N){
        FOR(j,0,M){
            FOR(k,0,K-1){
                get(i+1,j,k,i,j,k,0);
                get(i,j+1,k,i,j,k,0);
                if(f[i][j][k] >= 0 && str1[i] == str2[j]){
                    if(str1[i] == virus[k]){
                        get(i+1,j+1,k+1,i,j,k,1);
                    }
                    else{
                        int pos = next[k];
                        while(pos > 0 && str1[i] != virus[pos]) pos = next[pos];
                        get(i+1,j+1,pos+(str1[i] == virus[pos]),i,j,k,1);
                    }
                }
            }
        }
    }
    int x,y,z,ans=INT_MIN;
    FOR(i,0,K-1){
        if(f[N][M][i] > ans){
            ans = f[N][M][i];
            z = i;
        }
    }
    char out[MAXN];DEBUG(ans);
    if(ans <= 0) puts("0");
    else{
        x=N;y=M;
        int len = ans;
        while(pre[x][y][z][0] != -1){
            int xx = pre[x][y][z][0],yy=pre[x][y][z][1],zz=pre[x][y][z][2];
            if(x-xx==1 && y-yy==1 && str1[x-1] == str2[y-1]){
                out[ans--] = str1[x-1];
            }
            x = xx;y = yy;z = zz;
        }
        FOR(i,1,len){
            printf("%c",out[i]);
        }
    }
    // system("sleep 20");
    return 0;
}