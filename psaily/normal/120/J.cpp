#include<iostream>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=200000;
const int inf=(1<<30);
struct Point {
	double x,y;//
	int k;
	int id;//
};
int n;//
Point a[maxn];
int cx,cy;//
int k1,k2;
double cmin;
double dis(Point h,Point k) {
	return sqrt((h.x-k.x)*(h.x-k.x)+(h.y-k.y)*(h.y-k.y));
}
bool cmp(Point h,Point k) {
	if(h.x!=k.x) return h.x<k.x;
	return h.y<k.y;
}
int y[maxn],len;
bool cmp2(int i,int j) {
	return a[i].y<a[j].y;
}
void solve(int l,int r) {
	if(l==r) return ;
	if(l==r-1) {
		double tmp=dis(a[l],a[r]);
		if(tmp<cmin) cmin=tmp,cx=a[l].id,k1=a[l].k,cy=a[r].id,k2=a[r].k;
	}
	if(l==r-2) {
		double l1=dis(a[l],a[l+1]);
		double l2=dis(a[l+1],a[l+2]);
		double l3=dis(a[l],a[l+2]);
		if(l1<l2&&l1<l3) {
			if(l1<cmin) cmin=l1,cx=a[l].id,k1=a[l].k,cy=a[l+1].id,k2=a[l+1].k;
		}
		if(l2<l1&&l2<l3) {
			if(l2<cmin) cmin=l2,cx=a[l+1].id,k1=a[l+1].k,cy=a[l+2].id,k2=a[l+2].k;
		}
		if(l3<cmin) cmin=l3,cx=a[l].id,k1=a[l].k,cy=a[l+2].id,k2=a[l+2].k;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	len=0;
	for(int i=l; i<=r; i++) {
		if(fabs(a[i].x-a[mid].x)<cmin) {
			y[len++]=i;
		}
	}
	sort(y,y+len,cmp2);
	for(int i=0; i<len; i++) {
		for(int j=i+1,cnt=1; j<len&&cnt<=7; j++,cnt++) {
			double tmp=dis(a[y[i]],a[y[j]]);
			if(tmp<cmin) {
				cmin=tmp,cx=a[y[i]].id,k1=a[y[i]].k,cy=a[y[j]].id,k2=a[y[j]].k;
			}
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n)==1) {
		cmin=inf;
		for(int i=0; i<n; i++) {
			scanf("%lf%lf",&a[i].x,&a[i].y);
			if(a[i].x>=0&&a[i].y>=0) a[i].k=1;
			else if(a[i].x<0&&a[i].y<0) a[i].k=4;
			else if(a[i].x<0) a[i].k=2;
			else a[i].k=3;
			a[i].x=fabs(a[i].x);
			a[i].y=fabs(a[i].y);
			a[i].id=i+1;
		}
		sort(a,a+n,cmp);
		solve(0,n-1);
		printf("%d %d %d %d\n",cx,k1,cy,5-k2);
	}
	return 0;
}