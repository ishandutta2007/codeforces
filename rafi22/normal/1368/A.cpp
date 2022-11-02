#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n,res=0;
        cin>>a>>b>>n;
        if(b>a) swap(a,b);
        while(a<=n)
        {
            b+=a;
            if(b>a) swap(a,b);
            res++;
        }
        cout<<res<<endl;
    }
    return 0;
}