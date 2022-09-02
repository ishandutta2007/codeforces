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

const int MAXN = 310;


int a[MAXN][MAXN];
int b[MAXN];
int n;


int temp[MAXN];

void inverse(int* a){
    for (int i = 0; i < n; i++)
        temp[a[i]] = i;
    for (int i = 0; i < n; i++)
        a[i] = temp[i];
}






int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            scanf("%d",&a[i][j]),--a[i][j];
        inverse(a[i]);
    }

    for (int i = 0; i < n; i++)
        scanf("%d",&b[i]),--b[i];

    inverse(b);


    for (int i = 0; i < n; i++){
        int bt = -1,bv = -1;

        int curv = -1;

        for (int j = 0; j < n; j++){
            if (j == i)
                continue;
            if (curv == -1 || b[curv] > b[j])
                curv = j;
            if (bv == -1 || a[i][bv] > a[i][curv])
                bv = curv, bt = j;
           // cerr << i <<" "<< j <<" "<<bv <<" "<<bt<<" "<<curv << endl;
        }
//        cerr << endl;


        printf("%d ",bt+1);
    }



  return 0;
}