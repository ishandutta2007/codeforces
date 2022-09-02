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

const int MAXN = 310000;

int n;
vector<int> g[MAXN];
int cnt[MAXN];

char ans[MAXN];
bool inq[MAXN];

queue<int> q;

void change(int id){        
    for (int i = 0; i < (int)g[id].size(); i++)
        if (ans[g[id][i]] == ans[id])
            cnt[g[id][i]]--;
    ans[id] ^= 1;
    cnt[id] = 0;    
    for (int i = 0; i < (int)g[id].size(); i++)
        if (ans[g[id][i]] == ans[id]){
            cnt[g[id][i]]++;
            cnt[id]++;
            if (cnt[g[id][i]] >= 2 && !inq[g[id][i]])
                q.push(g[id][i]),inq[g[id][i]] = true;
        }
    assert(cnt[id] <= 1);       
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif


    memset(g,-1,sizeof(g));
    int m;
    scanf("%d %d",&n,&m);

    for (int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for (int i = 0; i < n; i++){
        ans[i] = '0';
        q.push(i);
        cnt[i] = g[i].size();
        inq[i] = true;
    }

    while (!q.empty()){
        int v = q.front();
        q.pop();
        inq[v] = false;
        if (cnt[v] >= 2)
            change(v);
    }

    ans[n] = 0;
    puts(ans);
    return 0;
}