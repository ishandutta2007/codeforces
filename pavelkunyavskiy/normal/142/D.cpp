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


int sum[100];
int n,m,k;

void add(int a){
   for (int i = 0; i < 10; i++)
        if (a & (1<<i))
            sum[i]++,sum[i] %= (k+1);

}

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d %d",&n,&m,&k);

    bool d1,d2;
    d1 = d2 = false;
    for (int i = 0; i < n; i++){
        int pos1,pos2;
        int cnt1,cnt2;
        cnt1 = cnt2 = 0;
        pos1 = pos2 = -1;
        for (int j = 0; j < m; j++){
            char c;
            scanf(" %c ",&c);
            if (c == 'G'){
               pos1 = j; 
               cnt1++;
            }
            else if (c == 'R'){
                pos2 = j;
                cnt2++;
            }
        }
       // cerr << pos1 <<" "<<pos2 << endl;
        if (pos1 == -1 && pos2 == -1)
            continue;
        if (pos1 == -1 && cnt2 != m)
            d2 = 1;
        else if (pos2 == -1 && cnt1 != m)
            d1 = 1;
        else {
            if (pos1 != -1 && pos2 != -1)
                add(abs(pos1-pos2)-1);
        }
    }


    if (d1 && !d2){
        printf("First\n");
        return 0;
    }

    if (d2 && !d1){
        printf("Second\n");
        return 0;
    }
    if (d1 && d2){
        printf("Draw\n");
        return 0;
    }


    for (int i = 0; i < 10; i++)
        if (sum[i]){
            printf("First\n");
            return 0;
        }
    printf("Second\n");
    return 0;
}