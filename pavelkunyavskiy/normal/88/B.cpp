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
 
 
char s[100][100]; 
int n,m,x; 
 
int val[255]; 
 
int getsmall(char c){ 
    bool q = false; 
    for (int i=0;i<n;i++) 
          for (int j=0;j<m;j++) 
              q |= s[i][j] == c; 
    if (!q) 
        return -1; 
    return 0; 
} 
 
int getbig(char c){ 
    bool q = false; 
    bool q2 = false; 
    c=c-'A'+'a'; 
    for (int i=0;i<n;i++) 
        for (int j=0;j<m;j++) 
            if (s[i][j] == 'S'){ 
                q2 = true; 
                for (int i1=0;i1<n;i1++) 
                    for (int j1=0;j1<m;j1++) 
                        if (s[i1][j1] == c) 
                            if ((i1-i)*(i1-i) + (j1-j) * (j1-j) <= x*x) 
                                q = true; 
            } 
    if (!q2 || val[(int)c] == -1) 
        return -1; 
    if (q) 
        return 0; 
    return 1;     
} 
 
 
int main() 
{ 
  #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
  #endif 
      scanf("%d %d %d",&n,&m,&x); 
      for (int i=0;i<n;i++) 
          for (int j=0;j<m;j++) 
              scanf(" %c ",&s[i][j]); 
 
      for (char i='a';i<='z';i++) 
          val[(int)i] = getsmall(i);     
           
       for (char i='A';i<='Z';i++) 
          val[(int)i] = getbig(i);     
           
      char c; 
      int ans = 0; 
      int sz; 
      scanf("%d",&sz); 
      for (;scanf(" %c ",&c)==1;){ 
          ans += val[(int)c]; 
          if (val[(int)c] == -1){ 
              printf("-1\n"); 
              return 0; 
          } 
      } 
      cout << ans << endl; 
    return 0; 
}