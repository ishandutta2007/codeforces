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

const int MAXN = 85;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

int a[MAXN][MAXN];
int n,m;

int encode(int i,int j){
    return i*m+j+1;
}    

int to[MAXN*MAXN*10];
int c[MAXN*MAXN*10];
int w[MAXN*MAXN*10];
int next[MAXN*MAXN*10];
int head[MAXN*MAXN+2];
int eptr;

int good(int x,int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

void addedge(int a,int b,int _w){
    to[eptr] = b;
    c[eptr] = 1;
    w[eptr] = _w;
    next[eptr] = head[a];
    head[a] = eptr++;

    to[eptr] = a;
    c[eptr] = 0;
    w[eptr] = -_w;
    next[eptr] = head[b];
    head[b] = eptr++;
}

int d[MAXN*MAXN+2];
int p[MAXN*MAXN+2];
bool inq[MAXN*MAXN+2];

int update(int v){
    if (v == 0) return 0;
    int temp = update(to[p[v]^1]);
    temp += w[p[v]];
    c[p[v]] = 0;
    c[p[v]^1] = 1;
    return temp;
}

int iter(){
    for (int i = 0; i < n; i++)
        d[i] = 1<<30,inq[i] = false;
    d[0] = 0;
    queue<int> q;
    q.push(0);
    inq[0] = true;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        inq[v] = false;
        for (int id = head[v]; id != -1; id = next[id]){
            if (c[id] == 0) continue;
            if (d[to[id]] > d[v] + w[id]){
                d[to[id]] = d[v] + w[id];
                p[to[id]] = id;
                if (!inq[to[id]]){
                    inq[to[id]] = true;
                    q.push(to[id]);
                }
            }
        }
    }
    return update(n-1);
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d",&a[i][j]);

    int ans = 0;

    memset(head,-1,sizeof(head));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if ((i + j) % 2 == 0){
                addedge(0,encode(i,j),0);
                for (int k = 0; k < 4; k++)
                    if (good(i+dx[k],j+dy[k]))
                        addedge(encode(i,j),encode(i+dx[k],j+dy[k]),a[i][j] != a[i+dx[k]][j+dy[k]]);
            } else {
                addedge(encode(i,j),n*m+1,0);
            }
        }

    int cnt = n*m/2;
    n = n*m+2;
    

    for (int i = 0; i < cnt; i++)
        ans += iter();

    printf("%d\n",ans);
          
    TIMESTAMP(end);
    return 0;
}