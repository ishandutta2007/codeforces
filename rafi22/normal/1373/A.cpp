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
        long double a,b,c;
        cin>>a>>b>>c;
        if(a>=c) cout<<-1<<" ";
        else  cout<<1<<" ";
        if(c/b<a) cout<<(int)b<<endl;
        else cout<<-1<<endl;
    }


    return 0;
}