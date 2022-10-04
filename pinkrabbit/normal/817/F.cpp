#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;

int n;
int t[100001],T=1;
LL L[100001],R[100001],B[200005];
LL S[524288]; int d[524288],f[524288];

void P(int i,LL len,int t){
	if(t==1) S[i]=len, d[i]=1, f[i]=0;
	if(t==2) S[i]=0, d[i]=2, f[i]=0;
	if(t==3) S[i]=len-S[i], f[i]^=1;
}

void PD(int i,int l,int r){
	if(d[i]) P(i<<1,B[(l+r>>1)+1]-B[l],d[i]), P(i<<1|1,B[r+1]-B[(l+r>>1)+1],d[i]), d[i]=0;
	if(f[i]) P(i<<1,B[(l+r>>1)+1]-B[l],3), P(i<<1|1,B[r+1]-B[(l+r>>1)+1],3), f[i]=0;
}

void Mdf(int i,int l,int r,int a,int b,int t){
	if(b<l||r<a) return;
	if(a<=l&&r<=b) return P(i,B[r+1]-B[l],t);
	PD(i,l,r);
	Mdf(i<<1,l,l+r>>1,a,b,t),
	Mdf(i<<1|1,(l+r>>1)+1,r,a,b,t);
	S[i]=S[i<<1]+S[i<<1|1];
}

LL Qur(int i,int l,int r){
	if(l==r) return B[l];
	PD(i,l,r);
	return S[i<<1]==B[(l+r>>1)+1]-B[l]?Qur(i<<1|1,(l+r>>1)+1,r):Qur(i<<1,l,l+r>>1);
}
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d%lld%lld",t+i,L+i,R+i), B[++T]=L[i], B[++T]=R[i]+1; B[1]=1;
	sort(B+1,B+T+1); T=unique(B+1,B+T+1)-B-1;
	F(i,1,n)
		L[i]=lower_bound(B+1,B+T+1,L[i])-B,
		R[i]=lower_bound(B+1,B+T+1,R[i]+1)-B-1;
	F(i,1,n){
		Mdf(1,1,T,L[i],R[i],t[i]);
		printf("%lld\n",Qur(1,1,T));
	}
	return 0;
}