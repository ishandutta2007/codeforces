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


const int MAXN = 111000;

int p[MAXN];
int sz[MAXN];

int cnt;

int root(int a){
    if (p[a] == a)
        return a;
    return p[a] = root(p[a]);
}

void join(int a,int b){
    a = root(a);
    b = root(b);
    if (a == b)
        return;
    --cnt;
    p[a] = b;
    sz[b] += sz[a];
}
int n,m,k;

int pow(int a,int b,int mod){
    if (!b)
        return 1%mod;
    if (b & 1)
        return (pow(a,b-1,mod)*1LL*a)%mod;
    int temp = pow(a,b>>1,mod);
    return (temp * 1LL * temp) % mod;
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d %d",&n,&m,&k);

    for (int i = 0; i < n; i++)
        p[i] = i, sz[i] = 1;

    cnt = n-2;

    for (int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        join(a,b);
    }

    if (cnt == -1){
        printf("%d",1%k);
        return 0;
    }


    int ans = pow(n,cnt,k);

    for (int i = 0; i < n; i++)
        if (p[i] == i)
            ans = (ans *1LL* sz[i])%k;

    cout << ans%k << endl;
    return 0;
}