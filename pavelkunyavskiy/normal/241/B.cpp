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


const int MAXN = 51000;

int a[MAXN];
int n;                
ll ans = 0;

int sum[MAXN][30];

ll count(int first,int cnt){    
   if (cnt < 0)
    return 0;
   assert(!(first & ((1<<cnt)-1)));
   ll ans = 0;
   int eds = (1<<cnt)-1;
   for (int i = 0; i < n; i++)
      ans += upper_bound(a,a+n,(a[i] | eds)^first) - lower_bound(a,a+n,(a[i] & ~eds)^first); 
   return ans - (first?0:n);
}

void addall(int first,int cnt){
   if (cnt < 0) return;
   assert(!(first & ((1<<cnt)-1)));
   //cerr <<"!!!!!!!!!!!"<<ans << endl;
   int eds = (1<<cnt)-1;
   for (int i = 0; i < n; i++){
      int r = upper_bound(a,a+n,(a[i] | eds)^first) - a;
      int l = lower_bound(a,a+n,(a[i] & ~eds)^first) - a;
      //if (cnt == 2)
      //  cerr << i <<" "<<l <<" "<<r<<" "<<first <<endl;
      if (r - l > !first){
        for (int j = 0; j < cnt; j++){
          //if (cnt == 2)
          //  cerr <<"!!!"<<i<<" "<<j <<" "<<(a[i] & (1<<j)) <<" "<<sum[r][j] - sum[l][j] << " "<<r-l<<endl;
          ans += (1LL<<j) * ((a[i] & (1<<j))?(r - l - (sum[r][j] - sum[l][j])):(sum[r][j] - sum[l][j]));
          //if (cnt == 2)
          //cerr <<"??"<<ans<<endl;
        }
      }
   } 
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


   ll m;

   scanf("%d",&n);
   cin >> m;
   m *= 2;
   for (int i = 0; i < n; i++)
      scanf("%d",&a[i]);
   sort(a,a+n);


   for (int i = 0; i < n; i++)
    for (int j = 0; j < 30; j++)
        sum[i+1][j] = sum[i][j] + !!(a[i] & (1<<j));

  // cerr << sum[3][0] - sum[2][0] << endl;
                                         
   int mask = 0;

   for (int i = 30; i >= 0; i--){
       ll cnt = count(mask|(1<<i),i);
       //cerr << i <<" "<<cnt << " "<<ans<<endl;
       ans += min(m,cnt) * (1LL<<i);          
       if (cnt >= m){
         mask |= (1<<i);     
       }
       else {
         //cerr <<"!!!"<<endl;
         addall(mask|(1<<i),i);
         m -= cnt;
       }
   } 

   cout << (ans/2)%1000000007  << endl;      
   return 0;
}