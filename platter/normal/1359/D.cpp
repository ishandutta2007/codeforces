#include <bits/stdc++.h>
using namespace std;

struct Node {
	long long sum,lsum,rsum,lrsum;
};

const long long INF=1e17;

Node merge(Node l,Node r) {
	Node ret;
	ret.sum=l.sum+r.sum;
	ret.lsum=max(l.lsum,l.sum+r.lsum);
	ret.rsum=max(r.rsum,r.sum+l.rsum);
	ret.lrsum=max(max(l.lrsum,r.lrsum),l.rsum+r.lsum);
	return ret;
}

const int sz=131072;
Node seg[sz*2];
int arr[100000];

void init() {
	for(int i=sz;i<sz*2;i++) {
		seg[i]={0,0,0,0};
	}
	for(int i=sz-1;i>0;i--) {
		seg[i]=merge(seg[i*2],seg[i*2+1]);
	}
}

Node sum(int l,int r,int node=1,int nodel=0,int noder=sz-1) {
	if (r<nodel||l>noder)
	return {0,-INF,-INF,-INF};
	if (l<=nodel&&noder<=r) {
		return seg[node];
	}
	int mid=(nodel+noder)/2;
	return merge(sum(l,r,node*2,nodel,mid),sum(l,r,node*2+1,mid+1,noder));
}

void update(int i,long long val) {
	i+=sz;
	seg[i].sum+=val;
	seg[i]={seg[i].sum,seg[i].sum,seg[i].sum,seg[i].sum};
	while (i>1) {
		i/=2;
		seg[i]=merge(seg[i*2],seg[i*2+1]);
	}
}

typedef pair<int,int> P;
P save[100000];

int main(void) {
    int n;
    scanf("%d",&n);
    init();
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        update(i,arr[i]);
        save[i]=P(arr[i],i);
    }
    int ret=0;
    sort(save,save+n);
    set<int> s;
    s.insert(-1);
    s.insert(n);
    for(int i=n-1;i>=0;i--) {
        int l=*prev(s.lower_bound(save[i].second))+1;
        int r=*s.upper_bound(save[i].second)-1;
        int sm=sum(l,r).lrsum;
        ret=max(ret,sm-arr[save[i].second]);
	s.insert(save[i].second);
    }
    printf("%d",ret);
}