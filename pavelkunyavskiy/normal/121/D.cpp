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
const int MAXM = 610000;

const ll INF = 1000000000000000001LL;

ll k;
int n;
int m;
ll l[MAXN];
ll r[MAXN];

vector<ll> luck;

void gen(ll cur){
    if (cur > INF)
        return;
    if (cur)
        luck.pb(cur);
    gen(10*cur+4);
    gen(10*cur+7);
}

ll res[MAXM];

ll minlen;


void add(ll& a,ll b){
    a += b;
    a = min(a,INF);
}

void mult(ll& a,ll b){
    if (a < INF/b)
        a *= b;
    else
        a = INF;
}

bool check(int mid){
    memset(res,0,sizeof(res));

    ll cur = 0;
    int ptr = 0;

    for (int i = 0; i +mid <= m; i++){
        ll temp = ptr;
        if (temp)
            mult(temp,luck[i+mid-1] - luck[i+mid-2]);
        add(cur,temp);
        while (ptr < n && r[ptr] < luck[i+mid-1]){
            add(cur,luck[i+mid-1] - r[ptr]);
            ++ptr;
        }
        res[i] = cur;
    }

    cur = 0;
    ptr = 0;

    //cerr <<luck[6] <<" "<< res[6] << endl;

    for (int i = m-mid; i >= 0; --i){
        ll temp = ptr;
        if (temp)
            mult(temp,luck[i+1] - luck[i]);     
        add(cur,temp);
        while (ptr < n && l[ptr] > luck[i]){
        //  cerr << l[ptr] - luck[i] <<" "<<l[ptr] <<" "<<luck[i] << endl;
            add(cur,l[ptr] - luck[i]);
            ++ptr;
        }
        add(res[i],cur);
    }

//  cerr << res[6] << endl;

    for (int i = 0; i+mid <= m; i++){
        if (luck[i+mid-1] - luck[i] <= minlen && res[i] <= k){
//          cerr <<"conver "<<mid <<" "<<luck[i] <<" "<<res[i] << endl;
            return true;
        }
    }
        
    return false;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  minlen = INF;

  gen(0);
  sort(luck.begin(),luck.end());
  m = luck.size();

  scanf("%d",&n);
  scanf("%I64d",&k);
  for (int i = 0; i < n; i++){
    scanf("%I64d %I64d",&l[i],&r[i]);
    minlen = min(minlen,r[i] - l[i]);
  }


  sort(l,l+n);
  reverse(l,l+n);
  sort(r,r+n);

  int lf = 0;
  int rg = luck.size()+1;

 // cerr << luck.size() << endl;

  while (rg-lf > 1){
    int mid = (lf+rg)/2;
    if (check(mid))
        lf = mid;
    else
        rg = mid;
  }

  cout << lf << endl;
  return 0;
}