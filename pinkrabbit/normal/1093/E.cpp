#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
// luogu
const int MN=200005;

int n,q;
int P[MN],a[MN];

int t[MN*5],x[MN*5],y[MN*5],f[MN*5],id[MN*5],cnt;
int Ans[MN];
int p[MN*5],pt;
inline bool cmp(int i,int j){return x[i]==x[j]?y[i]==y[j]?t[i]<t[j]:y[i]<y[j]:x[i]<x[j];}

int b[MN];
inline void Mdf(int i,int x){for(;i<=n;i+=i&-i)b[i]+=x;}
inline int Qur(int i){int A=0;for(;i;i-=i&-i)A+=b[i];return A;}

void CDQ(int lb,int rb){
	if(lb==rb) return;
	int mid=lb+rb>>1;
	pt=0;
	F(i,lb,mid) if(!t[i]) p[++pt]=i;
	F(i,mid+1,rb) if(t[i]) p[++pt]=i;
	sort(p+1,p+pt+1,cmp);
	F(I,1,pt){
		int i=p[I];
		if(!t[i]) Mdf(y[i],f[i]);
		else Ans[id[i]]+=f[i]*Qur(y[i]);
	}
	F(i,lb,mid) if(!t[i]) Mdf(y[i],-f[i]);
	CDQ(lb,mid); CDQ(mid+1,rb);
}

int main(){
	int xx,qq=0;
	scanf("%d%d",&n,&q);
	F(i,1,n) scanf("%d",&xx), P[xx]=i;
	F(i,1,n) scanf("%d",a+i), a[i]=P[a[i]];
//	F(i,1,n) printf("%d ",a[i]); puts("");
	F(i,1,n) t[++cnt]=0, x[cnt]=i, y[cnt]=a[i], f[cnt]=1;
	F(i,1,q){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int l,r,lb,rb;
			scanf("%d%d%d%d",&l,&r,&lb,&rb);
			--l, --lb;
			++qq;
			t[++cnt]=1, x[cnt]=rb, y[cnt]=r, f[cnt]=1, id[cnt]=qq;
			t[++cnt]=1, x[cnt]=rb, y[cnt]=l, f[cnt]=-1, id[cnt]=qq;
			t[++cnt]=1, x[cnt]=lb, y[cnt]=r, f[cnt]=-1, id[cnt]=qq;
			t[++cnt]=1, x[cnt]=lb, y[cnt]=l, f[cnt]=1, id[cnt]=qq;
		}
		else{
			int xx,yy;
			scanf("%d%d",&xx,&yy);
			t[++cnt]=0, x[cnt]=xx, y[cnt]=a[xx], f[cnt]=-1;
			t[++cnt]=0, x[cnt]=yy, y[cnt]=a[yy], f[cnt]=-1;
			t[++cnt]=0, x[cnt]=xx, y[cnt]=a[yy], f[cnt]=1;
			t[++cnt]=0, x[cnt]=yy, y[cnt]=a[xx], f[cnt]=1;
			swap(a[xx],a[yy]);
		}
	}
	CDQ(1,cnt);
	F(i,1,qq) printf("%d\n",Ans[i]);
	return 0;
}