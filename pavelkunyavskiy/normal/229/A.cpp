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

char s[11000];

int val1[11000];
int val2[11000];


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  int n,m;
  gets(s);
  sscanf(s,"%d %d",&n,&m);
                          
  for (int i = 0; i < n; i++){
    gets(s);
    memset(val1,1,sizeof(val1));

    if (find(s,s+m,'1') == s+m){
        printf("-1\n");
        return 0;
    }                    

    int last = -1;
    for (int _j = 0; _j < 2*m; _j++){
        int j = _j % m;
        if (s[j] == '1')
            last = _j;
        if (last != -1)
            val1[j] = min(val1[j], _j - last);
    }

    reverse(s,s+m);
    last = -1;

    for (int _j = 0; _j < 2*m; _j++){
        int j = _j % m;
        if (s[j] == '1')
            last = _j;
        if (last != -1)
            val1[m-j-1] = min(val1[m-j-1], _j - last);
    }

    for (int j = 0; j < m; j++){
       // cerr << val1[j] <<" ";
        val2[j] += val1[j]; 
    }
    //cerr << endl;
  }
  

  printf("%d\n",*min_element(val2,val2+m));
      
  return 0;
}