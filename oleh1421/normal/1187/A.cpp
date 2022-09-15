#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n,s,t;cin>>n>>s>>t;
        cout<<max(n-t,n-s)+1<<endl;
    }
    return 0;
}