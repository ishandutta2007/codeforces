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

int tree[1000007];
int timee[1000007];
int ans[200007];
set <int> add;
set <int>::iterator it;
int pos[200007],pot=1;

void ins(int u,int a,int b,int l,int p,int v)
{
    if(a<=l&&b>=p)
    {
        tree[u]=v;
        return;
    }
    if(p<a||l>b) return;
    ins(2*u,a,b,l,(l+p)/2,v);
    ins(2*u+1,a,b,(l+p)/2+1,p,v);
}
int que(int u)
{
    int maxi=0,val=0;
    int y=u+pot-1;
    while(y>0)
    {
        val=max(val,tree[y]);
        y/=2;
    }
    return val;
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
        int n,a;
        cin>>n;
        while(pot<n) pot*=2;
        int cnt=1,added;
        char ch;
        add.insert(inf);
        bool gg=0;
        for(int i=1;i<=2*n;i++)
        {
            cin>>ch;
            if(gg) continue;
            if(ch=='+')
            {
                add.insert(i);
                pos[i]=cnt++;

            }
            else
            {
                cin>>a;
                int x=que(a);
                it=add.upper_bound(x);
                if(*it==inf)
                {
                    gg=1;
                    continue;
                }
                ans[pos[*it]]=a;
                add.erase(*it);
                ins(1,1,a-1,1,pot,i);
            }
        }
        if(gg) cout<<"NO";
        else
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        }
    }

    return 0;
}