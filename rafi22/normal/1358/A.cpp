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
        int a,b;
        cin>>a>>b;
        if(b%2==0) swap(a,b);
        cout<<a/2*b+a%2*(b/2+b%2)<<endl;
    }
    return 0;
}