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

int p[N];
int d[N];
pair<int,int>seg[2][2*(1<<18)+7];
int pot;

void del(int v)
{
    v+=pot-1;
    seg[0][v].st=-inf;
    seg[1][v].st=-inf;
    while(v>1)
    {
        v/=2;
        seg[0][v]=max(seg[0][2*v],seg[0][2*v+1]);
        seg[1][v]=max(seg[1][2*v],seg[1][2*v+1]);
    }
}

pair<int,int>ins(int x,int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[x][v];
    if(r<a||l>b) return {-inf,0};
    return max(ins(x,2*v,a,b,l,(l+r)/2),ins(x,2*v+1,a,b,(l+r)/2+1,r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        pot=1;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++) cin>>p[i];
        for(int i=1;i<=2*pot;i++)
        {
            seg[0][i].st=-inf;
            seg[1][i].st=-inf;
        }
        for(int i=1;i<=n;i++)
        {
            seg[0][i+pot-1]={p[i]+i,i};
            seg[1][i+pot-1]={p[i]-i,i};
        }
        for(int i=pot-1;i>0;i--)
        {
            seg[0][i]=max(seg[0][2*i],seg[0][2*i+1]);
            seg[1][i]=max(seg[1][2*i],seg[1][2*i+1]);
        }
        deque<int>Q;
        d[a]=0;
        Q.pb(a);
        del(a);
        while(sz(Q)>0)
        {
            int v=Q[0];
            Q.pop_front();
            while(true)
            {
                pair<int,int>x=ins(0,1,max(1,v-p[v]),v-1,1,pot);
                if(x.st<v) break;
                d[x.nd]=d[v]+1;
                Q.pb(x.nd);
                del(x.nd);
            }
            while(true)
            {
                pair<int,int>x=ins(1,1,v+1,min(n,v+p[v]),1,pot);
                if(x.st<-v) break;
                d[x.nd]=d[v]+1;
                Q.pb(x.nd);
                del(x.nd);
            }
        }
        cout<<d[b]<<endl;
    }

    return 0;
}