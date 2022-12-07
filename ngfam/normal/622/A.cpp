#include <bits/stdc++.h>
using namespace std;
long long a,m,n;
int main(){
    cin>>a;
    n=1;m=0;
    while(n+m<a){
        m+=n;
        n++;
    }
    if(a==m)cout<<n;
    else cout<<a-m;
}