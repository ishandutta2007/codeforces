#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5+500;


vector < int > graf[N];
int par[N];
int dp[N],n;
double sol[N];

void dfs(int x){
    dp[x] = 1;
    for(int i = 0;i<graf[x].size();i++){
        dfs(graf[x][i]);
        dp[x] += dp[graf[x][i]];
    }
}

void f(int x){
    double sum = 0;
    for(int i = 0;i<graf[x].size();i++) sum += (double)dp[graf[x][i]];
    for(int i = 0;i<graf[x].size();i++){
        sol[graf[x][i]] = (sum-(double)dp[graf[x][i]]) / 2 + 1 + sol[x];
    }
    for(int i = 0;i<graf[x].size();i++){
        f(graf[x][i]);
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 2;i<=n;i++){
        scanf("%d",&par[i]);
        graf[par[i]].push_back(i);
    }
    sol[1] = 1;
    dfs(1);
    f(1);
    for(int i = 1;i<=n;i++){
        printf("%f ",sol[i]);
    }
}