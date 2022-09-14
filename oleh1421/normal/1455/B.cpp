#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
void solve(){
    int x;cin>>x;
    int m=0;
    while (m*(m+1ll)/2ll<x) m++;
    if (m*(m+1ll)/2ll-1==x)  m++;
    cout<<m<<endl;
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
//2 3 4 5
//2 3 4 5 6 7 8 9 10 11 12 14