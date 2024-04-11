#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    char ch;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>ch;
            if(ch=='C')ans+=a[i]+b[j],a[i]++,b[j]++;
        }
    }
    cout<<ans;
    
    return 0;
}