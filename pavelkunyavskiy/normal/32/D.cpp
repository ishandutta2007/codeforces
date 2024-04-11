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

int n,m,k;
bool a[300][300];


int main()
{
  #ifndef ONLINE_JUDGE
    ld start=clock();
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
        char c;
        scanf(" %c ",&c);
        a[i][j]=(c=='*');
    }   
    for (int r=1;r<=300;r++)
        for (int i=r;i+r<n;i++)
            for (int j=r;j+r<m;j++)
                if (a[i][j] && a[i-r][j] && a[i+r][j] && a[i][j-r] && a[i][j+r]){
                    --k;
                    if (k==0){
                        printf("%d %d\n",i+1,j+1);
                        printf("%d %d\n",i-r+1,j+1);
                        printf("%d %d\n",i+r+1,j+1);
                        printf("%d %d\n",i+1,j-r+1);
                        printf("%d %d\n",i+1,j+r+1);
                        #ifndef ONLINE_JUDGE
                          cerr<<(clock()-start)/CLOCKS_PER_SEC<<endl;
                        #endif
                        return 0;
                    }
                }
    printf("-1\n");
  #ifndef ONLINE_JUDGE
    cerr<<(clock()-start)/CLOCKS_PER_SEC<<endl;
  #endif
    return 0;
}