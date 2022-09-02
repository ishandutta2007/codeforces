#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;


queue<int> qx,qy;

int d[2][110000];

char s[2][110000];
int n,k;

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    gets(s[0]);
    sscanf(s[0],"%d %d",&n,&k);
    gets(s[0]);
    gets(s[1]);

    memset(d,63,sizeof(d));

    d[0][0] = 0;
    qx.push(0);
    qy.push(0);

    for (;qx.size();){
        int x = qx.front();
        int y = qy.front();
        qx.pop();qy.pop();

        if (d[y][x] > x)
            continue;



        if (x + k >= n){
            printf("YES\n");
            return 0;
        }

        if (s[y][x+1] == '-'){
            if (d[y][x+1] > d[y][x] + 1){
                d[y][x+1] = d[y][x] + 1;
                qx.push(x+1);
                qy.push(y);
            }    
        }


        if (x > 0 && s[y][x-1] == '-'){
            if (d[y][x-1] > d[y][x] + 1){
                d[y][x-1] = d[y][x] + 1;
                qx.push(x-1);
                qy.push(y);
            }    
        }


        if (s[y^1][x+k] == '-'){
            if (d[y^1][x+k] > d[y][x] + 1){
                d[y^1][x+k] = d[y][x] + 1;
                qx.push(x+k);
                qy.push(y^1);
            }    
        }
                 

    }

    printf("NO\n");


      
    return 0;
}