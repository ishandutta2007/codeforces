#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    for(int i=1;i<=k-1;i++){
        for(int j=1;j<=k-1;j++){
            int x,y;
            x=i*j/k;
            y=i*j%k;
            if(x!=0)
                cout<<x<<y<<' ';
            else cout<<' '<<y<<' ';
        }
        cout<<endl;
    }
    return 0;
}