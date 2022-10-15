#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,n,m,i,j;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a>>b;
        if (a-b==1) cout<<"NO"; else cout<<"YES";
        cout<<endl;
    }
}