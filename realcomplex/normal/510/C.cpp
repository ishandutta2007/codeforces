#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = 26;//letters are nodes
vector<int>G[N];
int state[N];
vector<int>topological_sort;

void dfs(int cur){
    if(state[cur]==1){
        cout <<"Impossible\n";
        exit(0);
    }
    if(state[cur]==2)
        return;
    state[cur]=1;
    for(auto x : G[cur]){
        dfs(x);
    }
    state[cur]=2;
    topological_sort.push_back(cur);
}

int main(){
    int n;
    cin >> n;
    string wor[n];
    bool broken;
    for(int i = 0;i<n;i++){
        cin >> wor[i];
        if(i==0)continue;
        broken=false;
        for(int j = 0;j<min(wor[i].size(),wor[i-1].size());j++){
            if(wor[i][j]==wor[i-1][j])
                continue;
            G[wor[i-1][j]-'a'].push_back(wor[i][j]-'a');
            broken=true;
            break;
        }
        if(!broken){
            if(wor[i-1].size()>wor[i].size()){
                cout << "Impossible\n";
                exit(0);
            }
        }
    }
    for(int i = 0;i<N;i++){
        dfs(i);
    }
    while(!topological_sort.empty()){
        cout<< char(topological_sort.back()+97);
        topological_sort.pop_back();
    }
    return 0;
}