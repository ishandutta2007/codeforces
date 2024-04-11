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

char s[210000];
char t[210000];

int dp1[210000];
int dp2[210000];


int last[26];

void calcdp(char* s,char* t,int* dp){
    memset(last,-1,sizeof(last));

    int ptr = 0;
    for (int i = 0; s[i]; i++){
        if (s[i] == t[ptr]){
            last[s[i]-'a'] = ptr;
            ptr++;
        }
        dp[i] = last[s[i]-'a']+1;
    }

}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  gets(s);
  gets(t);

  int len = strlen(s);
  int lent = strlen(t);

  calcdp(s,t,dp1);

  reverse(s,s+len);
  reverse(t,t+lent);
  calcdp(s,t,dp2);

  reverse(dp2,dp2+len);

  //for (int i = 0; i < len; i++)
  //  cerr << dp1[i] <<" "<<dp2[i] << endl;

  for (int i = 0; i < len; i++)
    if (dp1[i] + dp2[i] <= lent){
        printf("No\n");
        return 0;
    }
  printf("Yes\n");      
  return 0;
}