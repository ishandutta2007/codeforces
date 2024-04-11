#include<bits/stdc++.h>
using namespace std;

string s;
int n,k;
bool vis[107];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i='z';i>='a';){
        bool fg=false;
        memset(vis,0,sizeof(vis));
        for (int j=0;j<s.size();++j){
            if (s[j]!=i) continue;
            if (j>0&&s[j-1]==s[j]-1) vis[j]=1;
            if (j<s.size()-1&&s[j+1]==s[j]-1) vis[j]=1;
        }
        int m=s.size();
        for (int j=m-1;j>-1;--j){
            if (vis[j]) s.erase(s.begin()+j), fg=true;
        }
        if (!fg) i--;
    }
    cout<<n-s.size()<<endl;
    return 0;
}