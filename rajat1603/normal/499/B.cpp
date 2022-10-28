#include<bits/stdc++.h>
using namespace std;
map<string,string> m;
int main(){
    int n,g;
    cin>>n>>g;
    while(g--){
        string a,b;
        cin>>a>>b;
        m[a]=a;
        if(b.size()<a.size()){
            m[a]=b;
        }
    }
    while(n--){
        string x;
        cin>>x;
        cout<<m[x]<<" ";
    }
}