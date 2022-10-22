#include <bits/stdc++.h>
using namespace std;

const int sz=524288;
int arr[300001];
int val[300001]; //maximum left to remove it

struct SegmentTree {
    int seg[sz*2];
    int find(int k,int node=1,int nodel=0,int noder=sz-1) {
        if (nodel==noder) {
            return nodel;
        }
        int mid=(nodel+noder)/2;
        if (seg[node*2]>=k) {
            return find(k,node*2,nodel,mid);
        }
        else {
            return find(k-seg[node*2],node*2+1,mid+1,noder);
        }
    }
    void update(int i,int val) {
        i+=sz;
        seg[i]+=val;
        while (i>1) {
            i/=2;
            seg[i]=seg[i*2]+seg[i*2+1];
        }
    }
    int sum(int l,int r,int node=1,int nodel=0,int noder=sz-1) {
        if (r<nodel||l>noder) {
            return 0;
        }
        if (l<=nodel&&noder<=r) {
            return seg[node];
        }
        int mid=(nodel+noder)/2;
        return sum(l,r,node*2,nodel,mid)+sum(l,r,node*2+1,mid+1,noder);
    }
};

SegmentTree st;

typedef pair<int,int> P;
typedef pair<P,int> Pi;
Pi query[600000];
int ret[300001];

int main(void) {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++) {
        if (arr[i]>i) {
            val[i]=0;
            continue;
        }
        if (st.sum(0,n)<i-arr[i]) {
            val[i]=0;
            continue;
        }
        if (arr[i]==i) {
            val[i]=i;
        }
        else {
            val[i]=st.find(st.sum(0,n)+1-(i-arr[i]));
        }
        st.update(val[i],1);
    }
    for(int i=0;i<q;i++) {
        int l,r;
        int x,y;
        scanf("%d %d",&x,&y);
        l=x+1;
        r=n-y;
        query[i*2]=Pi(P(l-1,l),-i-1);
        query[i*2+1]=Pi(P(r,l),i+1);
    }
    sort(query,query+q*2);
    int ind=0;
    memset(st.seg,0,sizeof(st.seg));
    for(int i=0;i<=n;i++) {
        if (i!=0) {
            st.update(val[i],1);
        }
        while (ind<2*q&&query[ind].first.first==i) {
            if (query[ind].second<0) {
                ret[-query[ind].second]-=st.sum(query[ind].first.second,sz-1);
            }
            else {
                ret[query[ind].second]+=st.sum(query[ind].first.second,sz-1);
            }
            ind++;
        }
    }
    for(int i=1;i<=q;i++) {
        printf("%d\n",ret[i]);
    }
}