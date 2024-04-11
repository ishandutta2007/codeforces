#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> tab;
int k;
long long int solve(int a,int b,int l,int r,int lo,int hi)
{
    if(lo==hi)
    {
        if(l<=r) return (long long int)b*(r-l+1);
        return (long long int)a;
    }
    if(l>r) return (long long int)a;
    long long int res1;
    res1=(long long int)(hi-lo+1)*(long long int)(r-l+1)*(long long int)b;
    int mid=(lo+hi)/2;
    int c=l;
    while(c<k && tab[c]<=mid) c++;
    c--;
    long long int res2;
    res2=solve(a,b,l,c,lo,mid)+solve(a,b,c+1,r,mid+1,hi);
    return min(res1,res2);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin>>n>>k>>a>>b;

    for(int i=0;i<k;i++)
    {
        int x; cin>>x;
        tab.push_back(x);
    }
    sort(tab.begin(),tab.end());
    cout<<solve(a,b,0,k-1,1,1<<n);
    return 0;
}