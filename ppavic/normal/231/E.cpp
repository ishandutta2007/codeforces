#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <queue>
#include <cstring>


#define MAXN 100005
#define LOG 18
#define MOD 1000000007

using namespace std;

vector < vector < int> > v(MAXN);
int n,k,m,a,b;
int par[MAXN],bio[MAXN];
int dp[MAXN][LOG],p[MAXN];
vector < vector <int> > cik;
vector < int > emp;
vector < vector <int> > g;
vector <int> ab;
vector <int> bc;
int ind[MAXN];
int depth[MAXN];
int bio2[MAXN];

long long int fastpot(long long int x,long long int y){
    long long int res = 1;
    while(y!=0){
        if(y&1) res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
/**
6 7 1 2 2 3 3 1 1 4 4 5 5 6 6 7 3 1 4 1 5 1 2
**/
void c(int x,int y){
    //printf("C1: %d %d\n",x,y);
    cik[cik.size()-1].push_back(x);
    bio[x] = 2;
    ind[x] = cik.size()-1;
    for(int i = 0;i<v[x].size();i++){
        if(v[x][i] == cik[cik.size()-1][0] && y!=cik[cik.size()-1][0]) return;
    }
    for(int i = 0;i<v[x].size();i++){
        if(bio[v[x][i]] == 1){
            c(v[x][i],x);
        }
    }
    //printf("C2: %d %d\n",x,y);

}

void dfs(int x,int y){
    //printf("DFS1: %d %d\n",x,y);
    bio[x] = 1;

    for(int i = 0;i<v[x].size();i++){
        if(v[x][i] == y) continue;
        if(bio[v[x][i]] == 1){
            cik.push_back(emp);
            g.push_back(emp);
            c(x,x);
            continue;
        }
    }
    for(int i = 0;i<v[x].size();i++){
        if(bio[v[x][i]] == 2 || v[x][i] == y) continue;
        dfs(v[x][i],x);
    }
    if(bio[x] == 1){

        cik.push_back(emp);
        g.push_back(emp);
        ind[x] = cik.size()-1;
        cik[cik.size()-1].push_back(x);
    }
    //printf("DFS2: %d %d\n",x,y);
    bio[x] = 2;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        scanf("%d %d",&a,&b);
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
        ab.push_back(a);
        bc.push_back(b);
    }
    v[0].push_back(6);
    dfs(0,0);
    for(int i = 0;i<ab.size();i++){

        if(ind[ab[i]] != ind[bc[i]]){
            g[ind[ab[i]]].push_back(ind[bc[i]]);
            g[ind[bc[i]]].push_back(ind[ab[i]]);
        }
    }
    for(int i = 0;i<cik.size();i++){
        for(int j = 0;j<cik[i].size();j++){
        }
    }
    queue <int> bfs;
    bfs.push(0);
    bio2[0] = 1;
    while(!bfs.empty()){
        int q = bfs.front();
		if(cik[q].size() != 1) p[q]++;
        for(int i = 0;i<g[q].size();i++){

            if(bio2[g[q][i]] == 1) continue;
            depth[g[q][i]] = depth[q] +1;
            p[g[q][i]] = p[q];
            bio2[g[q][i]] = 1;
            dp[g[q][i]][0] = q;
            bfs.push(g[q][i]);
        }
        bfs.pop();
    }
    cout << endl;
    for(int j = 1;j<18;j++){
        for(int i = 0;i<cik.size();i++){
            if(depth[i]-(1<<(j-1))<0) {dp[i][j] = dp[i][j-1];}
            else{dp[i][j] = dp[dp[i][j-1]][j-1];}
        }
    }
    int q;
    scanf("%d",&q);
    for(int z = 0;z<q;z++){
        int xx,yy;
        scanf("%d %d",&xx,&yy);
        xx--;
        yy--;
        xx = ind[xx];
        yy = ind[yy];
        if(depth[yy] > depth[xx]){
            int temp = yy;
            yy = xx;
            xx = temp;
        }
        int rx = xx;int ry = yy;
        int sol = 0;
        for(int i = 17;i>=0;i--){
            if(depth[xx] - (1 << i) >= depth[yy]){
                xx = dp[xx][i];
            }
        }
        sol = 0;

        if(xx == 0) sol += p[rx];
        else {sol += p[rx] - p[xx];if(cik[xx].size() > 1) sol ++;}

        if(xx == yy) {printf("%d\n",fastpot(2,sol));continue;}
        for(int i = 17;i>=0;i--){
            if(dp[xx][i] != dp[yy][i]) {
            xx = dp[xx][i];
            yy = dp[yy][i];
            }

        }
        xx = dp[xx][0];
        if(xx == 0) {sol = p[rx] + p[ry];if(cik[0].size() > 1) sol--;}
        else {sol = p[rx] + p[ry] - 2 * p[xx];if(cik[xx].size()>1) sol++;}
        printf("%I64d\n",fastpot(2,(long long int)sol));

    }


}