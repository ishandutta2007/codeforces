#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int LN = 20;   // 2 ^ 20 > N
int dp[LN][N];        //FOR LCA BINARY JUMPING
int depth[N];        //DEPTH OF A NODE
int node1,node2;
int q;
int n;
int ans;
void pre(){
    node1 = 2;    //MOST DISTANT PAIR OF NODES
    node2 = 4;    //MOST DISTANT PAIR OF NODES
    n = 4;        //NUMBER OF NODES IN THE TREE
    ans = 2;      //DISTANCE BETWEEN 2 and 4
    dp[0][2] = 1; //PARENT OF 2 IS 1
    dp[0][3] = 1; //PARENT OF 3 IS 1
    dp[0][4] = 1; //PARENT OF 4 IS 1
    depth[1] = 0; //1 IS THE ROOT
    depth[2] = 1; //2 IS CHILD OF 1
    depth[3] = 1; //3 IS CHILD OF 1
    depth[4] = 1; //4 IS CHILD OF 1
}
int LCA (int a , int b){//RETURNS LOWEST COMMON ANCESTOR OF 2 NODES
    if(depth[a] < depth[b]){
        return LCA (b , a);
    }
    int dif = depth[a] - depth[b];
    for(int i = 0 ; i < LN ; ++i ){
        if((dif>>i)&1){
            a = dp[i][a];
        }
    }
    if(a != b){
        for(int i = LN - 1 ; i >= 0 ; --i ){
            if(dp[i][a] != dp[i][b]){
                a = dp[i][a];
                b = dp[i][b];
            }
        }
        a = dp[0][a];
    }
    return a;
}
int dist(int a , int b){//RETURN DISTANCE BETWEEN 2 NODES
    return depth[a] + depth[b] - (depth[LCA(a,b)]<<1);
}
int main(){
    pre();
    scanf("%d",&q);
    while(q--){
        int node;
        scanf("%d",&node);
        dp[0][n+1] = node;
        dp[0][n+2] = node;
        for(int i = 1 ; i < LN ; ++i ){
            dp[i][n+1] = dp[i-1][dp[i-1][n+1]];  //BUILD LCA TABLE
            dp[i][n+2] = dp[i][n+1];
        }
        depth[n+1] = depth[node] + 1;//INITIALIZE DEPTH OF N + 1 
        depth[n+2] = depth[n+1]     ;//INITIALIZE DEPTH OF N + 2
        int d1 = dist(n+1,node1);
        int d2 = dist(n+2,node2);
        if(d1>ans){
            node2 = n+1;
            ans = d1;
        }
        if(d2>ans){
            node1 = n+2;
            ans = d2;
        }
        printf("%d\n",ans);
        n+=2;
    }
}