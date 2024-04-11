#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int n,m,r,mid;
long long value(int x,int y)
{
    x=min(n+1,x+r)-max(x,r);
    y=min(m+1,y+r)-max(y,r);
    return (ll)x*(ll)y;
}
set<pair<ll,pair<int,int> > > s;
set<pair<ll,pair<int,int> > >::iterator it;
void add(int x,int y)
{
    if(y>1&&y<=mid)
    {
        s.insert({value(x,y-1),{x,y-1}});
    }
    if(y<m&&y>=mid)
    {
        s.insert({value(x,y+1),{x,y+1}});
    }
}
int main()
{
    int k;
    scanf("%i %i %i %i",&n,&m,&r,&k);
    mid=(m+1)/2;
    for(int i=1;i<=n;i++)
    {
        s.insert({value(i,mid),{i,mid}});
        //printf("Dodajem %lld, %i %i\n",value(i,mid),i,mid);
    }
    long long sum=0;
    for(int i=0;i<k;i++)
    {
        it=s.end();
        it--;
        pair<ll,pair<int,int> > dd=*it;
        s.erase(it);
        sum+=dd.first;
        //printf("Dodajem %lld  %i\n",dd.first,i);
        add(dd.second.first,dd.second.second);
    }
    ll broj=(ll)(n-r+1)*(ll)(m-r+1);
    printf("%.25f\n",(double)sum/broj);
    return 0;
}