#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

const int N=200007;

pair<int,int> r[N];
int s[N];
int cnt;
vector<pair<pair<int,int>,int>>changes;

int U[N],V[N];

pair<int,int> Find(int v)
{
    if(v!=r[v].st)
    {
        int p=r[v].nd;
        pair<int,int>x=Find(r[v].st);
        return {x.st,x.nd^r[v].nd};
    }
    return r[v];
}

void Merge(int i)
{
    int u=Find(U[i]).st,v=Find(V[i]).st;
    int b=Find(U[i]).nd^Find(V[i]).nd^1;
    if(s[u]>s[v]) swap(u,v);
    changes.pb({{u,v},b});
    if(u==v)
    {
        cnt+=b;
        return;
    }
    s[v]+=s[u];
    r[u]={v,b};
}
void Rollback()
{
    int u=changes.back().st.st,v=changes.back().st.nd,b=changes.back().nd;
    changes.pop_back();
    if(u==v)
    {
        cnt-=b;
        return ;
    }
    s[v]-=s[u];
    r[u]={u,0};
}

int R[N];

void rek(int l1,int r1,int l2,int r2)
{
    if(r1<l1) return;
    if(l2==r2)
    {
       // cout<<l2<<" "<<l1<<" "<<r1<<endl;
        for(int i=l1;i<=r1;i++) R[i]=l2;
        return ;
    }
    int m=(l2+r2)/2;
    for(int i=r2-1;i>=m;i--) Merge(i);
    int k;
    if(l1==0) k=-1;
    else k=l1-2;
    if(cnt==0)
    {
        k++;
        while(k+1<min(m,r1+1))
        {
            Merge(k+1);
            if(cnt>0)
            {
                Rollback();
                break;
            }
            k++;
        }
    }
    for(int i=max(1,l1);i<=k;i++) Rollback();
    rek(l1,k,l2,m);
    for(int i=r2-1;i>=m;i--) Rollback();
    for(int i=max(1,l1);i<=k;i++) Merge(i);
    rek(k+1,r1,m+1,r2);
    for(int i=max(1,l1);i<=k;i++) Rollback();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        r[i]={i,0};
        s[i]=1;
    }
    for(int i=1;i<=m;i++) cin>>U[i]>>V[i];
    rek(0,m,1,m+1);
    for(int i=1;i<=m;i++)
    {
        Merge(i);
        if(cnt>0) R[i]=inf;
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(R[l-1]<=r+1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }


    return 0;
}