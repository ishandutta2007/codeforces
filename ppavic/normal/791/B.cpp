#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 150005;

int n,m,x,y;
int cnt = 0;
int bio[N];
vector <int> v[N];
vector <int> sol;

void dfs(int x){
    sol.push_back(x);
    bio[x] = 1;
    for(int i = 0;i<v[x].size();i++){
        if(!bio[v[x][i]])dfs(v[x][i]);
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1;i<=n;i++){
        if(bio[i]) continue;
        dfs(i);
        long long int sum = 0;
        for(int j = 0;j<sol.size();j++)
            sum += v[sol[j]].size();
        if(sum != (long long)sol.size() * (sol.size() -1)){
            printf("NO\n");
            return 0;
        }
        sol.clear();
    }
    printf("YES\n");
}