#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n>>m;
        if(n==1||m==1||n==2&&m==2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}