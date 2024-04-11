#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;

int n;
int v[MAXN];
int c[MAXN];

ll best[MAXN];
ll b1,b2;
int c1,c2;

void init(){
    for (int i = 0; i < MAXN; i++)
        best[i] = -(1LL<<60);
    b1 = 0;
    c1 = -1;
    b2 = -(1LL<<60);
    c2 = -1;
}

void upd(ll b,int c){
//  cerr <<"!"<<b<<" "<<c<<endl;
    if (best[c] >= b)
        return;
    best[c] = b;
    if (c == c1) {
        b1 = b;
        return;
    }
    if (b > b1){
        swap(b,b1);
        swap(c,c1);
    }
    if (b > b2){
        b2 = b;
        c2 = c;
    }
}

ll getnotx(int x){
    if (c1 != x) return b1;
    return b2;
}

ll solve(ll a,ll b){
    init();
    for (int i = 0; i < n; i++){
        ll temp = best[c[i]] + a * v[i];
        ll temp2 = getnotx(c[i]) + b * v[i];                                             
        upd(max(temp,temp2),c[i]);
    //  cerr << c[i] <<"    "<<temp << " "<<temp2 << "        "<<b1 <<" "<<c1 <<" "<<b2 <<" "<<c2<<endl;
    }
    return b1;
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int q;
    scanf("%d %d",&n,&q);
    for (int i = 0; i < n; i++)
        scanf("%d ",&v[i]);
    for (int i = 0; i < n; i++)
        scanf("%d ",&c[i]);

    for (int i = 0; i < q; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        printf(LLD"\n",solve(a,b));
    }
      
  return 0;
}