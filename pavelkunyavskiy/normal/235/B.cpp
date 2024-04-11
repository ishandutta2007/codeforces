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

#ifdef LOCAL
double prob[100000];
double locans;
#endif

void init(){
#ifdef LOCAL
   prob[0] = 1.0;
   locans = 0;
#endif
}

void next(int n,double p){
#ifdef LOCAL
    for (int i = n; i>= 0; i--){
        locans += i*i*prob[i] * (1.0-p);
        prob[i+1] = prob[i] * p;
    }
    prob[0] = 1.0-p;
#endif
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  double a,b,c;
  int n;
  scanf("%d",&n);
  double ans = 0;

  init();

  a = b = 0;
  c = 1;

  for (int i = 0;i < n; i++){
    double p;            
    scanf("%lf",&p);
    ans += a * (1.0 - p);
    next(i,p);
    a = p*(a + 2*b + c);
    b = p*(b+c);
    c = 1.0;
    //cerr << a <<" "<<b <<" "<<c<<endl;
    #ifdef LOCAL
       assert(fabs(ans - locans) < 1e-9);
    #endif
  }
  ans += a;

  cout.precision(15);
  cout << fixed << ans << endl;

      
  return 0;
}