#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

const int MXN = 1e5 + 5;

vector<int> g[MXN];

double dfs(int w,int r){
    double sum = 0;
    for(int i = 0;i<g[w].size();i++){
        if(g[w][i] != r){
            sum += dfs(g[w][i],w)+1;
        }
    }
    if(g[w].size() == 0){
        return sum;
    }
    else{
        if(r==-1){
            return sum/g[w].size();
        }
        else{
            if(g[w].size() == 1){
                return sum;
            }
            else{
                return sum/(g[w].size()-1);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a,b;
    for(int i = 0;i<n-1;i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << setprecision(7) << dfs(0,-1);
    return 0;
}