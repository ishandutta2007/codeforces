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

const int MAXN=200000;

int a[MAXN];
int b[MAXN];
int cnt[MAXN];
int n,m,k;

set<int> s;

void add(int val,int dlt){
    int tmp=lower_bound(b,b+m,val)-b;
    if (cnt[tmp] == 1)
        s.erase(tmp);
    cnt[tmp]+=dlt;
    if (cnt[tmp] == 1)
        s.insert(tmp);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    m=unique(b,b+n)-b;
    
    for (int i=0;i<n;i++){
        add(a[i],1);
        if (i >= k-1){
            if (s.empty())
                printf("Nothing\n");
            else
                printf("%d\n",b[*--s.end()]);
            add(a[i-k+1],-1);
        }
    }
    return 0;
}