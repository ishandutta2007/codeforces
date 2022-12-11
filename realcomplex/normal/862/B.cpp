#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

void open(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

const int MAXN = 1e5+5;
vector<int>G[MAXN];
ll cnt[2];

void dfs(int t,int l,int c){
    cnt[c]++;
    for(int j = 0;j<G[t].size();j++){
        if(G[t][j] == l) continue;
        dfs(G[t][j],t,!c);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int a,b;
    for(int j = 1;j<n;j++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,-1,0);
    cout << cnt[0]*cnt[1]-n+1;
    return 0;
}