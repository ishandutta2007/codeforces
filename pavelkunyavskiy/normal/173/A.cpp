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

int cnt[2][3];

char s1[1100];
char s2[1100];

int ans1,ans2;
int n;

int type(char c){
   if (c == 'R')
        return 0;
   else if (c == 'S')
        return 1;
   else if (c == 'P')
        return 2;        
   assert(false);
}

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  gets(s1);
  sscanf(s1,"%d",&n);

  gets(s1);
  gets(s2);

  int l1 = strlen(s1);
  int l2 = strlen(s2);

  for (int i = 0; i < (l1*l2); i++){
    int t1 = type(s1[i % l1]);
    int t2 = type(s2[i % l2]);
    //cerr <<t1 <<" "<<t2<<endl;
    if ((t1+1)%3 == t2)
        ans1++;
    if ((t2+1)%3 == t1)
        ans2++;
  }


  ans1 *=  (n/(l1*l2));
  ans2 *= (n/(l1*l2));
  n %= l1*l2;

  for (int i = 0; i < n; i++){
    int t1 = type(s1[i % l1]);
    int t2 = type(s2[i % l2]);
    //cerr <<t1 <<" "<<t2<<endl;
    if ((t1+1)%3 == t2)
        ans1++;
    if ((t2+1)%3 == t1)
        ans2++;
  }

  printf("%d %d\n",ans2,ans1);
  return 0;
}