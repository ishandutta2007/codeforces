#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int> mp;
map<pair<int,int>,int> e;
#define N 100010
int n,a,b,k,f;
int tot,etot;
int price[305];
int st[305],ed[305];
int calc(int x,int y)
{
    if(x>y) swap(x,y);
    if(e.find({x,y})==e.end()) e[{x,y}]=++etot;
    return e[{x,y}];
}
int main()
{
    scanf("%d%d%d%d%d",&n,&a,&b,&k,&f);
    for(int i=1;i<=n;++i)
    {
        string name;
        cin>>name;
        if(mp.find(name)==mp.end()) mp[name]=++tot;
        st[i]=mp[name];
        cin>>name;
        if(mp.find(name)==mp.end()) mp[name]=++tot;
        ed[i]=mp[name];
    }

    for(int i=1;i<=n;++i)
    {
        if(st[i]==ed[i-1])
            price[calc(st[i],ed[i])]+=b;
        else
            price[calc(st[i],ed[i])]+=a;
    }
    sort(price+1,price+etot+1);
    int ans=0;
    for(int i=etot;i>=1;--i)
    {
        if(price[i]>f && k>0)
        {
            ans+=f;
            --k;
        }
        else
        {
            ans+=price[i];
        }
    }
    cout<<ans<<endl;
}