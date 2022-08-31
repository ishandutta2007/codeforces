#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define f(i,n) for(int i=0;i<n;i++)
#define Fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getrand()
{
    uniform_int_distribution<int> uid(0*1LL, 9999999999999*1LL);
    return uid(rng);
}

struct node{
    int prior,size;
    int val;
    struct node *l,*r;
};

typedef node* pnode;

int sz(pnode t){
    return t?t->size:0;
}

void upd_sz(pnode t){
    if(t) t->size=sz(t->l)+1+sz(t->r);
}

void split(pnode t,pnode &l,pnode &r,int pos){
    
    if(!t) (l=r=NULL);
    else if(t->val<=pos) split(t->r,t->r,r,pos),l=t;
    else split(t->l,l,t->l,pos),r=t;
    
    upd_sz(t);
}

void merge(pnode &t,pnode l,pnode r)
{   
    if (!l || !r) t = l?l:r;
    else if (l->prior > r->prior) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    
    upd_sz(t);
}

void erase(pnode & t,int key)
{
    if(!t) return;
    
    else if(t-> val == key)  merge(t,t->l,t->r);
    else erase (key < t->val ? t->l : t->r, key);  
        
    upd_sz(t);    
}

pnode init(int val)
{
    pnode ret = new node();
    ret->prior=rand();
    ret->size=1;
    ret->val=val;
    ret->l = ret-> r = NULL;
    return ret;
}

int range_query(pnode t,int x)
{    
    
    if(t==NULL) return 0;
    
    int ans = 0;
    
    if(x < t->val) return range_query(t->l,x);

    return sz(t->l)+1+range_query(t->r,x);
    
}

void insert (pnode & t, pnode it) 
{
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->l, it->r , it->val),  t = it;
    else
        insert (it->val < t->val ? t->l : t->r, it);
    
    upd_sz(t);
}

const int N = 1e4+10;
const int NN = 1e5+10;

pnode aa[N];
pair<pair<int,int>,int> dat[NN];

bool comp(const pair<pair<int,int>,int> & a,const pair<pair<int,int>,int> & b)
{
    if(a.F.S == b.F.S) return a.F.F < b.F.F;
    return a.F.S < b.F.S;
}

signed main()
{
    Fast;
   
    int n,k,ans=0;
    
    cin >> n >> k;
    
    f(i,n)
    {
     cin >> dat[i].F.F >> dat[i].F.S >> dat[i].S;  
     
     insert(aa[dat[i].S],init(dat[i].F.F));   
    }
    
    sort(dat,dat+n,comp);
   
    f(i,n)    
    {
      for(int j=max(1LL,dat[i].S-k);j<=min(10000*1LL,dat[i].S+k);j++)
      {
          ans+=range_query(aa[j],dat[i].F.F+dat[i].F.S)-range_query(aa[j],dat[i].F.F-dat[i].F.S-1);     
      }
      erase(aa[dat[i].S],dat[i].F.F);
    }
    
    cout << ans-n;
}