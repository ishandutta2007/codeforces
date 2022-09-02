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

typedef long long int64;
typedef long double ld;


int add[10];

int np[110000],nppt;
queue<pair<int64,int64> > q[3],w[3];



int64 curt;

int k[3],t[3];
int n;
int64 come[110000];

int64 ans = 0;

void push(){
//  cerr<<curt<<endl;
    while (nppt < n && come[nppt] <= curt){     
        w[0].push(mp(curt,curt));
        nppt++;
    }
    while (!q[0].empty() && q[0].front().first <= curt){
        w[1].push(mp(curt,q[0].front().second));
        q[0].pop();
    }
    while (!w[0].empty() && q[0].size() < k[0]){
        q[0].push(mp(curt+t[0],w[0].front().second));
        w[0].pop();
    }
    
    while (!q[1].empty() && q[1].front().first <= curt){
        w[2].push(mp(curt,q[1].front().second));
        q[1].pop();
    }
    while (!w[1].empty() && q[1].size() < k[1]){
        q[1].push(mp(curt+t[1],w[1].front().second));
        w[1].pop();
    }
    
    while (!q[2].empty() && q[2].front().first <= curt){
        ans = max(ans,curt-q[2].front().second);
        q[2].pop();
    }
    while (!w[2].empty() && q[2].size() < k[2]){
        q[2].push(mp(curt+t[2],w[2].front().second));
        w[2].pop();
    }
}

bool next(){    
    int64 nexttime = 1LL<<60LL;
    if (nppt != n)
        nexttime = min(nexttime,come[nppt]);
    for (int i=0;i<3;i++)
        if (!q[i].empty())
            nexttime = min(nexttime,q[i].front().first);
    if (nexttime <= curt || (nexttime == (1LL<<60LL)))
        return false;
    curt = nexttime;
    push();
    return true;
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>k[0]>>k[1]>>k[2];
    cin>>t[0]>>t[1]>>t[2];
    cin>>n;
    for (int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        come[i] = tmp;
    }
    sort(come,come+n);
    for (;next(););
    cout << ans << endl;
    return 0;
}