#include<bits/stdc++.h>
using namespace std;
const int maxN=501;
int A[maxN],n,dp[maxN][maxN];
void enter(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
}
int DFS(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if(l==r)return 1;
    if(r-l==1)
        if(A[l]==A[r])return 1;
        else return 2;
    dp[l][r]=501;
    if(A[l]==A[r])dp[l][r]=DFS(l+1,r-1);
    for(int i=l;i<r;i++)
       dp[l][r]=min(dp[l][r],DFS(l,i)+DFS(i+1,r));
    return dp[l][r];
}
void init(){
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
           dp[i][j]=-1;
}
int main(){
    enter();
    init();
    cout<<DFS(1,n);
}