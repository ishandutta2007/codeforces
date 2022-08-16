#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l = 0, int r = 999999999)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

typedef struct item * pitem;
    
struct item {
    int prior, value, cnt;
    bool rev;
    pitem l, r;
    
    item(int a,int b)
    {
        prior = b;
        value = a;
        cnt = 1;
        rev = 0;
        l = r = NULL;
    }
};

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

int get(pitem t,int key,int add = 0)
{
    push(t);
    
    int cur_key = add + cnt(t->l);
    
    if(key < cur_key) return get(t->l,key,add);
    else if(key > cur_key) return get(t->r,key,add + 1 + cnt(t->l));
    else return t->value;
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

void output (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    cout<< (t->value) << ' ';
    output (t->r);
}

void shift(pitem t,int l,int r)
{
    pitem t1, t2, t3,t4;
    
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    split(t2, t2,t4, r-l);
    
    merge (t, t1, t4);
    merge(t, t, t2);
    merge (t, t, t3);    
}

void heapify (pitem t) {
    if (!t) return;
    pitem max = t;
    if (t->l != NULL && t->l->prior > max->prior)
        max = t->l;
    if (t->r != NULL && t->r->prior > max->prior)
        max = t->r;
    if (max != t) {
        swap (t->prior, max->prior);
        heapify (max);
    }
}

pitem build (int * a, int n) {
    
    // Construct a treap on values {a[0], a[1], ..., a[n - 1]}
    if (n == 0) return NULL;
    int mid = n / 2;
    pitem t = new item (a[mid],getRand());
    t->l = build (a, mid);
    t->r = build (a + mid + 1, n - mid - 1);
    heapify (t);
    upd_cnt(t);
    
    return t;
}

signed main()
{
    fast;
    
    int n,q,m;
    cin >> n >> q >> m;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    pitem go = build(a,n);
    
    int x,y,z;
    
    while(q--)
    {
        cin >> x >> y >> z;
        y--; z--;
    
        if(x == 1) shift(go,y,z);
        else reverse(go,y,z);
    }
    
    while(m--)
    {
        cin >> x; x--;
        cout << get(go,x) << ' ';
    }
    
}