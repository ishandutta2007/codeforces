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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;

int a[55];

int d[55][55][2];
int cnt[55][55][2];
int c[55][55];

const int MOD = 1000000007;

void ADD(int& a,int b){
    if ((a += b) >= MOD) a -= MOD;
}

queue<int> qx,qy,qs;


void update(int x,int y,int side,int dst,int ccnt){
    if (d[x][y][side] > dst){
        d[x][y][side] = dst;
        cnt[x][y][side] = 0;
        qx.push(x);
        qy.push(y);
        qs.push(side);
    }
    if (d[x][y][side] == dst)
        ADD(cnt[x][y][side],ccnt);
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n,k;
    scanf("%d %d",&n,&k);k /= 50;
    int cnt1 = 0,cnt2 = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]), a[i] /= 50;
        if (a[i] == 1) cnt1++;
        else if (a[i] == 2) cnt2++;
        else assert(false);
    }

                          

    c[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++){
            if (i) ADD(c[i][j],c[i-1][j]);
            if (i && j) ADD(c[i][j],c[i-1][j-1]);
        }

    memset(d,0x3f,sizeof(d));
    memset(cnt,-1,sizeof(cnt));

    d[cnt1][cnt2][0] = 0;
    cnt[cnt1][cnt2][0] = 1;
    qx.push(cnt1);
    qy.push(cnt2);
    qs.push(0);  
                                       

    while (!qx.empty()){
        int x = qx.front();qx.pop();
        int y = qy.front();qy.pop();
        int s = qs.front();qs.pop();

        //eprintf("%d %d %d    %d\n",x,y,s,d[x][y][s]);

        if (s == 1){
            for (int i = 0; i <= cnt1 - x; i++)
                for (int j = 0; j <= cnt2 - y; j++)
                    if (i + j > 0 && i + 2*j <= k)
                        update(x+i,y+j,0,d[x][y][s]+1, (((cnt[x][y][s] * 1LL * c[cnt1-x][i]) % MOD) * 1LL * c[cnt2-y][j]) % MOD);
        } else {
            for (int i = 0; i <= x; i++)
                for (int j = 0; j <= y; j++)
                    if (i + j > 0 && i + 2*j <= k)
                        update(x-i,y-j,1,d[x][y][s]+1, (((cnt[x][y][s] * 1LL * c[x][i]) % MOD) * 1LL * c[y][j]) % MOD);
        }
    }

    if (d[0][0][1] >= 10000000)
        printf("-1\n0\n");
    else
        printf("%d\n%d\n",d[0][0][1],cnt[0][0][1]); 
      
    TIMESTAMP(end);
    return 0;
}