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

bool isgl(char c){
    if (c>='a' && c<='z')
        c=c-'a'+'A';        
    if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y')
        return true;
    return false;
}

const string answers[2]={"NO\n","YES\n"};

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  bool q=false;
  for (char c;cin>>c;){
    if (('a'<=c && c<='z') || ('A'<=c && c<='Z'))
        q=isgl(c);
  }
  cout<<answers[q];

  return 0;
}