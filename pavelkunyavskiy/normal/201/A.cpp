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


int insq(int temp){
    if (temp % 2 == 0)
        return temp*temp/2;
    return (temp*temp+1)/2;
}

bool check(int i,int x){
    if (i == 3){
        return x == 1 || x == 2 || x == 4 || x == 5;
    }
    if (i % 2 == 0){
        if (x % 4 != 0)
            return 0;
        int temp = i/2-1;
        return 4*insq(temp) >= x;
    }
    int val = insq(i);
    return val >= x;               
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int x;
  cin >> x;

  for (int i = 1;;i++){
    if (check(i,x)){
        printf("%d\n",i);
        return 0;
    }
  }

      
  return 0;
}