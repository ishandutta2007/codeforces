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

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;

int h,w,k;

const int MAXN = 1100;


bool up[MAXN][MAXN];
bool lft[MAXN][MAXN];
bool tmpup[MAXN][MAXN];
bool tmplft[MAXN][MAXN];
int ans[MAXN][MAXN];
int tmpans[MAXN][MAXN];



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d %d %d",&h,&w,&k);

    for (int i = 0;  i < h; i++){
        for (int j = 1; j < w; j++){
            char c;
            scanf(" %c",&c);
            lft[i][j] = (c == 'N');
        }
        if (i != h-1){
            for (int j = 0; j < w; j++){
                char c;
                scanf(" %c",&c);
                up[i+1][j] = (c == 'N');
            }       
        }
    }

    bool inv = false;

    if (k == 1){
        int cnt,cnteq;
        cnt = cnteq = 0;
        for (int i = 0; i < h; i++)
            for (int j = 1; j < w; j++)
                cnt++, cnteq += !lft[i][j];
        for (int i = 1; i < h; i++)
            for (int j = 0; j < w; j++)
                cnt++, cnteq += !up[i][j];

        if (3 * cnt <= 4 * cnteq){
            printf("YES\n");
            for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                    printf("1%c"," \n"[j==w-1]);
            return 0;
        }       
        printf("NO\n");
        return 0;
    }

    if (h > w){   
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                tmplft[j][i] = up[i][j], tmpup[j][i] = lft[i][j];
        swap(w,h);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                up[i][j] = tmpup[i][j], lft[i][j] = tmplft[i][j];
        inv = true;
    }

    
    ans[0][0] = 0;

    for (int i = 1; i < w; i++)      
        ans[0][i] = ans[0][i-1] ^ lft[0][i]; 

    /*for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            eprintf("%d%c",lft[i][j]," \n"[j==w-1]);
    eprintf("\n\n");
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            eprintf("%d%c",up[i][j]," \n"[j==w-1]); */


    for (int i = 1; i < h; i++){
        for (int j = 0; j < w; j++){
            if (!j || (j == w-1) || ((ans[i][j-1] ^ lft[i][j]) == (ans[i-1][j] ^ up[i][j]))){
                ans[i][j] = ans[i-1][j] ^ up[i][j];
            } else {
                ans[i][j+1] = ans[i-1][j+1] ^ up[i][j+1];
                ans[i][j]   = ans[i][j+1] ^ lft[i][j+1];
                j++;
            }
        }
    }

    if (inv) {
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                tmpans[j][i] = ans[i][j];
        swap(w,h);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                ans[i][j] = tmpans[i][j];
    }

    printf("YES\n");
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            printf("%d%c",ans[i][j]+1," \n"[j==w-1]);
                   





      
    TIMESTAMP(end);
    return 0;
}