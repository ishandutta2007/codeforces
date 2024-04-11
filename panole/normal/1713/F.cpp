#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a,ans;

vector<int> solve(vector<int> a)
{
    int n=a.size(),L=1,c=0;
    vector<int> ans;
    ans.resize(n);
    while ((L<<1)<=n) L<<=1,c++;
    if (L!=n)
    {
        vector<int> va; va.clear();
        for (int i=L; i<n; i++) va.push_back(a[i]^a[i-L]);
        vector<int> vans=solve(va);
        for (int i=L; i<n; i++) ans[i]=vans[i-L];
    }
    for (int j=0; j<c; j++)
        for (int i=0; i<L; i++)
            if (!((i>>j)&1)) a[i]^=a[i|(1<<j)];
    for (int i=0; i<L; i++) ans[i]=a[i^(L-1)]^(i+L<n?ans[i+L]:0);
    return ans;
}

int main()
{
    scanf("%d",&n),a.resize(n);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    ans=solve(a);
    for (int i=n-1; i>=0; i--) printf("%d ",ans[i]);
    return 0;
}