#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=400005;
int l[Maxn],r[Maxn],L[Maxn],R[Maxn],n;
int tree1[Maxn*4],tree2[Maxn*4];
void modify1(int p,int l,int r,int pos,int val){
	if (l==r){
		tree1[p]=max(tree1[p],val);
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid){
		modify1(p*2,l,mid,pos,val);
	}
	else{
		modify1(p*2+1,mid+1,r,pos,val);
	}
	tree1[p]=max(tree1[p*2],tree1[p*2+1]);
}
void modify2(int p,int l,int r,int pos,int val){
	if (l==r){
		tree2[p]=min(tree2[p],val);
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid){
		modify2(p*2,l,mid,pos,val);
	}
	else{
		modify2(p*2+1,mid+1,r,pos,val);
	}
	tree2[p]=min(tree2[p*2],tree2[p*2+1]);
}
int query1(int p,int l,int r,int lo,int hi){
	if(lo>hi) return 0;
	if (lo<=l && r<=hi){
		return tree1[p];
	}
	int ans=0;
	int mid=l+r>>1;
	if (lo<=mid){
		ans=max(ans,query1(p*2,l,mid,lo,min(hi,mid)));
	}
	if (hi>mid){
		ans=max(ans,query1(p*2+1,mid+1,r,max(lo,mid+1),hi));
	}
	return ans;
}
int query2(int p,int l,int r,int lo,int hi){
	if (lo>hi) return 1e9;
	if (lo<=l && r<=hi){
		return tree2[p];
	}
	int ans=1e9;
	int mid=l+r>>1;
	if (lo<=mid){
		ans=min(ans,query2(p*2,l,mid,lo,min(hi,mid)));
	}
	if (hi>mid){
		ans=min(ans,query2(p*2+1,mid+1,r,max(lo,mid+1),hi));
	}
	return ans;
}
int ord[Maxn];
bool cmp(int x,int y){
	if (r[x]!=r[y]) return r[x]<r[y];
	return l[x]<l[y];
}
int main(){
	scanf("%d",&n);
	vector<int> A,B;
	for (int i=1;i<=n;i++){
		scanf("%d %d %d %d",&l[i],&r[i],&L[i],&R[i]);
		A.pb(l[i]);A.pb(r[i]);
		B.pb(L[i]);B.pb(R[i]);
	}
	sort(A.begin(),A.end());
	A.resize(unique(A.begin(),A.end())-A.begin());
	sort(B.begin(),B.end());
	B.resize(unique(B.begin(),B.end())-B.begin());
	for (int i=1;i<=n;i++){
		l[i]=lower_bound(A.begin(),A.end(),l[i])-A.begin()+1;
		r[i]=lower_bound(A.begin(),A.end(),r[i])-A.begin()+1;
		L[i]=lower_bound(B.begin(),B.end(),L[i])-B.begin()+1;
		R[i]=lower_bound(B.begin(),B.end(),R[i])-B.begin()+1;
	}
	for (int i=0;i<Maxn*4;i++){
		tree1[i]=0;tree2[i]=1e9;
	}
	for(int i=1;i<=n;i++){
		ord[i]=i;
	}
	sort(ord+1,ord+1+n,cmp);
	for(int ii=1;ii<=n;ii++){
		int i=ord[ii];
		int v1=query1(1,1,400000,l[i],400000);
		if (v1>R[i]){
			printf("NO\n");
			return 0;
		}
		int v2=query2(1,1,400000,l[i],400000);
		if (v2<L[i]){
			printf("NO\n");
			return 0;
		}
		modify1(1,1,400000,r[i],L[i]);
		modify2(1,1,400000,r[i],R[i]);
	}
	for(int i=1;i<=n;i++){
		swap(l[i],L[i]);
		swap(r[i],R[i]);
	}
	for (int i=0;i<Maxn*4;i++){
		tree1[i]=0;tree2[i]=1e9;
	}
	for(int i=1;i<=n;i++){
		ord[i]=i;
	}
	sort(ord+1,ord+1+n,cmp);
	for(int ii=1;ii<=n;ii++){
		int i=ord[ii];
		int v1=query1(1,1,400000,l[i],400000);
		if (v1>R[i]){
			printf("NO\n");
			return 0;
		}
		int v2=query2(1,1,400000,l[i],400000);
		if (v2<L[i]){
			printf("NO\n");
			return 0;
		}
		modify1(1,1,400000,r[i],L[i]);
		modify2(1,1,400000,r[i],R[i]);
	}
	printf("YES\n");
	return 0;
}
/*
2
3 3 9 10
1 3 7 9
*/