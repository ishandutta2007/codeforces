#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353,g=3,invg=332748118;
int N,A,B;
int r[1100000],fac[1100000],inv[1100000];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void ntt(vector<int> &A,int n,int f){
	for(int i=0;i<n;i++) if(i<r[i]) swap(A[i],A[r[i]]);
	for(int i=1;i<n;i<<=1){
		int wn=qpow(f==1?g:invg,(cys-1)/(i<<1));
		for(int j=0;j<n;j+=(i<<1)){
			int w=1;
			for(int k=j;k<j+i;k++,w=1ll*w*wn%cys){
				int x=A[k],y=1ll*w*A[k+i]%cys;
				A[k]=mod(x+y); A[k+i]=mod(x+cys-y);
			}
		}
	}
}

vector<int> getstl(int ll,int rr,int x){
	if(ll==rr){
		vector<int> ans;
		ans.resize(2);
		ans[1]=1,ans[0]=ll-1;
		return ans;
	}
	int mid=(ll+rr)/2;
	vector<int> lson=getstl(ll,mid,0),rson=getstl(mid+1,rr,1),ans;
	int m=rr-ll+1,n=1,l=0;
	while(n<=m) n<<=1,l++;
	for(int i=0;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	lson.resize(n); rson.resize(n); ans.resize(n);
	ntt(lson,n,1); ntt(rson,n,1);
	for(int i=0;i<n;i++) ans[i]=1ll*lson[i]*rson[i]%cys;
	ntt(ans,n,-1);
	for(int i=0;i<=m;i++) ans[i]=1ll*ans[i]*qpow(n,cys-2)%cys;
	return ans;
}

int solve(int n,int m){
	if(m>n) return 0;
	if(n==0){
		if(m==0) return 1;
		else return 0;
	}
	return getstl(1,n,1)[m];
}

int main(){
	N=readint(); A=readint(); B=readint();
	N--;
	fac[0]=inv[0]=1;
	for(int i=1;i<=A+B-2;i++) fac[i]=1ll*fac[i-1]*i%cys;
	for(int i=1;i<=A+B-2;i++) inv[i]=qpow(fac[i],cys-2);
	cout<<1ll*solve(N,A+B-2)*fac[A+B-2]%cys*inv[A-1]%cys*inv[B-1]%cys<<endl;
	return 0;
}