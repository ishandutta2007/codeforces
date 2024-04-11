#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,i,u,v;
    cin>>n;
    v=0;
    for (i=1;i<=n;i++) {
        cin>>u;
        v+=u;
    }
    cout<<v;
}