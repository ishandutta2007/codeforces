#include <iostream>
using namespace std;
bool vis[105];
int n;
int main(){
    cin>>n;
    if(!(n&1)){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++){
        int tmp;
        cin>>tmp;
        if(tmp&1) vis[i]=true;
    }
    if(vis[1]&&vis[n]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}