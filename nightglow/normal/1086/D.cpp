#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n,m;
set<int>G[5];
set<int>::iterator gtw;
struct node {
	int mi,a[4];
	inline void clear() {
		for (int i=1;i<=3;i++) a[i]=0;
		mi=n+1;
	}
}f[N*4],AL,AR;
int a[N];
char c[N];
inline node up(node x,node y) {
	node ss;
	ss.clear();
	for (int i=1;i<=3;i++) {
		ss.a[i]=x.a[i]+y.a[i];
		ss.mi=min(ss.mi,ss.a[i]);
	}
	return ss;
}
inline void build(int o,int l,int r) {
	f[o].a[1]=f[o].a[2]=f[o].a[3]=0;
	if (l==r) {
		f[o].a[1]=f[o].a[2]=f[o].a[3]=0;
		f[o].a[a[l]]=1;
		f[o].mi=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
	f[o]=up(f[o*2],f[o*2+1]);
}
inline void change(int o,int l,int r,int ll,int p) {
	if (l==r) {
		f[o].a[a[l]]--;
		a[l]=p;
		f[o].a[a[l]]++;
		return ;
	}
	int mid=(l+r)>>1;
	if (ll<=mid) change(o*2,l,mid,ll,p);
	else change(o*2+1,mid+1,r,ll,p);
	f[o]=up(f[o*2],f[o*2+1]);
}
inline int askl(int o,int l,int r) {
	if (l==r) return l;
	int mid=(l+r)>>1;
	node gt=up(AL,f[o*2]);
	if (!gt.mi) {
		AL=gt;
		return askl(o*2+1,mid+1,r);
	}
	else return askl(o*2,l,mid);
}
inline int askr(int o,int l,int r) {
	if (l==r) return l;
	int mid=(l+r)>>1;
	node gt=up(AR,f[o*2+1]);
	if (!gt.mi) {
		AR=gt;
		return askr(o*2,l,mid);
	}
	else return askr(o*2+1,mid+1,r);
}
inline void ask() {
	if (f[1].mi==0) {
		int s=0;
		for (int i=1;i<=3;i++) if (f[1].a[i]) s++;
		if (s==1) {
			printf("%d\n",n);
			return ;
		}
		if (!f[1].a[1]) {
			printf("%d\n",f[1].a[3]);
			return ;
		}
		if (!f[1].a[2]) {
			printf("%d\n",f[1].a[1]);
			return ;
		}
		if (!f[1].a[3]) {
			printf("%d\n",f[1].a[2]);
			return ;
		}
	}
	AL.clear();
	AR.clear();
	int R=askr(1,1,n);
	int L=askl(1,1,n);
	L--,R++;
	if (L<R) {
		int ans=R-L-1;
		if (!AL.a[1]) ans+=AL.a[3]+(*G[3].begin())-1;
		if (!AL.a[2]) ans+=AL.a[1]+(*G[1].begin())-1;
		if (!AL.a[3]) ans+=AL.a[2]+(*G[2].begin())-1;
		if (!AR.a[1]) {
			gtw=G[3].end();
			gtw--;
			ans+=AR.a[3]+n-(*gtw);
		}
		if (!AR.a[2]) {
			gtw=G[1].end();
			gtw--;
			ans+=AR.a[1]+n-(*gtw);
		}
		if (!AR.a[3]) {
			gtw=G[2].end();
			gtw--;
			ans+=AR.a[2]+n-(*gtw);
		}
		printf("%d\n",ans);
	}
	else {
		int ans=0;
		if (a[L]==1) {
			if (*G[2].begin()<L) {
				ans+=*G[2].begin()-1;
				ans+=AL.a[2];
				ans+=AR.a[1]-(L-R+1);
				gtw=G[1].end();
				gtw--;
				ans+=n-(*gtw);
			}
			else {
				gtw=G[2].end();
				gtw--;
				ans+=n-(*gtw);
				ans+=AR.a[2];
				ans+=AL.a[1]-(L-R+1);
				ans+=(*G[1].begin())-1;
			}
		}
		if (a[L]==2) {
			if (*G[3].begin()<L) {
				ans+=*G[3].begin()-1;
				ans+=AL.a[3];
				ans+=AR.a[2]-(L-R+1);
				gtw=G[2].end();
				gtw--;
				ans+=n-(*gtw);
			}
			else {
				gtw=G[3].end();
				gtw--;
				ans+=n-(*gtw);
				ans+=AR.a[3];
				ans+=AL.a[2]-(L-R+1);
				ans+=(*G[2].begin())-1;
			}
		}
		if (a[L]==3) {
			if (*G[1].begin()<L) {
				ans+=*G[1].begin()-1;
				ans+=AL.a[1];
				ans+=AR.a[3]-(L-R+1);
				gtw=G[3].end();
				gtw--;
				ans+=n-(*gtw);
			}
			else {
				gtw=G[1].end();
				gtw--;
				ans+=n-(*gtw);
				ans+=AR.a[1];
				ans+=AL.a[3]-(L-R+1);
				ans+=(*G[3].begin())-1;
			}
		}
		printf("%d\n",ans);
	}
}
int main() {
//	freopen("0.in","r",stdin);
	scanf("%d%d",&n,&m);
	scanf("%s",c);
	for (int i=1;i<=n;i++) {
		if (c[i-1]=='R')
		a[i]=1;
		if (c[i-1]=='P')
		a[i]=2;
		if (c[i-1]=='S')
		a[i]=3;
		G[a[i]].insert(i);
	}
	build(1,1,n);
	ask();
	for (int i=1;i<=m;i++) {
		int x;
		scanf("%d",&x);
		G[a[x]].erase(x);
		char c=getchar();
		int y=0;
		while (c!='R'&&c!='P'&&c!='S') c=getchar();
		if (c=='R')
		y=1;
		if (c=='P')
		y=2;
		if (c=='S')
		y=3;
		change(1,1,n,x,y);
		G[a[x]].insert(x);
		ask();
	}
}