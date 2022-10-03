#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MS (1<<20|7)
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;
int a[MN],ia[MN],b[MN];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
#define ls li,l,mid
#define rs ri,mid+1,r
int mn[MS],tg[MS];
inline void P(int i,int x){mn[i]+=x,tg[i]+=x;}
inline void pd(int i){if(tg[i])P(li,tg[i]),P(ri,tg[i]),tg[i]=0;}
void Add(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b)return P(i,x);
	pd(i);
	Add(ls,a,b,x),Add(rs,a,b,x);
	mn[i]=min(mn[li],mn[ri]);
}
int Qur(int i,int l,int r,int a,int b){
	if(r<a||b<l)return n+1;
	if(a<=l&&r<=b)return mn[i];
	pd(i);
	return min(Qur(ls,a,b),Qur(rs,a,b));
}
bool ck(int v){
//	printf("\tck(%d) :\n\t\t", v);
//	printf("0");F(i,1,n)printf(",%d",Qur(1,1,n,i,i));puts("");
	int p=ia[v];
	int pre=p==1?0:min(0,Qur(1,1,n,1,p-1));
	int suf=Qur(1,1,n,p,n);
//	printf("\t\t[pre,suf]=[%d,%d]\n",pre,suf);
	return suf<=pre;
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),ia[a[i]]=i;
	F(i,1,n)scanf("%d",b+i);
	int j=n;
	Add(1,1,n,ia[j],n,1);
	F(i,1,n){
		while(ck(j))--j,Add(1,1,n,ia[j],n,1);
//		printf("ans[%d]=%d\n",i,j);
		printf("%d\n",j);
		Add(1,1,n,b[i],n,-1);
	}
	return 0;
}