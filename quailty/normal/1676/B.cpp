#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    return 0*printf("%d\n",accumulate(a.begin(),a.end(),0)-*min_element(a.begin(),a.end())*n);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}