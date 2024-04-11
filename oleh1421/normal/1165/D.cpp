/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int t;cin>>t;
    while (t--){
        int n;cin>>n;
        vector<ll>v;
        for (int i=1;i<=n;i++){
            int a;cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        ll x=v[0]*v[n-1]*1ll;
        vector<ll>u;
        for (ll i=2;i*i<=x;i++){
            if (x%i) continue;
            u.push_back(i);
            if (i*i!=x) u.push_back(x/i);
        }
        sort(u.begin(),u.end());
        if (u==v) cout<<x<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}