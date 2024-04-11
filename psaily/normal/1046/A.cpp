#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct node{
	int x,r,s;
	bool operator <(const node &_)const{
		return r>_.r;
	}
}A[N];
int B[N];
struct Binary_Indexed_Tree{
	vector<int>num,sum;
	int n;
	void init(int x){
		num.push_back(x);
	}
	void build(){
		num.push_back(-1);
		sort(num.begin(),num.end());
		n=unique(num.begin(),num.end())-num.begin()-1;
		sum.resize(n+1);
	}
	void Add(int x){
		int i=upper_bound(num.begin(),num.begin()+n+1,x)-num.begin()-1;
		while (i<=n){
			sum[i]++;
			i+=i&-i;
		}
	}
	int Query(int x,int t=0){
		int i;
		if (t==0){
			i=upper_bound(num.begin(),num.begin()+n+1,x)-num.begin()-1;
		}else{
			i=lower_bound(num.begin(),num.begin()+n+1,x)-num.begin()-1;
		}
		int res=0;
		while (i>0){
			res+=sum[i];
			i-=i&-i;
		}
		return res;
	}
}BIT[N];
int main(){
	int n,K,i,j;
	scanf("%d%d",&n,&K);
	for (i=1;i<=n;i++){
		scanf("%d%d%d",&A[i].x,&A[i].r,&A[i].s);
		B[i]=A[i].s;
	}
	sort(A+1,A+1+n);
	sort(B+1,B+1+n);
	int h=unique(B+1,B+1+n)-B-1;
	for (i=1;i<=n;i++){
		A[i].s=lower_bound(B+1,B+1+h,A[i].s)-B;
		BIT[A[i].s].init(A[i].x);
	}
	for (i=1;i<=h;i++){
		BIT[i].build();
	}
	long long Ans=0;
	for (i=1;i<=n;i++){
		for (j=A[i].s;j>=1 && B[j]>=B[A[i].s]-K;j--){
			Ans+=BIT[j].Query(A[i].x+A[i].r)-BIT[j].Query(A[i].x-A[i].r,1);
		}
		for (j=A[i].s+1;j<=h && B[j]<=B[A[i].s]+K;j++){
			Ans+=BIT[j].Query(A[i].x+A[i].r)-BIT[j].Query(A[i].x-A[i].r,1);
		}
		BIT[A[i].s].Add(A[i].x);
	}
	printf("%lld\n",Ans);
	return 0;
}