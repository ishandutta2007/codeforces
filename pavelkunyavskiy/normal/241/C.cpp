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


int h1,h2;
int n;

int l[110];
int r[110];
bool side[110];
int score[110];

bool hit[110];

int calc(int x){
    memset(hit,0,sizeof(hit));

    int dx = 100000;
    int dy = 100*x + ((x&1)?(100-h2):h2) - h1;

    int ans = 0;

    for (int i = 1; i <= x; i++){
       bool any = false;
       int cdy = 100*i - h1;
       for (int j = 0; j < n; j++)
          if (side[j] == (i&1))
            if (l[j] * 1LL * dy <= dx *1LL * cdy && dx *1LL * cdy <= r[j] *1LL * dy){
                if (hit[j])
                    return 0;
                any = true;
                hit[j] = true;
                ans += score[j];
            }
       if (!any)
         return 0;               
    }
    return ans;
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int ans = 0;
  scanf("%d %d %d",&h1,&h2,&n);

  for (int i = 0; i < n; i++){
    char c;
    scanf("%d %c %d %d",&score[i],&c,&l[i],&r[i]);
    side[i] = c == 'T';
  }

  for (int i = 1; i <= 200; i++){
      int t = calc(i);
      ans = max(ans,t);
      //if (t) cerr << i <<" "<<t<<endl;       
  }

  h1 = 100 - h1;
  h2 = 100 - h2;
  for (int i = 0; i < n; i++)
    side[i] ^= 1;


  for (int i = 1; i <= 200; i++){
      int t = calc(i);
      ans = max(ans,t);
      //if (t) cerr << -i <<" "<<t<<endl;       
  }


  
  cout << ans << endl;

      
  return 0;
}