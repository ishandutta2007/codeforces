#include <cstdio>
#include <algorithm>
namespace IO{
	const int SIZE=(1<<21)+1;
	char ibuf[SIZE],*iS,*iT;
	#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*(iS++))):*(iS++))
	template<typename Elem>
	void read(Elem &a){
		a=0;
		char c=gc();
		while(c<'0'||c>'9'){
			c=gc();
		}
		while(c>='0'&&c<='9'){
			a=(a<<1)+(a<<3)+(c^48);
			c=gc();
		}
	}
	#undef gc
}
using IO::read;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
const int Maxn=4000000;
const int Mod=1000000007;
int n;
int a[Maxn+5];
int C[Maxn+5][9];
bool np[Maxn+5];
int mu[Maxn+5];
int p[Maxn+5],p_len;
void init(){
	C[0][0]=1;
	for(int i=1;i<=Maxn;i++){
		C[i][0]=1;
		if(i<=8){
			C[i][i]=1;
		}
		for(int j=1;j<std::min(9,i);j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
	np[0]=np[1]=1;
	mu[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			mu[i]=-1;
		}
		for(int j=1,x;(x=i*p[j])<=Maxn;j++){
			np[x]=1;
			if(i%p[j]==0){
				mu[x]=0;
				break;
			}
			mu[x]=-mu[i];
		}
	}
}
int v[Maxn+5];
int main(){
	init();
	read(n);
	int g=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		g=gcd(g,a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i]/g;
		v[a[i]]++;
	}
	if(g>1){
		puts("-1");
		return 0;
	}
	if(v[1]>0){
		printf("%d\n",1);
		return 0;
	}
	for(int i=1;i<=Maxn;i++){
		v[i]=(v[i]>0);
	}
	for(int i=1;i<=Maxn;i++){
		for(int j=i+i;j<=Maxn;j+=i){
			v[i]+=v[j];
		}
	}
	for(int ans=2;ans<=8;ans++){
		int sum=0;
		for(int i=1;i<=Maxn;i++){
			if(mu[i]&&v[i]>=ans){
				sum=(sum+mu[i]*C[v[i]][ans])%Mod;
			}
		}
		if(sum!=0){
			printf("%d\n",ans);
			break;
		}
	}
	return 0;
}