#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll a[500005];
vector<pair<ll,int> >s[805];
vector<int>res;
vector<pair<ll,int> >::iterator itr;
ll tag[805];
int main()
{
    int n,q;
    cin>>n>>q;
    int b_s=(int)sqrt(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int loc=-1;
    for(int i=0;i<n;i++)
    {
        if(i%b_s==0)loc++;
        s[loc].push_back(make_pair(a[i],i));
    }
    for(int i=0;i<=loc;i++)
    {
        sort(s[i].begin(),s[i].end());
    }
    int op,l,r;
    ll x,y;
    while(q--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            cin>>l>>r>>x;
            l--,r--;
            int bl=l/b_s;
            int br=r/b_s;
            for(int i=bl+1;i<br;i++)
            {
                tag[i]+=x;
            }
            for(int i=0;i<s[bl].size();i++)
            {
                s[bl][i].first+=tag[bl];
                if(s[bl][i].second>=l && s[bl][i].second<=r)
                    s[bl][i].first+=x;
            }
            sort(s[bl].begin(),s[bl].end());
            tag[bl]=0;
            if(br>bl)
            {
                for(int i=0;i<s[br].size();i++)
                {
                    s[br][i].first+=tag[br];
                    if(s[br][i].second>=l && s[br][i].second<=r)
                        s[br][i].first+=x;
                }
                sort(s[br].begin(),s[br].end());
                tag[br]=0;
            }
        }
        else
        {
            cin>>y;
            res.clear();
            for(int i=0;i<=loc;i++)
            {
                itr=lower_bound(s[i].begin(),s[i].end(),make_pair(y-tag[i],0));
                if(itr!=s[i].end() && (*itr).first==y-tag[i])res.push_back((*itr).second);
                itr=lower_bound(s[i].begin(),s[i].end(),make_pair(y-tag[i]+1,0));
                if(itr!=s[i].begin())
                {
                    itr--;
                    if((*itr).first==y-tag[i])res.push_back((*itr).second);
                }
            }
            if(res.empty())cout<<"-1"<<endl;
            else
            {
                sort(res.begin(),res.end());
                cout<<res[res.size()-1]-res[0]<<endl;
            }
        }
    }
    return 0;
}