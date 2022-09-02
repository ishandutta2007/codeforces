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

const int MOD = 1000000007;

int n;


vector<int> multiply(const vector<int>& a,const vector<int>& b){
    vector<int> res(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; i+j < n; j++)
            res[i+j] = (res[i+j] + a[i] * 1LL * b[j]) % MOD;

    return res;
}

vector<int> pow(vector<int> a,int st){
    vector<int> res(n,0);
    res[0] = 1;

    for (int i = 0; (1<<i) <= st; i++){
        if (st & (1<<i))
            res = multiply(res,a);
        a = multiply(a,a);
    }

    return res;    
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d",&n);
    int k;
    scanf("%d",&k);

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]), b[i] = 1;

    b = pow(b,k);

    a = multiply(a,b);

    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
      
  return 0;
}