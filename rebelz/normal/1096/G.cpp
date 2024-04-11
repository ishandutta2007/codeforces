#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353,g=3;
int n,sz;
int r[10000005],aa[10000005],bb[10000005],cc[10000005],ans[10000005],t[10000005];

int mod(int x){return x<cys?x:x-cys;}

int power(int x,int p){
	int ret=1;
	for(;p;p>>=1,x=1ll*x*x%cys) if(p&1) ret=1ll*ret*x%cys;
	return ret;
}

void ntt(int *A,int f){
	for(int i=0;i<n;i++) if(i<r[i]) swap(A[i],A[r[i]]);
	for(int i=1;i<n;i<<=1){
		int wn=power(g,(cys-1)/(i*2));
		if(f==-1) wn=power(wn,cys-2);
		for(int j=0;j<n;j+=(i<<1)){
			int w=1;
			for(int k=j;k<j+i;k++,w=1ll*w*wn%cys){
				int x=A[k],y=1ll*w*A[k+i]%cys;
				A[k]=mod(x+y); A[k+i]=mod(x-y+cys);
			}
		}
	}
}

void mul(int *A,int sa,int *B,int sb,int *C,int &sc){
//	cout<<"TEST "<<sa<<' '<<sb<<' '<<sc<<endl;
//	for(int i=0;i<sa;i++) cout<<A[i]<<' ';
//	cout<<endl;
//	for(int i=0;i<sb;i++) cout<<B[i]<<' ';
//	cout<<endl;
	int m=sa+sb,l=0;
	for(n=1;n<=m;n<<=1) l++;
	for(int i=0;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<n;i++) aa[i]=i<sa?A[i]:0;
	for(int i=0;i<n;i++) bb[i]=i<sb?B[i]:0;
	ntt(aa,1); ntt(bb,1);
//	cout<<"N "<<n<<endl;
	for(int i=0;i<n;i++) cc[i]=1ll*aa[i]*bb[i]%cys;
	ntt(cc,-1);
	for(int i=0;i<n;i++) C[i]=1ll*cc[i]*power(n,cys-2)%cys;
	sc=m;
//	cout<<"END "<<sa<<' '<<sb<<' '<<sc<<endl;
//	for(int i=0;i<n;i++) cout<<C[i]<<' ';
//	cout<<endl;
}

void solve(int *A,int s,int p){
	ans[0]=1,sz=1;
	for(;p;p>>=1,mul(A,s,A,s,A,s)) if(p&1) mul(ans,sz,A,s,ans,sz);
}

int main(){
	int n,m;
	n=readint(); m=readint();
	int x;
	for(int i=1;i<=m;i++){
		x=readint();
		t[x]=1;
	}
	solve(t,10,n/2);
	int ret=0;
	for(int i=0;i<sz;i++) ret=mod(ret+1ll*ans[i]*ans[i]%cys);
	printf("%d\n",ret);
	return 0;
}