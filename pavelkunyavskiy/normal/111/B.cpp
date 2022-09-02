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

typedef long long int64;
typedef long double ld;

int last[110000];


void update(int x,int y,int id){
    int ans = 0;

    for (int i = 1; i*i <= x; i++){
        if (x%i) continue;
        ans += (last[i] < id-y);
        last[i] = id;
        ans += (last[x/i] < id-y);
        last[x/i] = id;
    }

    printf("%d\n",ans);
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        update(x,y,i+1);
    }
    return 0;
}