#include<cstdio>
#include<algorithm>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#include<cmath>
int n,q,tim,cnt,sig,S;
struct Qur{int x,y,t,i;}Qs[100001];
int a[100001],b[200001],blk[100001];
inline bool cmp(Qur p1,Qur p2){return blk[p1.x]==blk[p2.x]?(blk[p1.y]==blk[p2.y]?p1.t<p2.t:blk[p1.y]<blk[p2.y]):blk[p1.x]<blk[p2.x];}
int p[100001],k[100001],k_[100001],ans[100001];
int count1[200001],count2[100001];
inline void gx1(int i){--count2[count1[i]];++count2[++count1[i]];}
inline void gx2(int i){--count2[count1[i]];++count2[--count1[i]];}
int main(){
	scanf("%d%d",&n,&q); S=(int)pow(n,2.0/3.0);
	F(i,1,n) scanf("%d",a+i), b[i]=a[i], blk[i]=(i-1)/S+1;
	F(i,1,q){
		int opt,x,y; scanf("%d%d%d",&opt,&x,&y);
		if(opt==1) Qs[++cnt]=(Qur){x,y,tim,cnt};
		else ++tim, b[n+tim]=y, p[tim]=x, k_[tim]=a[x], k[tim]=a[x]=y;
	} F(i,1,n) a[i]=b[i];
	sort(Qs+1,Qs+cnt+1,cmp); sort(b+1,b+n+tim+1); sig=unique(b+1,b+n+tim+1)-b-1;
	F(i,1,n) a[i]=lower_bound(b+1,b+sig+1,a[i])-b;
	F(i,1,tim) k[i]=lower_bound(b+1,b+sig+1,k[i])-b, k_[i]=lower_bound(b+1,b+sig+1,k_[i])-b;
	count2[0]=sig+10;
	int l=1, r=0, t=0;
	F(i,1,cnt){
		while(Qs[i].x<l) gx1(a[--l]);
		while(Qs[i].y>r) gx1(a[++r]);
		while(Qs[i].x>l) gx2(a[l++]);
		while(Qs[i].y<r) gx2(a[r--]);
		while(Qs[i].t>t) ++t, (Qs[i].x<=p[t]&&p[t]<=Qs[i].y)?gx1(k[t]),gx2(k_[t]):void(0), a[p[t]]=k[t];
		while(Qs[i].t<t) (Qs[i].x<=p[t]&&p[t]<=Qs[i].y)?gx1(k_[t]),gx2(k[t]):void(0), a[p[t]]=k_[t], --t;
		for(ans[Qs[i].i]=1;count2[ans[Qs[i].i]];++ans[Qs[i].i]);
	}
	F(i,1,cnt) printf("%d\n",ans[i]);
	return 0;
}