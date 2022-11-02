#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b>=a) cout<<b<<endl;
        else if(d>=c) cout<<-1<<endl;
        else cout<<b+(long long)ceil((long double)(a-b)/(long double)(c-d))*c<<endl;
    }
    return 0;
}