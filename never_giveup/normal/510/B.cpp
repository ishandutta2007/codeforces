#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
int n,m,d[50][50],q[50][50];
int dfs(int i,int j){
    d[i][j]=1;
    int a=0;
     if(i!=0){
            if(d[i-1][j]==1)
                a++;
            else
            if(q[i][j]==q[i-1][j] && dfs(i-1,j)==1)
            return 1;
     }
     if(i!=n-1){
            if(d[i+1][j]==1)
                a++;
            else
            if(q[i][j]==q[i+1][j] && dfs(i+1,j)==1)
            return 1;
     }
     if(j!=0){
            if(d[i][j-1]==1)
                a++;
            else
            if(q[i][j]==q[i][j-1] && dfs(i,j-1)==1)
            return 1;
     }
     if(j!=m-1){
            if(d[i][j+1]==1)
                a++;
            else
            if(q[i][j]==q[i][j+1] && dfs(i,j+1)==1)
            return 1;
     }
     if(a>1)
        return 1;
     d[i][j]=0;
     return 0;
}
int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    cin>>n>>m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        char c;
        cin>>c;
        q[i][j]=c-65;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(i,j)==1){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
}