#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <cassert>

#define mp make_pair
#define pb push_back

#ifdef LOCAL
  #define LLD "%lld"
  #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
  #define LLD "%I64d"
  #define eprintf(...) ;
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

pair<int,int> a[110000];

int ans[110000];

int main(){
  #ifdef LOCAL  
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&a[i].first);
      a[i].second = -i;
    }
    memset(ans,-1,sizeof(ans));
    int best = -1;
    
    sort(a,a+n);
    
    for (int i=0;i<n;){
      int j = i;
      for (;j<n && a[j].first == a[i].first;j++);     
      
      
      for (int k=i;k<j;k++)
    ans[-a[k].second] = best;
    
      for (int k=i;k<j;k++)
    best = max(best,-a[k].second);
      
      i = j;      
      
      //cerr<<ans[0]<<" "<<ans[1]<<" "<<ans[2] <<" "<<ans[3]<<" "<<ans[4]<<endl;
    }
    
    for (int i=0;i<n;i++)
      if (ans[i] < i)
    ans[i] = -1;
      else
    ans[i] = ans[i]-i -1;
    
    for (int i=0;i<n;i++)
      printf("%d ",ans[i]);
    
    printf("\n");
    
     
    return 0;
}