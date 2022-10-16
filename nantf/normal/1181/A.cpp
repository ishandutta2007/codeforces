#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,z;
int main(){
    cin>>x>>y>>z;
cout<<(x+y)/z<<" ";
if(x/z+y/z==(x+y)/z) cout<<0;
else cout<<min(z-x%z,z-y%z);
}