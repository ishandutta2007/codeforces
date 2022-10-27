#include<iostream>
using namespace std;
int n,m,k,x,y;
int main(){
    cin>>n>>m>>k;
    while(k--){
        cin>>x>>y;
        if(min(min(x-1,n-x),min(y-1,m-y))<5){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}