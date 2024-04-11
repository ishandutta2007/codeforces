#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int N=10e5+5;
int Fen[N];
void add(int x)
{
    for(;x<N;x+=x&(-x))
        Fen[x]++;
}
int cnt(int x)
{
    int r=0;
    for(;x>0;x-=x&(-x))
        r+=Fen[x];
    return r;
}
int koji[N],x[N],r[N],q[N];
vector<pair<int,int> > by_r;
vector<pair<pair<int,int>,int> > by_qx;
int solve(int iq,int L,int R)
{
    L=lower_bound(by_qx.begin(),by_qx.end(),make_pair(make_pair(iq,L),-1))-by_qx.begin();
    R=lower_bound(by_qx.begin(),by_qx.end(),make_pair(make_pair(iq,R+1),-1))-by_qx.begin();
    R--;
    if(R<L)
        return 0;
    return cnt(R+1)-cnt(L);
}
int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%i %i %i",&x[i],&r[i],&q[i]);
        by_r.push_back({r[i],i});
        by_qx.pb({{q[i],x[i]},i});
    }
    sort(by_r.begin(),by_r.end());
    reverse(by_r.begin(),by_r.end());
    sort(by_qx.begin(),by_qx.end());
    for(int i=0;i<by_qx.size();i++)
        koji[by_qx[i].second]=i;
    ll ans=0;
    for(int i=0;i<by_r.size();i++)
    {
        int id=by_r[i].second;
        int L=x[id]-r[id];
        int R=x[id]+r[id];
        int iq=q[id];
        for(int i=iq-k;i<=iq+k;i++)
        {
            ans+=solve(i,L,R);
        }
        //printf("Dodajem %i\n",koji[id]);
        add(koji[id]+1);
    }
    printf("%lld\n",ans);
    return 0;
}