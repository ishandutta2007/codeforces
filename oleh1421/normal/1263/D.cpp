#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int>x[300001];
bool used[27];
string s[300001];
vector<int>g[300001];
bool used1[300001];
void dfs(int v){
    if (used1[v]) return;
    used1[v]=true;
    for (auto to:g[v]){
        dfs(to);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<=n;i++){
        for (int j=0;j<=25;j++) used[j]=false;
        for (int j=0;j<s[i].size();j++){
            if (!used[s[i][j]-'a']) x[s[i][j]-'a'].push_back(i),used[s[i][j]-'a']=true;
        }
    }
    for (int i=0;i<=25;i++){
        for (int j=1;j<x[i].size();j++){
            g[x[i][j]].push_back(x[i][j-1]);
            g[x[i][j-1]].push_back(x[i][j]);
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (!used1[i]){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt;
	return 0;
}