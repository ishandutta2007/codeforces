#include <bits/stdc++.h>
using namespace std;
   
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e5 + 10;

struct dat
{
    public : 
    
    int re,ag,agrank,id,l,r,cover;
    
    inline bool operator<(dat & o)
    {
        return re < o.re;
    }
};

struct qq
{
  int u,v,id,mx,l,r;
    
  inline bool operator<(qq & other)
  {
      return mx < other.mx;
  }
};

int res[N];

bool cmp(const dat & a,const dat & b)
{
    return a.id < b.id;
}

int f[N];

void add(int id)
{
    for(id++;id<N;id+=id&-id) f[id]++;
}

int sum(int x)
{
    int res = 0;
    for(x++;x>0;x-=x&-x) res+=f[x];
    return res;
}

vector<int> seg(2*N+100,-1);

void upd(int id,int val)
{
    id+=N;
    seg[id] = max(seg[id],val);
    
    for(;id>1;id>>=1) seg[id>>1] = max(seg[id],seg[id^1]);
}

int query(int l,int r)
{
    int res = -1;
    
    for(l+=N,r+=N+1;l<r;l>>=1,r>>=1)
    {
        if(l&1) res = max(res,seg[l++]);
        if(r&1) res = max(res,seg[--r]);
    }
    
    return res;
}

signed main()
{
    fast;
    
    int n,k;
    cin >> n >> k;
    
    dat a[n];
    
    f(i,n) cin >> a[i].re;
    f(i,n) cin >> a[i].ag;
    f(i,n) a[i].id = i;
    
    vector<int> temp(n);
    f(i,n) temp[i] = a[i].ag;
    sort(temp.begin(),temp.end());
    
    f(i,n) a[i].agrank = lower_bound(temp.begin(),temp.end(),a[i].ag) - temp.begin();
    f(i,n) a[i].r = upper_bound(temp.begin(),temp.end(),a[i].ag + k) - temp.begin() - 1;
    f(i,n) a[i].l = lower_bound(temp.begin(),temp.end(),a[i].ag - k) - temp.begin();
    
    sort(a,a+n);
    
    f(i,n)
    {
        add(a[i].agrank);
        a[i].cover = sum(a[i].r) - sum(a[i].l-1);
    }
    
    sort(a,a+n,cmp);
    
    int q;
    cin >> q;
    
    qq go[q];
    
    f(i,q) cin >> go[i].u >> go[i].v;
    f(i,q) go[i].u--,go[i].v--;
    f(i,q) if(a[go[i].u].ag > a[go[i].v].ag) swap(go[i].u,go[i].v);
    f(i,q) go[i].mx = max(a[go[i].u].re,a[go[i].v].re);
    f(i,q) go[i].id = i;
    f(i,q) go[i].l = a[go[i].v].l;
    f(i,q) go[i].r = a[go[i].u].r;
    
    sort(go,go+q);
    sort(a,a+n);
    
    int idd = n-1;
    
    for(int i=q-1;i>=0;i--)
    {
        while(idd >=0 && a[idd].re >= go[i].mx) 
        {
            upd(a[idd].agrank,a[idd].cover);
            idd--;    
        }
        
        res[go[i].id] = query(go[i].l,go[i].r);
    }
    
    f(i,q) cout << res[i] << '\n';
}