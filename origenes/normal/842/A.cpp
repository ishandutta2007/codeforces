#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    long long l, r, x, y, k;
    cin>>l>>r>>x>>y>>k;
    if(l>y*k||r<x*k) cout<<"NO"<<endl;
    else if(k<=r-l) cout<<"YES"<<endl;
    else if(r%k==0||l%k==0) cout<<"YES"<<endl;
    else if((l/k+1)*k>r) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}