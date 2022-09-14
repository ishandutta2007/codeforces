#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=100010;
int p[N];
void solve(){
    int n;cin>>n;
    int mx=1;
    for (int i=2;i<=n;i++){
        cout<<"? "<<i<<" "<<mx<<endl;
        int a;cin>>a;
        cout<<"? "<<mx<<" "<<i<<endl;
        int b;cin>>b;
        if (a>b) p[i]=a;
        else {
            p[mx]=b;
            mx=i;
        }

    }
    p[mx]=n;
    cout<<"! ";
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}