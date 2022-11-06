#include <bits/stdc++.h>
using i64 = long long;
template<class Info,
	class Merge=std::plus<Info>>
struct SegmentTree{
	const int n;
	const Merge merge;
	std::vector<Info> info;
	SegmentTree(int n):n(n),merge(Merge()),info(4 << std::__lg(n)){}
	SegmentTree(std::vector<Info> init):SegmentTree(init.size()){
		std::function<void(int,int,int)> build=[&](int p, int l, int r){
			if(r-l==1){
				info[p]=init[l];
				return;
			}
			int m=(l+r)/2;
			build(2*p,l,m);
			build(2*p+1,m,r);
			pull(p);
		};
		build(1,0,n);
	}
	void pull(int p){
		info[p]=merge(info[2*p],info[2*p+1]);
	}
	void modify(int p,int l,int r,int x,const Info &v){
		if(r-l==1){
			info[p]=v;
			return;
		}
		int m=(l+r)/2;
		if(x<m){
			modify(2*p,l,m,x,v);
		}
		else{
			modify(2*p+1,m,r,x,v);
		}
		pull(p);
	}
	void modify(int p,const Info &v){
		modify(1,0,n,p,v);
	}
	Info rangeQuery(int p,int l,int r,int x,int y){
		if(l>=y||r<=x){
			return Info();
		}
		if (l >= x && r <= y) {
			return info[p];
		}
		int m = (l + r) / 2;
		return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
	}
	Info rangeQuery(int l, int r) {
		return rangeQuery(1, 0, n, l, r);
	}
};
int x, y;
struct Info {
	double f[3][3];
	Info(i64 n = 0) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i + j > 2) {
					f[i][j] = -1E18;
				} else {
					f[i][j] = (j == 0 ? 0.0 : 1.0 * n / (j == 1 ? x + y : y));
				}
			}
		}
	}
};
Info operator+(const Info &a, const Info &b) {
	Info c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c.f[i][j] = -1E18;
			for (int k = 0; k < 3; k++) {
				c.f[i][j] = std::max(c.f[i][j], a.f[i][k] + b.f[k][j]);
			}
		}
	}
	return c;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("%d%d",&x,&y);
	if(x>y){
		std::swap(x,y);
	}
	std::vector<int> b;
	b.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	SegmentTree seg(std::vector<Info>(b.begin(),b.end()));
	for (int i = 0; i < q; i++) {
		int t;
		std::cin >> t;
		if (t == 1) {
			int k, v;
			scanf("%d%d",&k,&v);
			k--;
			seg.modify(k, v);
		} else {
			int l, r;
			scanf("%d%d",&l,&r);
			l--;
			auto info = seg.rangeQuery(l, r) + Info();
			printf("%.10lf\n",info.f[0][0]);
		}
	}
	return 0;
}