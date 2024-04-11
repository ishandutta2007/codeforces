#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
typedef pair<P,int> Pi;
int ret[200000];
Pi query[200000];
int n,m;
int ori[200000];
P arr[200000];
int size=262144;
int seg[524288];

int sum(int l, int r, int node, int nodel, int noder) {
    if (l>noder||r<nodel) {
        return 0;
    }
    if (l<=nodel&&noder<=r) {
        return seg[node];
    }
    int mid=(nodel+noder)/2;
    return sum(l,r,node*2,nodel,mid)+sum(l,r,node*2+1,mid+1,noder);
}

void update(int i) {
    i+=size;
    seg[i]+=1;
    while (i>1) {
        i/=2;
        seg[i]=seg[i*2]+seg[i*2+1];
    }
}

bool compare(P a, P b) {
    if (a.first==b.first) {
        return a.second<b.second;
    }
    return a.first>b.first;
}

int find(int k) {
    int lo=0;
    int hi=size-1;
    int mid=(lo+hi)/2;
    while (lo<=hi) {
        mid=(lo+hi)/2;
        if (sum(0,mid-1,1,0,size-1)<k&&sum(0,mid,1,0,size-1)>=k) {
            return mid;
        }
        if (sum(0,mid,1,0,size-1)<k) {
            lo=mid+1;
        }
        else {
            hi=mid-1;
        }
    }
    return mid;
}

int main(void) {
    int n;
    scanf("%d\n", &n);
    for(int i=0;i<n;i++) {
        scanf("%d ", &ori[i]);
        arr[i].first=ori[i];
        arr[i].second=i;
    }
    sort(arr,arr+n,compare);
    scanf("\n%d\n", &m);
    for(int i=0;i<m;i++) {
        int x,y;
        scanf("%d %d\n", &x, &y);
        query[i]=Pi(P(x,y),i);
    }
    sort(query,query+m);
    int ind=0;
    for(int i=1;i<=n;i++) {
        update(arr[i-1].second);
        while (query[ind].first.first==i) {
            ret[query[ind].second]=ori[find(query[ind].first.second)];
            ind+=1;
        }
    }
    for(int i=0;i<m;i++) {
        printf("%d\n",ret[i]);
    }
    return 0;
}