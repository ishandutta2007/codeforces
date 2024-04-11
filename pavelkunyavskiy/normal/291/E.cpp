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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "E"

typedef long long ll;
typedef long double ld;

const int MAXN = 311000;

char buf[MAXN];

string t;                   

vector<int> g[MAXN];
vector<string> gs[MAXN];
int n;

int p[MAXN];
int ans;

int next[MAXN][26];



void dfs(int v,int pos){
    for (int i = 0; i < (int)g[v].size(); i++){
        int pos2 = pos;
        for (int j = 0; j < (int)gs[v][i].size(); j++){
            pos2 = next[pos2][gs[v][i][j]-'a'];
            if (pos2 == (int)t.size()-1)
                ans++;
        }
        dfs(g[v][i],pos2);          
    }
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    
    scanf("%d",&n);
    for (int i = 1; i < n; i++){
        int a;
        scanf("%d %s",&a,buf);
        g[a-1].pb(i);
        gs[a-1].pb(buf);
    }

    scanf("%s",buf);
    t = buf;
    t += '$';

    p[0] = 0;
    for (int i = 1; i < (int)t.size(); i++){
        int j = p[i-1];
        while (j && t[i] != t[j]) j = p[j-1];
        if (t[i] == t[j]) j++;
        p[i] = j;   
    }

    for (int i = 0; i < (int)t.size(); i++)
        for (int j = 0; j < 26; j++)
            if (t[i] == 'a' + j)
                next[i][j] = i+1;
            else
                next[i][j] = (i?next[p[i-1]][j]:0);


    dfs(0,0);
    printf("%d\n",ans);
      
    TIMESTAMP(end);
    return 0;
}