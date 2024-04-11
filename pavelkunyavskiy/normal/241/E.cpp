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

const int MAXN = 5100;

int n,m;

namespace fb{
    int a[MAXN*2];
    int b[MAXN*2];
    int w[MAXN*2];
    int ptr;
    int d[MAXN];
    int d2[MAXN];

    void add(int a,int b,int w){
        fb::a[ptr] = a;
        fb::b[ptr] = b;
        fb::w[ptr] = w;
        ptr++;
    }

    void fordbelman(){
        memset(d,63,sizeof(d));
        d[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < ptr;j++)
                d[b[j]] = min(d[b[j]],d[a[j]]+w[j]);

        memcpy(d2,d,sizeof(d));

        //cerr << d[0] <<" "<<d[1] <<" "<<d[2] <<" "<<d[3] << endl;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < ptr;j++)
                d[b[j]] = min(d[b[j]],d[a[j]]+w[j]);

        //cerr << d[0] <<" "<<d[1] <<" "<<d[2] <<" "<<d[3] << endl;


        for (int i = 0; i < n; i++)
            if (d[i] != d2[i]){
                printf("No\n");
                exit(0);
            }
    }
};

vector<int> g[MAXN];
vector<int> gt[MAXN];
              

int a[MAXN];
int b[MAXN];
int w[MAXN];
bool used1[MAXN];
bool used2[MAXN];

void dfs(int v,vector<int>* g,bool* used){
    if (used[v])
        return;
    vector<int>& gv = g[v];
    used[v] = true;
    for (int i = 0; i < (int)gv.size(); i++)
        dfs(gv[i],g,used);
}



int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&n,&m);

    for (int i = 0; i < m; i++){
        scanf("%d %d",&a[i],&b[i]);
        --a[i],--b[i];
        g[a[i]].pb(b[i]);
        gt[b[i]].pb(a[i]);
    }

    dfs(0,g,used1);
    dfs(n-1,gt,used2);

    for (int i = 0; i < m; i++)
        if (used1[a[i]] && used2[a[i]] && used1[b[i]] && used2[b[i]]){
            fb::add(a[i],b[i],2);
            fb::add(b[i],a[i],-1);
        }

    fb::fordbelman();

    printf("Yes\n");

    for (int i = 0; i < m; i++)
        if (used1[a[i]] && used2[a[i]] && used1[b[i]] && used2[b[i]]){
            printf("%d\n",fb::d[b[i]] - fb::d[a[i]]);
        }
        else
            printf("1\n");

      
  return 0;
}