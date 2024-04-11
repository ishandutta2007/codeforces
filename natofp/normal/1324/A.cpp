#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a=0;
        int b=0;
        for(int i=1;i<=n;i++)
        {
            int x; cin>>x; if(x%2==0) a++;
            else b++;
        }
        if(a==0 || b==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}