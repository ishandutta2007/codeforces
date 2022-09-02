//#include <iostream>
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
#include <sstream>
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

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;


int g[110000][2];

void add(int a,int b){
    if (g[a][0] == -1) g[a][0] = b;
    else if (g[a][1] == -1) g[a][1] = b;
    else assert(false); 
}

vector<pair<int,int> > ans;
bool used[110000];
int n,m;

void go(int first,int last,int ptr){
    if ((int)ans.size() == m){
        for (int i = 0; i < m; i++)
            printf("%d %d\n",ans[i].first+1,ans[i].second+1);
        exit(0); 
    }
    while (used[ptr]) ptr++;
    for (int i = ptr; i < n; i++)
        if (!used[i]) {
            if (last == -1){
                used[i] = true;
                go(i, i, ptr);              
                used[i] = false;
                continue;
            }
            if (i != g[last][0] && i != g[last][1]){
                used[i] = true;
                ans.push_back(mp(last,i));
                go(first, i, ptr);
                ans.pop_back();
                used[i] = false;
            }
            if (i != g[first][0] && i != g[first][1] && first != last){
                used[i] = true;
                ans.push_back(mp(i,first));
                go(i, last, ptr);
                ans.pop_back();
                used[i] = false;
            }
        }
    if (g[last][0] != first && g[last][1] != first && last != first && ans.back() != mp(first,last)){
        ans.push_back(mp(last, first));
        go(-1,-1,ptr);
        ans.pop_back();
    }
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    scanf("%d %d",&n,&m);
    memset(g,-1,sizeof(g));
    for (int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        add(a,b);
        add(b,a);
    }
    
    go(-1,-1,0);

    printf("-1\n");
      
    TIMESTAMP(end);
    return 0;
}