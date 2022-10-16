#include <bits/stdc++.h>
#define ll long long int
#define pb push_back


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        ll a,b,n; cin>>a>>b>>n;
        int cnt = 0;
        while(a<=n && b<=n)
        {
            if(a<b) a+=b;
            else b+=a;
            cnt++;
        }
        cout<<cnt<<endl;
    }


    return 0;
}