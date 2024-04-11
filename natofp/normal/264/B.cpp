#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> a;

set<int> rozloz(int n)
{
    set<int> res;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            res.insert(i);
        }
    }
    if(n>1) res.insert(n);
    return res;
}
int main()
{
    int n; cin>>n;
    int * b=new int[n];
    for(int i=0;i<n;i++) cin>>b[i];
    int ans=0;
    int wyn;
    for(int i=0;i<n;i++)
    {
        wyn=0;
        set<int> dzielniki=rozloz(b[i]);
        set<int>::iterator it;
        it=dzielniki.begin();
        while(it!=dzielniki.end())
        {
            int val=*it;
            it++;
            wyn=max(wyn,a[val]+1);
        }
        it=dzielniki.begin();
        while(it!=dzielniki.end())
        {
            a[*it]=max(wyn,a[*it]);
            it++;
        }
        ans=max(ans,wyn);
    }
    if(ans==0) cout<<1;
    else cout<<ans;
    return 0;
}