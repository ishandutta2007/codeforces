#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair < int,int > pii;
typedef pair < ll ,ll > pll;
typedef pair < double, double > pdd;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int edg[N],n,x,gud = 1;
vector < int > v[N];

int leaf(int x){
    if(v[x].size() == 0) return 1;
    return 0;
}

void dfs(int x){
    if(leaf(x)) return;
    int cnt = 0;
    for(int i = 0;i<v[x].size();i++){
        dfs(v[x][i]);
        cnt += leaf(v[x][i]);
    }
    if(cnt < 3) gud = 0;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n-1;i++){
        int x,y;scanf("%d",&x);
        v[x].push_back(i+2);
    }
    gud = 1;
    dfs(1);
    if(gud) printf("Yes\n");
    else printf("No\n");
}