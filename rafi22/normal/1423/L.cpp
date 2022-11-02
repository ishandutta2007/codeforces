#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

unordered_map<bitset<1000>,int>mapa;
unordered_map<bitset<1000>,bool>was;
bitset<1000> sw[37];
bitset<1000>que[1007];
int ans[1007];
bitset<1000>act;
int ile,n,s,d;

void bt(int i)
{
    if(i==s-s/3+1)
    {
        if(!was[act])
        {
            was[act]=1;
            mapa[act]=ile;
        }
        else mapa[act]=min(mapa[act],ile);
        return;
    }
    act^=sw[i];
    ile++;
    bt(i+1);
    act^=sw[i];
    ile--;
    bt(i+1);
}
void bt1(int i)
{
    if(i==s+1)
    {
        for(int j=1;j<=d;j++)
        {
            if(was[(que[j]^act)]) ans[j]=min(ans[j],ile+mapa[que[j]^act]);
        }
        return ;
    }
    act^=sw[i];
    ile++;
    bt1(i+1);
    act^=sw[i];
    ile--;
    bt1(i+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,a;
    cin>>n>>s>>d;
    for(int i=1;i<=s;i++)
    {
        cin>>t;
        while(t--)
        {
            cin>>a;
            sw[i][a-1]=1;
        }
    }
    bt(1);
    for(int i=1;i<=d;i++)
    {
        ans[i]=inf;
        cin>>t;
        while(t--)
        {
            cin>>a;
            que[i][a-1]=1;
        }
    }
    bt1(s-s/3+1);
    for(int i=1;i<=d;i++)
    {
        if(ans[i]==inf) cout<<-1<<endl;
        else cout<<ans[i]<<endl;
    }

    return 0;
}