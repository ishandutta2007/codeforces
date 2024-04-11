#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=1;i+1<n;i++)
        res+=(a[i]>a[i-1]+a[i+1]);
    return 0*printf("%d\n",k>1 ? res : (n-1)/2);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}