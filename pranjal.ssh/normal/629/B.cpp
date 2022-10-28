#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(366),b(366);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        char ch;
        int x,y;
        cin>>ch>>x>>y;
        x--,y--;
        if(ch=='M')
        {
            for(int j=x;j<=y;++j)a[j]++;
        }
        else
        {
            for(int j=x;j<=y;++j)b[j]++;
        }
    }
    for(int j=0;j<366;++j)ans=max(ans,2*min(a[j],b[j]));
    cout<<ans;
    
    return 0;
}