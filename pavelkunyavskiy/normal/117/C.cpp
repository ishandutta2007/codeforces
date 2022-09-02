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
#include <iterator>
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


int curv;
int n;
char g[5010][5010];


int v[5010];


bool cmp(int a){
    return g[curv][a] == '1';
}

void solve(int l,int r){
    if (r - l < 3)
        return;
    random_shuffle(v+l,v+r);
    curv = v[l];
    int mid = partition(v+l+1,v+r,cmp) - v;

//  copy(v+l,v+r,ostream_iterator<int>(cerr," "));cerr << endl;

    for (int i = l + 1; i < mid; i++)
        for (int j = mid; j < r; j++)
            if (g[v[i]][v[j]] == '1'){
                printf("%d %d %d\n",v[l]+1,v[i]+1,v[j]+1);
                exit(0);
            }

    solve(l+1,mid);
    solve(mid,r);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    gets(g[0]);
    sscanf(g[0],"%d",&n);
    for (int i = 0; i < n; i++){
        gets(g[i]);
        v[i] = i;
    }

    solve(0,n);

    cout << -1 << endl;
    

  return 0;
}