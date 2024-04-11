#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define MP make_pair
#define PB push_back
#define INP scanf
#define OUT printf

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;
typedef pair < string,int> psi;

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);

int n,k,m,dis[N],par[N],sum[N];
vector < int > v[N];
vector < llint > pref[N];
vector < pii > g[N];

bool cmp(int A,int B){
    return sum[A] < sum[B];
}

void dfs(int x,int lst){
    par[x] = lst;
    for(int i = 0;i<g[x].size();i++){
        if(g[x][i].first == lst || g[x][i].first == x) continue;
        sum[g[x][i].first] = sum[x] + g[x][i].second;
        dis[g[x][i].first] = g[x][i].second;
        dfs(g[x][i].first, x);
    }
}

void build(){
    vector < int > vv;
    for(int i = 1;i<=n;i++){
        vv.push_back(i);
    }
    sort(vv.begin(),vv.end(),cmp);
    for(int k = 0;k<n;k++){
        int i = vv[k];
        int j = i;
        while(j != 0){
            v[j].push_back(sum[i] - sum[j]);
            j = par[j];
        }
    }
    for(int i = 1;i<=n;i++){
        llint sum = 0;
        for(int j = 0;j<v[i].size();j++){
            sum += (llint)v[i][j];
            pref[i].push_back(sum);
        }
    }
}

llint query(int x, llint h){
    llint sol = 0;
    int y = x;
    if(v[x][0] <= h)
        sol += (upper_bound(v[x].begin(),v[x].end(), h) - v[x].begin())  * h  -pref[x][upper_bound(v[x].begin(),v[x].end(),h) - v[x].begin() - 1];
    while(x != 1){
        h -= dis[x];
        if(h < 0) break;
        sol += h;
        x = par[x];
        int s = 4 * x + 1;
        y = s - y;
        if(y > n) {
            y = x;
            continue;
        }
        h -= dis[y];
        if(v[y][0] <= h)
            sol += (upper_bound(v[y].begin(),v[y].end(), h) - v[y].begin())  * h  - pref[y][upper_bound(v[y].begin(),v[y].end(), h) - v[y].begin() - 1];
        h += dis[y];
        y = x;
    }
    return sol;
}


int main() {
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n-1;i++){
        scanf("%d",&k);
        g[i+2].push_back(make_pair(i/2+1,k));
        g[i/2+1].push_back(make_pair(i+2,k));
    }
    dfs(1,0);
    build();
    for(int i = 0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%I64d\n",query(a,b));
    }
    return 0;
}