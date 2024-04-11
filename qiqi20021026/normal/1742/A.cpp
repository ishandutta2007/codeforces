#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--){
        int x,y,z; cin>>x>>y>>z;
        if (x>z) swap(x,z);
        if (y>z) swap(y,z);
        cout<<(x+y==z?"YES":"NO")<<'\n';
    }
}