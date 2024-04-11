#include<bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fr(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define endl "\n"
#define fast std::ios_base::sync_with_stdio(false)
lli power(lli a,lli b)
{
    if(b==0)
        return 1;
    lli p=power(a,b/2);
    if(b%2==0)
        return p*p;
    else
        return a*p*p;
}
li gcd(li a,li b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    fast;
    lli n,i,a,b,st;
    cin>>n;
    map<lli,vector<lli> > m;
    map<lli,li> vis;
    fr(i,n)
    {
        cin>>a>>b;
        m[a].pb(b);
        m[b].pb(a);
        vis[a]=0;
        vis[b]=0;
    }
    map<lli,vector<lli> >::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if((it->S).size()==1)
        {
            st=(it->F);
            break;
        }
    }
    while(!vis[st])
    {
        vis[st]=1;
        cout<<st<<" ";
        if(!vis[m[st][0]])
            st=m[st][0];
        else if(m[st].size()==2)
            st=m[st][1];
    }
    return 0;
}