#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int q[1000][1000];
int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            q[i][j]=0;
        }
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(a!=0){
            if(b!=0){
                if(q[a-1][b-1]!=0 && q[a][b-1]!=0 && q[a-1][b]!=0){
                    cout<<i+1;
                    return 0;
                }
            }
            if(b!=m-1){
                if(q[a][b+1]!=0 && q[a-1][b]!=0 && q[a-1][b+1]!=0){
                    cout<<i+1;
                    return 0;
                }
            }
        }
        if(a!=n-1){
            if(b!=0){
                if(q[a+1][b-1]!=0 && q[a][b-1]!=0 && q[a+1][b]!=0){
                    cout<<i+1;
                    return 0;
                }
            }
            if(b!=m-1){
                if(q[a][b+1]!=0 && q[a+1][b]!=0 && q[a+1][b+1]!=0){
                    cout<<i+1;
                    return 0;
                }
            }
        }
        q[a][b]=1;
    }
    cout<<0;
}