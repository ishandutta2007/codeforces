#include<bits/stdc++.h>

using namespace std;

void cmax(int &x,int y){x=max(x,y);}
void solve(){
    int n; string s;
    cin>>n>>s;
    vector<vector<int>> f(n+1);
    f[0]=vector<int>(2);
    for (int i=1;i<=n;++i){
        f[i]=vector<int>(2);
        int t; cin>>t;
        int x=s[i-1]-'0';
        if (x==0){
            cmax(f[i][0],f[i-1][0]);
            cmax(f[i][1],f[i-1][0]+t);
        }
        else{
            cmax(f[i][0],f[i-1][0]+t);
            cmax(f[i][0],f[i-1][1]);
            cmax(f[i][1],f[i-1][1]+t);
        }
    }
    cout<<f[n][0]<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}