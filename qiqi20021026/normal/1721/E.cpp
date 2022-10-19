#include<bits/stdc++.h>

using namespace std;

#define N 1200000

int n,m,nxt[N],go[N][30];
char s[N];

void solve(){
    scanf("%s",s+n+1); m=strlen(s+n+1);
    for (int i=n+1,j=nxt[n];i<=n+m;++i){
        for (;j&&s[j+1]!=s[i];){
            if (j>n) j=nxt[j];
            else{
                j=go[j][s[i]-'a'];
            }
        }
        nxt[i]=s[j+1]==s[i]?++j:j;
        cout<<nxt[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    scanf("%s",s+1); n=strlen(s+1);
    for (int i=2,j=0;i<=n;++i){
        for (;j&&s[j+1]!=s[i];j=nxt[j]);
        nxt[i]=s[j+1]==s[i]?++j:j;
    }
    for (int i=1;i<=n;++i){
        for (int j=0;j<26;++j) go[i][j]=go[nxt[i]][j];
        go[i][s[nxt[i]+1]-'a']=nxt[i];
    }
    int T; scanf("%d",&T);
    while (T--) solve();

    return 0;
}