#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

const int roz = (1<<20);

int t[roz];

void add(int lo,int hi,int u,int a,int b,int val)
{
    if(lo == a && b == hi)
    {
        t[u] += val;
        return;
    }
    if(b<=a) return;
    int mid = (lo + hi) / 2;
    add(lo,mid,u*2,a,min(b,mid),val);
    add(mid,hi,u*2+1,max(a,mid),b,val);
}

int ask(int pos)
{
    pos += roz/2;
    int ans = 0;
    while(pos >= 1)
    {
        ans += t[pos];
        pos /= 2;
    }
    return ans;
}

const int nax = 3e5 + 5;
int a[nax];
int n,q;

struct query
{
    int lo;
    int hi;
    int numer;
};

bool cmp(query x,query y)
{
    if(x.hi == y.hi) return x.numer < y.numer;
    return x.hi < y.hi;
}

int odp[nax];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<query> s;
    for(int i=1;i<=q;i++)
    {
        int x,y; cin>>x>>y;
        query nowa;
        nowa.lo = x + 1;
        nowa.hi = n - y;
        nowa.numer = i;
        s.pb(nowa);
    }
    sort(s.begin(),s.end(),cmp);
    for(int i=1;i<=n;i++) a[i] = i - a[i];
    int done = 0;
    for(int i=1;i<=n;i++)
    {
        int akt = a[i];
        if(akt >= 0 && ask(1) >= akt)
        {
            int lo = 1;
            int hi = i;

            while(lo + 1 < hi)
            {
                int mid = (lo + hi) / 2;
                int v = ask(mid);
                if(v >= akt) lo = mid;
                else hi = mid;
            }
            int ok = lo;
            if(ask(hi) >= akt) ok = hi;
            add(0,roz/2,1,1,ok+1,1);
        }
        while(done < q)
        {
            query teraz = s[done];
            int idx = teraz.numer;
            if(teraz.hi != i) break;
            odp[idx] = ask(teraz.lo);
            done++;
        }
    }

    for(int i=1;i<=q;i++) cout<<odp[i]<<"\n";



    return 0;
}