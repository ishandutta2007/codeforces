#include <bits/stdc++.h>
using namespace std;
bool a[15][15], b[15][15];
int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; ++i){
        cin>> s;
        for(int j=0; j<n; ++j){
            a[i][j]=false;
            if(s[j]=='O') a[i][j]=true;
        }
    }
    for(int i=0; i<n; ++i){
        cin>> s;
        for(int j=0; j<n; ++j){
            b[i][j]=false;
            if(s[j]=='O') b[i][j]=true;
        }
    }
    bool r[10];
    for(int i=0; i<10; i++) r[i]=true;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(a[i][j]!=b[i][j]) r[0]=false;
            if(a[i][j]!=b[n-1-i][j]) r[1]=false;
            if(a[i][j]!=b[i][n-1-j]) r[2]=false;
            if(a[i][j]!=b[n-1-i][n-1-j]) r[3]=false;
            if(a[i][j]!=b[j][i]) r[4]=false;
            if(a[i][j]!=b[j][n-1-i]) r[5]=false;
            if(a[i][j]!=b[n-1-j][i]) r[6]=false;
            if(a[i][j]!=b[n-1-j][n-1-i]) r[7]=false;
        }
    }
    if(r[0]||r[1]||r[2]||r[3]||r[4]||r[5]||r[6]||r[7]) cout<<"Yes";
    else cout<< "No";
    return 0;
}