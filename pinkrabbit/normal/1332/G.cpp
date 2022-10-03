#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define MS (1<<19|7)
#define ll long long
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,q;
int a[MN],val[MN];
int r3[MN],r4[MN],mni3[MN],mni4[MN];
int x3[MN],x4[MN],y4[MN];
int stk1[MN],stk2[MN],tp1,tp2;
set<int> myst;
int main(){
	scanf("%d%d",&n,&q);
	F(i,1,n)scanf("%d",a+i),r3[i]=r4[i]=n+1;
	myst.insert(n+1);
	dF(i,n,1){
		while(tp1&&a[stk1[tp1]]<a[i]){
			if(!--val[stk1[tp1]])myst.insert(stk1[tp1]);
			--tp1;
		}
		while(tp2&&a[stk2[tp2]]>a[i]){
			if(!--val[stk2[tp2]])myst.insert(stk2[tp2]);
			--tp2;
		}
		stk1[++tp1]=i,stk2[++tp2]=i;
		val[i]=2;
		int pos1=lower_bound(stk1+1,stk1+tp1+1,i,[](int x,int y){return a[x]>a[y];})-stk1-1;
		int pos2=lower_bound(stk2+1,stk2+tp2+1,i,[](int x,int y){return a[x]<a[y];})-stk2-1;
		pos1=pos1>0?stk1[pos1]:n+1;
		pos2=pos2>0?stk2[pos2]:n+1;
		//3
		if(pos1==n+1&&pos2==n+1)continue;
		if(pos1<pos2){
			int pos3=myst.empty()?n+1:*myst.begin();
			int pos4=lower_bound(stk2+1,stk2+tp2+1,pos1,[](int x,int y){return x>y;})-stk2-1;
			pos4=pos4>0?stk2[pos4]:n+1;
			r3[i]=min(pos3,pos4);
		}else{
			int pos3=myst.empty()?n+1:*myst.begin();
			int pos4=lower_bound(stk1+1,stk1+tp1+1,pos2,[](int x,int y){return x>y;})-stk1-1;
			pos4=pos4>0?stk1[pos4]:n+1;
			r3[i]=min(pos3,pos4);
		}
		//4
		int mxpos=max(pos1,pos2);
		if(mxpos<=n)r4[i]=*myst.upper_bound(mxpos);
		//
		if(r3[i]<=n){
			int pos5=*upper_bound(stk1+1,stk1+tp1+1,r3[i],[](int x,int y){return x>y;});
			int pos6=*upper_bound(stk2+1,stk2+tp2+1,r3[i],[](int x,int y){return x>y;});
			if(a[pos5]>max(a[i],a[r3[i]]))x3[i]=pos5;
			else x3[i]=pos6;
		}
		if(r4[i]<=n){
			int pos5=*upper_bound(stk1+1,stk1+tp1+1,r4[i],[](int x,int y){return x>y;});
			int pos6=*upper_bound(stk2+1,stk2+tp2+1,r4[i],[](int x,int y){return x>y;});
			x4[i]=min(pos5,pos6),y4[i]=max(pos5,pos6);
		}
	}
//	F(i,1,n)printf("r3[%d]=%d\n",i,r3[i]);
//	F(i,1,n)printf("r4[%d]=%d\n",i,r4[i]);
	mni3[n]=mni4[n]=n;
	dF(i,n-1,1){
		mni3[i]=r3[i]<r3[mni3[i+1]]?i:mni3[i+1];
		mni4[i]=r4[i]<r4[mni4[i+1]]?i:mni4[i+1];
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int i3=mni3[l],i4=mni4[l];
		if(r4[i4]<=r){
			puts("4");
			printf("%d ",i4);
			printf("%d %d ",x4[i4],y4[i4]);
			printf("%d\n",r4[i4]);
		}else if(r3[i3]<=r){
			puts("3");
			printf("%d ",i3);
			printf("%d ",x3[i3]);
			printf("%d\n",r3[i3]);
		}else puts("0\n");
	}
	return 0;
}

/*
6 1000
3 1 4 1 5 9
1 3
4 6


5 0
2 1 3 4 2

*/