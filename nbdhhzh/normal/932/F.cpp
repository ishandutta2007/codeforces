#include<bits/stdc++.h>
#define L -100000
#define R 100000 
#define M 8000010
#define N 200010
using namespace std;
int ls[M],rs[M];
long long A[M],B[M],F[N];
int v[N],ne[N],head[N],a[N],b[N],dad[N],root[N];
int l,np,n,i,x,y;
void add(int x,int y){
	v[++l]=y;ne[l]=head[x];head[x]=l;
}
void pushdown(int l,int r,int &cur,long long a,long long b){
	if(!cur){
		cur=++np;
		A[cur]=a;
		B[cur]=b;
		return;
	}
	int mid=(l+r)/2;
	if(A[cur]+l*B[cur]>a+l*b)
		swap(A[cur],a),swap(B[cur],b);
	if(l==r)return;
	if(A[cur]+mid*B[cur]>a+mid*b){
		swap(A[cur],a);swap(B[cur],b);
		pushdown(l,mid,ls[cur],a,b);
	}else if(A[cur]+r*B[cur]>a+r*b)
		pushdown(mid+1,r,rs[cur],a,b);
}
void merge(int l,int r,int &cur1,int cur2){
	if(!cur1||!cur2){
		cur1|=cur2;
		return;
	}
	int mid=(l+r)/2;
	merge(l,mid,ls[cur1],ls[cur2]);
	merge(mid+1,r,rs[cur1],rs[cur2]);
	pushdown(l,r,cur1,A[cur2],B[cur2]);
}
long long ask(int l,int r,int cur,int k){
	if(!cur)return 1e18;
	long long ans=A[cur]+B[cur]*k;
	if(l==r)return ans;
	int mid=(l+r)/2;
	if(k<=mid)return min(ans,ask(l,mid,ls[cur],k));
	return min(ans,ask(mid+1,r,rs[cur],k));
}
void dfs(int x){
	for(int i=head[x];i;i=ne[i])
	if(dad[x]!=v[i]){
		dad[v[i]]=x;
		dfs(v[i]);
		merge(L,R,root[x],root[v[i]]);
	}
	F[x]=root[x]?ask(L,R,root[x],a[x]):0;
	pushdown(L,R,root[x],F[x],b[x]);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(1);
	for(i=1;i<=n;i++)
		printf("%I64d ",F[i]);
	puts("");
}