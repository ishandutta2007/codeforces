#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
const int INF=1e6;
const int sz=262144;
int seg[sz*2];
int lazy[sz*2];
set<P> s; //P(l,-r)
set<P> rs; //P(-r,l)
int tree[200001];
 
int fsum(int i) {
    int ret=0;
    i++;
    while (i>0) {
        ret+=tree[i];
        i-=(i&-i);
    }
    return ret;
}
 
void upd(int i,int val) {
    i++;
    while (i<=200000) {
        tree[i]+=val;
        i+=(i&-i);
    }
}
 
void propagate(int node) {
    if (lazy[node]!=0) {
        seg[node]+=lazy[node];
        if (node<sz) {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
 
int sum(int l,int r,int node=1,int nodel=0,int noder=sz-1) {
    if (r<nodel||l>noder) {
        return INF;
    }
    if (l<=nodel&&noder<=r) {
        return seg[node];
    }
    int mid=(nodel+noder)/2;
    return min(sum(l,r,node*2,nodel,mid),sum(l,r,node*2+1,mid+1,noder));
}
 
void update(int i,int val) {
    i+=sz;
    seg[i]=val;
    while (i>1) {
        i/=2;
        seg[i]=min(seg[i*2],seg[i*2+1]);
    }
}
set<int> alive;
 
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++) {
        alive.insert(i);
        upd(i,1);
        update(i,INF);
    }
    for(int i=0;i<q;i++) {
        int t;
        scanf("%d",&t);
        if (t==0) {
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            l--;
            r--;
            if (x==0) {
                auto iter=alive.lower_bound(l);
                vector<int> er;
                while (iter!=alive.end()) {
                    if ((*iter)>r) {
                        break;
                    }
                    er.push_back(*iter);
                    iter++;
                }
                for(int i=0;i<er.size();i++) {
                    alive.erase(er[i]);
                }
            }
            else {
                if (seg[l+sz]>r)
                update(l,r);
            }
        }
        else {
            int pos;
            scanf("%d",&pos);
            pos--;
            if (alive.find(pos)==alive.end()) {
                printf("NO\n");
                continue;
            }
            auto iter=alive.find(pos);
            int l=0;
            int r=n-1;
            if (iter!=alive.begin()) {
                l=(*(prev(iter)))+1;
            }
            iter++;
            if (iter!=alive.end()) {
                r=(*iter)-1;
            }
            if (sum(l,r)<=r) {
                printf("YES\n");
            }
            else {
                printf("N/A\n");
            }
        }
    }
    return 0;
}