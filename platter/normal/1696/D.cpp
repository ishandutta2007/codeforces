#include <bits/stdc++.h>
using namespace std;

int n;
typedef pair<int,int> P;
P seg[1048576];
int arr[500001];
int sz;

P merge(P a,P b) {
if (a==P(0,n+1)&&b==P(0,n+1)) return a;
    return P(arr[a.first]<arr[b.first]?a.first:b.first,arr[a.second]>arr[b.second]?a.second:b.second);
}

P sum(int l,int r,int node=1,int nodel=0,int noder=sz-1) {
    if (r<nodel||l>noder) {
        return P(0,n+1);
    }
    if (l<=nodel&&noder<=r) {
        return seg[node];
    }
    int mid=(nodel+noder)/2;
    return merge(sum(l,r,node*2,nodel,mid),sum(l,r,node*2+1,mid+1,noder));
}

int solve(int l,int r) {
    if (l==r) {
        return 0;
    }
    P got=sum(l,r);
    if (got.first==l&&got.second==r) {
        return 1;
    }
    if (got.second==l&&got.first==r) {
        return 1;
    }
    if (got.first!=l&&got.first!=r) {
        return solve(l,got.first)+solve(got.first,r);
    }
    return solve(l,got.second)+solve(got.second,r);
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&arr[i]);
        }
        arr[0]=n+1;
        arr[n+1]=0;
        sz=1;
        while (sz<n+1) {
            sz*=2;
        }
        for(int i=1;i<sz*2;i++) {
            seg[i]=P(0,n+1);
        }
for(int i=1;i<=n;i++) seg[i+sz]=P(i,i);
        for(int i=sz-1;i>0;i--) {
            seg[i]=merge(seg[i*2],seg[i*2+1]);
        }
        printf("%d\n",solve(1,n));
    }
    return 0;
}