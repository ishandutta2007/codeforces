#include <bits/stdc++.h>
using namespace std;
int a[200010];
main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
    if (a[n]==0){ cout<<-1;exit(0);}
    vector<int>basis;
    basis.push_back(a[n]);
    for (int i=1;i<n;i++){
        for (auto y:basis) a[i]=min(a[i],a[i]^y);
        if (a[i]) basis.push_back(a[i]);
    }
    cout<<basis.size();
    return 0;
}