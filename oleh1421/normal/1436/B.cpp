#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
bool prime(int x){
    for (int i=2;i*i<=x;i++){
        if (x%i==0) return false;
    }
    return true;
}
int a[N][N];
void solve(){
    int n;cin>>n;
    for (int i=0;i<n-1;i++) a[0][i]=1;
    int x=n;
    while (!prime(x) || prime(x-n+1)){
        x++;
    }
    a[0][n-1]=x-n+1;
    for (int i=1;i<n;i++){
        for (int j=0;j<n;j++){
            a[i][j]=a[0][(i+j)%n];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}