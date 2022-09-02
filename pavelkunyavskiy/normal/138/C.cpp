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

const int MAXN = 110000;


int a[MAXN],h[MAXN],l[MAXN],r[MAXN];
pair<int,int> _b[MAXN];
int b[MAXN];
int z[MAXN];
ld tree[MAXN*4];
int n,m;

int lst;

void upd(int v,int l,int r,int L,int R,ld p){
   // if (v == 1)
     //   cerr << L <<" "<<R<<" "<<p <<endl;
    if (R < l || r < L || R < L)
        return;
    if (L <= l && r <= R){
        tree[v] *= p;
        return;
    }
    upd(2*v,l,(l+r)/2,L,R,p);
    upd(2*v+1,(l+r)/2+1,r,L,R,p);        
}


int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    scanf("%d",&m);

    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d",&a[i],&h[i],&l[i],&r[i]);
    for (int i = 0; i < m; i++)
        scanf("%d %d",&_b[i].first,&_b[i].second);

    sort(_b,_b+m);

    for (int i = 0; i < m; i++)
        b[i] = _b[i].first,z[i] = _b[i].second;

    lst = 2;
    for (;lst < m; lst *= 2);

    for (int i = 1; i < 2*lst; i++)
        tree[i] = 1;

    for (int i = 0; i< n; i++){
        upd(1,0,lst-1,lower_bound(b,b+m,a[i]-h[i])-b,lower_bound(b,b+m,a[i])-b-1,(100-l[i])/100.0);
        upd(1,0,lst-1,upper_bound(b,b+m,a[i])-b,upper_bound(b,b+m,a[i]+h[i])-b-1,(100-r[i])/100.0);
    }


    for (int i = 1; i < lst; i++)
        tree[2*i] *= tree[i], tree[2*i+1] *= tree[i];

    ld ans = 0;

    cerr.precision(16);
    //cerr << fixed <<" "<<tree[1] <<" "<<tree[2] <<" "<<tree[3] << endl;
    for (int i = 0; i < m; i++){
      //  cerr << fixed <<tree[i+lst] << endl;
        ans += z[i] * tree[i+lst];
    }

    cout.precision(15);
    cout << fixed << ans << endl;

  return 0;
}