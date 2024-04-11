#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int tot, root;
map<int,int> mp;
struct node
{
    int l, r, val; bool cov;
    ll lsum, sum;
} tree[maxn*50];
void pushdown(int rt,int l,int r)
{
    if(!tree[rt].cov) return ;
    int mid = (l+r)>>1;
    if(!tree[rt].l) tree[rt].l = ++tot;
    if(!tree[rt].r) tree[rt].r = ++tot;
    int ls = tree[rt].l, rs = tree[rt].r;
    tree[ls].cov = 1;
    tree[ls].val = tree[rt].val;
    tree[ls].sum = (ll)(mid-l+1)*tree[rt].val;
    tree[ls].lsum = tree[rt].val < 0 ? tree[ls].sum : 0;
    tree[rs].cov = 1;
    tree[rs].val = tree[rt].val;
    tree[rs].sum = (ll)(r-mid)*tree[rt].val;
    tree[rs].lsum = tree[rt].val < 0 ? tree[rs].sum : 0;
    tree[rt].cov = tree[rt].val = 0;
}
void update(int &rt,int L,int R,int l,int r,int x)
{
    if(!rt) rt = ++tot;
    if(l >= L && r <= R){
        tree[rt].cov = 1; tree[rt].val = x;
        tree[rt].sum = (ll)(r-l+1)*x;
        tree[rt].lsum = x < 0 ? tree[rt].sum : 0;
        return ;
    }
    pushdown(rt,l,r);
    int mid = (l+r)>>1;
    if(mid >= L) update(tree[rt].l,L,R,l,mid,x);
    if(mid < R) update(tree[rt].r,L,R,mid+1,r,x);
    tree[rt].sum = tree[tree[rt].l].sum+tree[tree[rt].r].sum;
    tree[rt].lsum = min(tree[tree[rt].l].lsum,tree[tree[rt].l].sum+tree[tree[rt].r].lsum);
}
pair<double,ll> query(int &rt,int L,int R,int l,int r,ll x)
{
    if(!rt) return make_pair(0,0);
    if(l == L && r == R){
        if(x+tree[rt].lsum > 0) return make_pair(-1,tree[rt].sum);
        if(l == r || tree[rt].cov) return make_pair(L-x*1.0/(tree[rt].sum/(r-l+1)),tree[rt].sum);
    }
    pushdown(rt,l,r);
    int mid = (l+r)>>1;
    if(mid >= R) return query(tree[rt].l,L,R,l,mid,x);
    else if(mid < L) return query(tree[rt].r,L,R,mid+1,r,x);
    else{
        pair<double,ll> tmp1 = query(tree[rt].l,L,mid,l,mid,x);
        if(tmp1.first > 0) return tmp1;
        else{
            pair<double,ll> tmp2 = query(tree[rt].r,mid+1,R,mid+1,r,x+tmp1.second);
            return make_pair(tmp2.first,tmp1.second+tmp2.second);
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, op, x, y, z;
    cin >> n;
    int L = 1, R = 1e9;
    mp[L-1] = mp[R+1] = 0;
    cout << fixed << setprecision(9);
    while(n--){
        cin >> op >> x;
        if(op == 1){
            cin >> y;
            mp[x] = y;
            auto it = mp.find(x); it++;
            update(root,x,(*it).first-1,L,R,y);
        }
        else if(op == 2){
            auto it = mp.find(x), pre = it, nxt = it;
            --pre; ++nxt;
            update(root,x,(*nxt).first-1,L,R,(*pre).second);
            mp.erase(it);
        }
        else{
            cin >> y >> z;
            if(z == 0){ cout << x << '\n'; continue; }
            auto it = mp.lower_bound(x);
            if((*it).first >= y){ cout << "-1\n"; continue; }
            pair<double,ll> ans = query(root,(*it).first,y-1,L,R,z);
            //cout<<"*"<<ans.first<<" "<<ans.second<<endl;
            if(ans.first < 0) cout << "-1\n";
            else cout << ans.first << '\n';
        }
    }
    return 0;
}