#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> a;
const long long int INF=1e18;
long long int minxor(int e,int l1,int r1,int l2,int r2)
{
    if(l1>=r1 || l2>=r2) return INF;
    if(e<0) return 0LL;
    int m1=l1;
    int m2=l2;
    while(m1<r1 && ((a[m1]>>e)&1)==0) m1++;
    while(m2<r2 && ((a[m2]>>e)&1)==0) m2++;
    if((l1 < m1 && l2 < m2) || (m1<r1 && m2<r2))
    {
        return min(minxor(e-1,l1,m1,l2,m2),minxor(e-1,m1,r1,m2,r2));
    }
    else
    {
        return minxor(e-1,l1,r1,l2,r2)+(1<<e);
    }
}

long long int solve(int e,int l,int r)
{
    if(e<0 || l>=r) return 0LL;
    int m=l;
    while(m<r && ((a[m]>>e)&1)==0) m++;
    long long int res=solve(e-1,l,m)+solve(e-1,m,r);
    if(l<m && m<r)
    {
        res+=minxor(e-1,l,m,m,r)+(1<<e);
    }
    return res;
}

int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x; a.push_back(x);
    }
    sort(a.begin(),a.end());
    cout<<solve(30,0,n);
    return 0;
}