#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define ll long long
using namespace std;
const int M=998244353,G=3,N=1<<20;
int Pw(int x,int y=M-2){return y?((y&1)?(ll)Pw((ll)x*x%M,y/2)*x%M:Pw((ll)x*x%M,y/2)%M):1;}
int rt[N],mg[N],fac[N],Lm=1;
int rev[N],a[N],iv;
void dft(int n){
	L(i,0,n-1)rev[i]=(rev[i>>1]>>1)|((i&1)*(n>>1)),((i<rev[i])&&(a[i]^=a[rev[i]]^=a[i]^=a[rev[i]]));
	for(int i=2;i<=n;i<<=1)
		for(int j=0,l=(i>>1);j<n;j+=i)
			for(int k=0,pa,pb,*w=rt+l;k<l;k++,w++)
				pa=a[j+k],pb=(ll)a[j+k+l]**w%M,a[j+k]=(pa+pb)%M,a[j+k+l]=(pa+M-pb)%M;
	L(i,0,n-1)a[i]=(ll)a[i]*iv%M;
}
int n,deg[N],cnt[N],ns,x,y,all;
int main(){
	cin>>n,fac[0]=deg[1]=1;
	L(i,1,n)fac[i]=(ll)fac[i-1]*i%M;
	L(i,1,n-1)cin>>x>>y,deg[x]+=1,deg[y]+=1;
	L(i,1,n)if(deg[i]>1)cnt[deg[i]-1]+=1,all+=1;
	for(;Lm<=all;Lm<<=1);
	int w=Pw(G,(M-1)/Lm);
	mg[0]=1,iv=Pw(Lm);
	L(i,1,Lm-1)mg[i]=(ll)mg[i-1]*w%M;
	for(int i=1,S;i<Lm;i<<=1){
		S=Pw(G,M-1-(M-1)/(i<<1)),rt[i]=1;
		L(j,i+1,i*2-1)rt[j]=(ll)rt[j-1]*S%M;
	}
	L(i,0,Lm-1)a[i]=1;
	L(i,1,n)if(cnt[i])for(int j=0,*w=mg;j<Lm;j++,w++)a[j]=(ll)a[j]*Pw(*w+i,cnt[i])%M;
	dft(Lm);
	L(i,0,all)(ns+=(ll)fac[n-i]*a[all-i]%M*((i&1)?M-1:1)%M)%=M;
	cout<<ns<<'\n';
	return 0;
}