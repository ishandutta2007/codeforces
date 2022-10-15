#include<bits/stdc++.h>
using namespace std;
const int N = 12;
const int M = 1e3 + 6;
typedef long long ll;
char s[N][N];
int n,trie[M][26],cnt,fail[M],len[M],m,mx,ind[5] = {1,0,'G'-'A','T'-'A','C'-'A'};
const int mod = 1e9+9;
ll f[M][N][M];
void insert(int o){
    int l = strlen(s[o] + 1);mx = max(l,mx);
    int now = 0;
    for (int i = 1,c; i <= l;i++){
        c = s[o][i] - 'A';
        if(trie[now][c] == 0) trie[now][c] = ++cnt;
        now = trie[now][c];
    }
    len[now] = l;
}

void build(){
    queue<int> q;
    for (int i = 0; i < 26;i++) if(trie[0][i]) q.push(trie[0][i]);
    while(!q.empty()){
        int now = q.front();q.pop();
        for (int i = 0; i < 26;i++){
            if(trie[now][i]){
                q.push(trie[now][i]);
                fail[trie[now][i]] = trie[fail[now]][i];
            }else
                trie[now][i] = trie[fail[now]][i];
        }
        len[now] = max(len[now],len[fail[now]]);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= m;i++) {
        scanf("%s",s[i]+1);
        insert(i);
    }
    build();
    f[0][0][0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < mx;j++){
            for(int k = 0;k <= cnt;k++){
                if(!f[i][j][k]) continue;
                for(int l = 1;l <= 4;l++){
                    int now = trie[k][ind[l]];
                    if(len[now] > j) f[i+1][0][now] = (f[i+1][0][now] + f[i][j][k]) % mod;
                    else f[i+1][j+1][now] = (f[i+1][j+1][now] + f[i][j][k]) % mod;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i <= cnt;i++) ans = (ans + f[n][0][i]) % mod;
    cout<<ans;
}