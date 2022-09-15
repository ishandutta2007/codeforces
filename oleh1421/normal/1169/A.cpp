#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll d[300001];
ll f[300001];
const long long mod=998244353ll;
int main()
{
    int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    a--;
    b--;
    c--;
    d--;
    while (a!=b && c!=d){
        if (a==c){
            cout<<"YES";
            return 0;
        }
        a=(a+1)%n;
        c=(c+n-1)%n;
      //  cout<<a<<" "<<c<<endl;
    }
    if (a==c) cout<<"YES";
    else cout<<"NO";
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4