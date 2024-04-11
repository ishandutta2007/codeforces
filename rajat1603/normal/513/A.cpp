#include<bits/stdc++.h>
using namespace std;
int k,l;
int mem[51][51][2];
bool solve(int n1,int n2,bool c){
    if(n1==0&&c==0){
        return 0;
    }
    if(n2==0&&c==1){
        return 1;
    }
    if(mem[n1][n2][c]!=-1){
        return mem[n1][n2][c];
    }
    if(c==0){
        bool b=0;
        for(int i=1;i<=k;i++){
            if(i<=n1){
                b|=solve(n1-i,n2,1);
            }
        }
        return mem[n1][n2][c]= b;
    }
    else{
        bool b=1;
        for(int i=1;i<=l;i++){
            if(i<=n2){
                b&=solve(n1,n2-i,0);
            }
        }
        return mem[n1][n2][c]=(b);
    }
}
int main() {
    memset(mem,-1,sizeof(mem));
    int n,m;
    cin>>n>>m>>k>>l;
    if(solve(n,m,0)){
        printf("First");
    }
    else{
        printf("Second");
    }
}