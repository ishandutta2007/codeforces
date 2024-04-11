#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int pref[200007];
int pref1[200007];
vector <int> v;
map <int,int> ile;
int inf=1000000000000000007;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,a,x;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(ile[a]==0)
        {
            v.push_back(a);
        }
        ile[a]++;
    }
    v.push_back(-1);
    sort(v.begin(),v.end());
    int m=v.size()-1;
    for(int i=1;i<=m;i++)
    {
        pref[i]=pref[i-1]+ile[v[i]]*v[i];
        pref1[i]=pref1[i-1]+ile[v[i]];
    }
    int ans=inf;
    for(int i=1;i<=m;i++)
    {
        int res1=inf,res2=inf;
        x=k-ile[v[i]];
        if(x<=0)
        {
            ans=0;
            continue;
        }
        if(i>1)
        {
            res1=pref1[i-1]*(v[i]-1)-pref[i-1];
        }
        if(i!=m)
        {
            res2=(pref[m]-pref[i])-(pref1[m]-pref1[i])*(v[i]+1);
        }
        if(res1<=res2)
        {
            if(pref1[i-1]>=x)
            {
                ans=min(ans,res1+x);
            }
            else if(pref1[m]-pref1[i]>=x)
            {
                ans=min(ans,res2+x);
            }
            else
            {
                ans=min(ans,res2+res1+x);
            }
        }
        else
        {
            if(pref1[m]-pref1[i]>=x)
            {
                ans=min(ans,res2+x);
            }
            else if(pref1[i-1]>=x)
            {
                ans=min(ans,res1+x);
            }
            else
            {
                ans=min(ans,res2+res1+x);
            }
        }
    }
    cout<<ans;

    return 0;
}