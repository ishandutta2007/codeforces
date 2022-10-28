#include<iostream>
using namespace std;
int main(){
    int n,s=0,p,q;
    cin>>n;
    while(n--){
        cin>>p>>q;
        s+= (q-p)>=2?1:0;
    }
    cout<<s;
}