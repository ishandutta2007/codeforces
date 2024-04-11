#include<bits/stdc++.h>

using namespace std;

int n,a[400];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i){
        int d=i-1;
        for (int j=1;j<=n;++j){
            cout<<(a[i]+(j-i)*i%n+n)%n<<" \n"[j==n];
        }
    }

    return 0;
}