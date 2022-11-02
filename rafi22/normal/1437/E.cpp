#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[500007];
bool is[500007];
set<pair<int,int>>lis;
set<pair<int,int>>::iterator it;
pair<int,int> pr;
int ans=0;

void process(int p,int k)
{
    int act=0;
    lis.insert({-inf,-inf});
    lis.insert({a[p],0});
    lis.insert({inf,inf});
    for(int i=p+1;i<k;i++)
    {
        it=lis.upper_bound({a[i],inf});
        it--;
        pr=*it;
        if(pr.st!=-inf)
        {
            int x=pr.nd+1;
            act=max(act,x);
            if(pr.st==a[i]) lis.erase(it);
            lis.insert({a[i],x});
            while(true)
            {
                it=lis.upper_bound({a[i],x});
                pr=*it;
                if(pr.nd<=x) lis.erase(it);
                else break;
            }
        }
    }
    it=lis.begin();
    while(true)
    {
        pr=*it;
        if(pr.st<=a[k]) act=pr.nd;
        else break;
        it++;
    }
    ans+=k-p-1-act;
    lis.clear();
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,k,last=0,x;
        cin>>n>>k;
        a[0]=-inf/2;
        a[n+1]=inf/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]-=i;
        }
        for(int i=0;i<k;i++)
        {
            cin>>x;
            is[x]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(is[i])
            {
                if(a[i]<a[last])
                {
                    cout<<-1;
                    return 0;
                }
                if(last!=i-1) process(last,i);
                last=i;
            }
        }
        if(last<n) process(last,n+1);
        cout<<ans;
    }

    return 0;
}