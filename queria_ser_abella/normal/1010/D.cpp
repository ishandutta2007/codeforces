#include <bits/stdc++.h>
#define pb push_back
#define maxn 1001000
using namespace std;

vector<int> L[maxn];
char str[88];
char tipo[maxn];
int val;
int ini[maxn];
int change[maxn];

int dp[maxn];

int dfs(int x,int ch = 1){
    if(tipo[x] == 'i'){
        return dp[x] = ini[x]; 
    }
    int A = L[x][0];
    int B = A;
    if(L[x].size() == 2)
        B = L[x][1];
    if(tipo[x] == 'a'){
        int a = dfs(A);
        int b = dfs(B);
        return dp[x] = a&b;
    }if(tipo[x] == 'x'){
        int a = dfs(A);
        int b = dfs(B);
        return dp[x] = a^b;
    }
    if(tipo[x] == 'o'){
        int a = dfs(A);
        int b = dfs(B);
        return dp[x] = a|b;
    }
    if(tipo[x] == 'n'){
        int a = dfs(A);
        return dp[x] = 1-a;
    }
}

int dfs2(int x,int ch){
    if(tipo[x] == 'i'){
        change[x] = ch;
        return 0;
    }
    int A = L[x][0];
    int B = A;
    if(L[x].size() == 2)
        B = L[x][1];
    if(tipo[x] == 'a'){
        int a = dfs2(A,ch&dp[B]);
        int b = dfs2(B,ch&dp[A]);
        return 0;
    }if(tipo[x] == 'x'){
        int a = dfs2(A,ch);
        int b = dfs2(B,ch);
        return 0;
    }
    if(tipo[x] == 'o'){
        int a = dfs2(A,ch&(1-dp[B]));
        int b = dfs2(B,ch&(1-dp[A]));
        return 0;
    }
    if(tipo[x] == 'n'){
        int a = dfs2(A,ch);
        return 0;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %s",str);
        str[0] = str[0] -'A'+'a';
        tipo[i] = str[0];
        
        if(str[0] == 'i'){
            scanf("%d",ini+i);
        }
        else {
            int a,b;
            scanf("%d%d",&a,&b), a--, b--;
            L[i].pb(a);
            L[i].pb(b);
        }
    }
    int ans = dfs(0);
    dfs2(0,1);
    for(int i=0;i<n;i++)
        if(tipo[i] == 'i')printf("%d",ans^change[i]);
}