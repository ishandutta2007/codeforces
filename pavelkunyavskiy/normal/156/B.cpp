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

const int MAXN = 111000;

int n,m;
int a[MAXN];
int cnt1[MAXN];
int cnt2[MAXN];
bool can[MAXN];

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int cntn = 0;
  scanf("%d %d",&n,&m);

  for (int i = 0;i < n; i++)
    scanf("%d",&a[i]),cntn += (a[i] < 0);

  for (int i = 0; i < n; i++)
    if (a[i] > 0)
        cnt1[a[i]-1]++;

  for (int i = 0; i < n; i++)
    cnt2[i] = cntn;

  for (int i = 0; i < n; i++)
    if (a[i] < 0)
        cnt2[-a[i]-1]--;

  int cntcan = 0;

  for (int i = 0; i < n; i++){
    can[i] = (cnt1[i] + cnt2[i] == m);
    cntcan += can[i];
  }

  for (int i = 0; i < n; i++){
    if (a[i] > 0 && !can[a[i]-1]){
        printf("Lie\n");
        continue;
    }
    if (a[i] > 0){
        if (cntcan == 1)
        {
            printf("Truth\n");
            continue;
        }
        printf("Not defined\n");
        continue;
    }
    if (a[i] < 0 && !can[-a[i]-1]){
       printf("Truth\n");
       continue;
    }
    if (cntcan == 1)
    {
        printf("Lie\n");
        continue;
    }
    printf("Not defined\n");
  }


        



  return 0;
}