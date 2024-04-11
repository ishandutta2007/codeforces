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

const ll inf = (1LL<<60);

const int MAXN = 1100000;


int a[MAXN];
int b[MAXN];

int n,m;

struct myst{
    vector<pair<ll,ll> > v;

    myst(){
        v.pb(mp(inf,inf));
    }

    bool empty(){
        return (int)v.size() == 1;
    }

    void push(ll x){
        v.pb(mp(x,min(x,v.back().second)));
    }

    ll pop(){
        ll temp = v.back().first;
        v.pop_back();
        return temp;
    }

    ll val(){
        return v.back().second;
    }    

    void clear(){
        v.resize(1);
    }

    int size(){
        return (int)v.size()-1;
    }
};

struct myqu{
    myst a,b;

    myqu():a(),b(){
    }

    void push(ll x){
        a.push(x);
    }

    void pop(){
        if (b.empty()){
            while (!a.empty())
                b.push(a.pop());                
        }
        b.pop();
    }

    ll val(){
        return min(a.val(),b.val());
    }

    void clear(){
        a.clear();
        b.clear();
    }
    
    int size(){
        return a.size()+b.size();
    }
};

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&n,&m);
    memset(a,-1,sizeof(a));
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d",&t);
        a[t] = i;
    }
    memset(b,-1,sizeof(b));
    for (int i = 0; i < m; i++){
        int t;
        scanf("%d",&t);
        if (a[t] != -1)
            b[a[t]] = i;
    }


    int ans = 0;

    ll cur = 0;

    myqu q;

    for (int R = 0;R < 2*n; R++){
        int r = R % n;
        if (b[r] == -1){
            q.clear();
            continue;
        }
        
        ll cur1 = b[r] + ((cur - b[r])/m)*1LL*m;
        while (cur1 <= cur)
            cur1+=m;

        q.push(cur1);

        cur = cur1;

//        cerr << cur << endl;

        while (cur  - q.val() >= m)
            q.pop();

        ans = max(ans,q.size());
    }

    printf("%d\n",ans);
    return 0;
}