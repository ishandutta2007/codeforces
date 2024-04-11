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
        cout<<pow(max(max(a,b),2*min(a,b)),2)<<endl;
    }
    return 0;
}