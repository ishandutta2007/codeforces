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


ll f[15];

int ans;

void gen(ll cur,ll x){
    if (cur >= x)
        return;
    if (cur && cur < x)
        ans++;
    gen(10*cur+4,x);
    gen(10*cur+7,x);
}


int a[15];   
bool used[15];


bool luck(ll x){
    //cerr << x << endl;
    for (;x;x/=10)
        if (x %10 != 4 && x % 10 != 7)
            return false;
    return true;    
}


void genkth(int n,int k){
    for (int i = 0; i < n; i++){
        ll temp = f[n-i-1];
        int pos = k/temp+1;
        k %= temp;
        int j;
        for (j = 0;pos; j++)
            if (!used[j])
                --pos;
        a[i] = j-1;
//      cerr << a[i] <<" ";
        used[j-1] = true;
    }
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  f[0] = 1;
  for (int i = 1; i < 15; i++)
    f[i]= f[i-1]*i;

  int n,k;
  cin >> n >> k;
  if (n < 15 && f[n] < k){
    printf("-1\n");
    return 0;
  }

  int y = min(n,13);

  genkth(y,k-1);


  int x = n - y + 1;
  ans = 0;

  gen(0,x);

  for (int i = 0; i < y; i++){
    //cerr << a[i] <<" "<<i+x <<" "<<a[i]+x << endl;
    if (luck(i+x) && luck(a[i]+x))          
        ans++;
  }
  

  cout << ans << endl;  

  return 0;
}