#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int n,a[51][51],res[51],dd[51];
ifstream fi("GUESS.INP");
ofstream fo("GUESS.OUT");
void enter(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
}
void solve(){
    for(int i=1;i<=n;i++){
        int dem[51];
        memset(dem,0,sizeof(dem));
        for(int j=1;j<=n;j++)dem[a[i][j]]++;
        for(int j=1;j<=n;j++)
            if(dem[j]==n-j){
                res[i]=j;
                break;
            }
    }
}
void testout(){
    for(int i=n;i>=1;i--)
        if(res[i]==n-1){
        res[i]=n;
        break;
    }
    for(int i=1;i<=n;i++)cout<<res[i]<<" ";
}
int main(){
    enter();
    solve();
    testout();
}