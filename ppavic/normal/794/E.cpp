#include <cstdio>
#include <iostream>
#include <vector>

#define PB push_back
#define MP make_pair

using namespace std;

typedef pair < int, int >pii;
typedef vector < int > vi;

const int N = 1e5 + 500;

vi v;
int n,x,dp[1005][1005][2],sol[N];

int f(int i,int j,int k){
    if(dp[i][j][k]) return dp[i][j][k];
    if(i == j) return v[j];
    if(k){
        return dp[i][j][k] = max(f(i+1,j,!k),f(i,j-1,!k));
    }
    else{
        return dp[i][j][k] = min(f(i+1,j,!k),f(i,j-1,!k));
    }
}

int getpar(int len){
    if(n&1){
        int s1 = max(v[len / 2], v[len / 2 - 1]);
        int s2 = max(v[v.size() - 1 - len / 2],v[v.size() - len / 2]);
        return max(s1, s2);
    }
    else{
        int s1 = max(v[len / 2], v[len / 2 - 1]);
        int s2 = max(v[v.size() - 1 - len / 2],v[v.size() - len / 2]);
        return max(s1, s2);
    }
}

int getnep(int len){
    if(n&1){
        int s1 = min(v[len / 2], v[len / 2 - 1]);
        int s2 = min(v[len / 2], v[len / 2 + 1]);
        int s3 = min(v[v.size() - len / 2 - 1],v[v.size() - len / 2]);
        int s4 = min(v[v.size() - len / 2 - 1],v[v.size() - len / 2 - 2]);
        return max(max(s1,s2),max(s3,s4));
    }
    else{
        int s1 = min(v[len / 2], v[len / 2 - 1]);
        int s2 = min(v[len / 2], v[len / 2 + 1]);
        int s3 = min(v[v.size() - len / 2 - 1],v[v.size() - len / 2]);
        int s4 = min(v[v.size() - len / 2 - 1],v[v.size() - len / 2 - 2]);
        return max(max(s1,s2),max(s3,s4));
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        v.PB(x);
        sol[1] = max(sol[1], x);
    }
    int cur = -1;
    for(int len = n - (n%2);len>1;len-=2){
        cur = max(cur, getpar(len));
        sol[len] = cur;
    }
    cur = -1;
    for(int len = n - (!(n%2));len>1;len-=2){
        cur = max(cur, getnep(len));
        sol[len] = max(sol[len],cur);
    }
    for(int i = n;i>=1;i--){
        printf("%d ",sol[i]);
    }
    printf("\n"); 
    /**
// BRUTE 
    for(int i = n;i>=1;i--){
        int x = 0;
        for(int j = 0;j+i<=n;j++){
            x = max(x, f(j, j + i - 1 , 1));
        }           
        printf("X%d\n",x);
        if(sol[i] != x) printf("I%d %d\n",i,x - sol[i]);

    } 
    printf("\n");  
    system("pause");
    **/      
}