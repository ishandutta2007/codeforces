#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int size=1048576;
int arr[2097152];
int lazy[2097152];
int minarr[2097152];
int maxarr[2097152];
char str[1000001];
int INF=1e9;

void propagate(int node, int nodel, int noder) {
	if (lazy[node]!=0) {
		minarr[node]+=lazy[node];
		maxarr[node]+=lazy[node];
		arr[node]+=(noder-nodel+1)*lazy[node];
		if (node<size) {
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

int sum(int l, int r, int node, int nodel, int noder) {
	propagate(node,nodel,noder);
	if (r<nodel||l>noder) {
		return 0;
	}
	if (l<=noder&&noder<=r) {
		return arr[node];
	}
	int mid=(nodel+noder)/2;
	return sum(l,r,node*2,nodel,mid)+sum(l,r,node*2+1,mid+1,noder);
}

int minsum(int l, int r, int node, int nodel, int noder) {
	propagate(node,nodel,noder);
	if (r<nodel||l>noder) {
		return 0;
	}
	if (l<=noder&&noder<=r) {
		return minarr[node];
	}
	int mid=(nodel+noder)/2;
	return min(minsum(l,r,node*2,nodel,mid),minsum(l,r,node*2+1,mid+1,noder));
}

int maxsum(int l, int r, int node, int nodel, int noder) {
	propagate(node,nodel,noder);
	if (r<nodel||l>noder) {
		return 0;
	}
	if (l<=noder&&noder<=r) {
		return maxarr[node];
	}
	int mid=(nodel+noder)/2;
	return max(maxsum(l,r,node*2,nodel,mid),maxsum(l,r,node*2+1,mid+1,noder));
}

void update(int l, int r, int node, int nodel, int noder, int val) {
	propagate(node,nodel,noder);
	if (r<nodel||l>noder) {
		return;
	}
	if (l<=nodel&&noder<=r) {
		lazy[node]+=val;
		propagate(node,nodel,noder);
		return;
	}
	int mid=(nodel+noder)/2;
	update(l,r,node*2,nodel,mid,val);
	update(l,r,node*2+1,mid+1,noder,val);
	arr[node]=arr[node*2]+arr[node*2+1];
	minarr[node]=min(minarr[node*2],minarr[node*2+1]);
	maxarr[node]=max(maxarr[node*2],maxarr[node*2+1]);
}

int main() {
	int n;
	scanf("%d\n", &n);
	int point=0;
	int len=0;
	int leng=0;
	for(int i=0;i<n;i++) {
		char x;
		scanf("%c",&x);
		if (x=='L') {
			len=max(0,len-1);
		}
		if (x=='R') {
			len+=1;
		}
		str[i]=x;
		leng=max(leng,len);
	}
	leng+=1;
	int stat=0;
	char ori[1000001];
	for(int i=0;i<n;i++) {
		if (str[i]=='L') {
			point=max(0,point-1);
		}
		else if (str[i]=='R') {
			point+=1;
		}
		else {
			if (ori[point]==')') {
			update(point,size-1,1,0,size-1,1);
			stat+=1;
			}
			if (ori[point]=='(') {
			update(point,size-1,1,0,size-1,-1);
			stat-=1;
			}
		if (str[i]=='(') {
			update(point,size-1,1,0,size-1,1);
			stat+=1;
		}
		if (str[i]==')') {
			update(point,size-1,1,0,size-1,-1);
			stat-=1;
		}
		ori[point]=str[i];
		}
		if (minsum(0,size-1,1,0,size-1)<0) {
			printf("-1 ");
			continue;
		}
		if (stat!=0) {
			printf("-1 ");
			continue;
		}
		printf("%d ",maxsum(0,size-1,1,0,size-1));
	}
	return 0;
}