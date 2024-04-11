#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define MN 200000

using std::max,std::min;
using std::vector;

const int INF = 0x3fffffff;

int n,a[MN+5],l[MN+5],r[MN+5];
int v[MN+5];

struct Segment{
	int l,r;
};

vector<Segment> s;

struct Node{
	int min,tag;
}T[MN*4+5];

void build(int k,int l,int r){
	T[k] = {INF,INF};
	if(l==r) return;
	int mid = (l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}

void pushtag(int k,int w){
	T[k].min = min(T[k].min,w);
	T[k].tag = min(T[k].tag,w);
}

void pushdown(int k){
	if(T[k].tag!=INF){
		pushtag(k<<1,T[k].tag);
		pushtag(k<<1|1,T[k].tag);
		T[k].tag = INF;
	}
}

void modify(int k,int l,int r,int L,int R,int w){
	if(l==L&&r==R){
		pushtag(k,w);
		return;
	}
	int mid = (l+r)>>1;
	pushdown(k);
	if(R<=mid) modify(k<<1,l,mid,L,R,w);
	else if(L>mid) modify(k<<1|1,mid+1,r,L,R,w);
	else modify(k<<1,l,mid,L,mid,w),modify(k<<1|1,mid+1,r,mid+1,R,w);
	T[k].min = min(T[k<<1].min,T[k<<1|1].min);
}

int query(int k,int l,int r,int L,int R){
	if(l==L&&r==R) return T[k].min;
	int mid = (l+r)>>1;
	pushdown(k);
	if(R<=mid) return query(k<<1,l,mid,L,R);
	if(L>mid) return query(k<<1|1,mid+1,r,L,R);
	return min(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		l[i] = INF;
		r[i] = -INF;
	}
	for(int i=1;i<=n;i++){
		l[a[i]] = min(l[a[i]],i);
		r[a[i]] = max(r[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		if(l[i]!=INF&&l[i]!=r[i]){
			s.push_back({l[i],r[i]});
		}
	}
	sort(s.begin(),s.end(),[](Segment a,Segment b)->bool{
		if(a.l != b.l){
			return a.l < b.l;
		}
		return a.r > b.r;
	});
	int ans = 0;
	for(Segment segment:s){
		v[segment.l]++;
		v[segment.r+1]--;
	}
	for(int i=1;i<=n;i++){
		v[i] += v[i-1];
		if(v[i]) ans++;
	}
	build(1,1,n);
	int cr = 0;
	int rf = 0;
	for(Segment segment:s){
		if(cr>=segment.r) continue;
		cr = segment.r;
		int g = query(1,1,n,segment.l,segment.r);
		if(g==INF){
			modify(1,1,n,segment.l,segment.r,rf+2);
			rf += 2;
		}else{
			modify(1,1,n,segment.l,segment.r,g+1);
			rf = g+1;
		}
	}
	printf("%d\n",ans-rf);
}

//f[r] = r+f[p]-p-1