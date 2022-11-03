#include<bits/stdc++.h>
#define mod 1000000007
#define hmod 1009260817
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char A[2][2010],S[2010],rS[2010];
int n,m,N,Base[2010];
struct yybakioiqwqwqwq{
	int HS[2010];char*pp;
	void pre(char*S,int n){pp=S;for(int i=1;i<=n;++i)HS[i]=(HS[i-1]+1ll*S[i]*Base[i])%hmod;}
	int get(int l,int r){return 1ll*(HS[r]-HS[l-1]+hmod)*Base[N-r]%hmod;}
	/*std::string get(int l,int r){
		std::string ret;
		for(int i=l;i<=r;++i)ret+=pp[i];
		std::cerr<<"get "<<l<<" "<<r<<" "<<ret<<std::endl;
		return ret;
	}*/
}hA[2],hS,hrS;
int f[2010][2][2010];
void add(int&a,int b){a=a+b>=mod?a+b-mod:a+b;}
int work(){
	memset(f,0,sizeof f);
	int ret=0;
	for(int i=1;i<=n;++i){//f[i][j][K]iji+1 K
		f[i-1][0][0]=f[i-1][1][0]=1;
		for(int o=0;o<2;++o){
			for(int j=i+1;j<=n;++j)
				if(m>=2*(j-i+1)&&hA[o^1].get(i,j)==hrS.get(1,j-i+1)&&hA[o].get(i,j)==hS.get(m-2*(j-i+1)+1,m-(j-i+1)))
					add(ret,f[i-1][o][m-2*(j-i+1)]*1ll*(m==2*(j-i+1)?(mod+1>>1):1)%mod);
			for(int j=i-1;j;--j)
				if(m>=2*(i-j+1)&&hA[o^1].get(j,i)==hrS.get(m-(i-j+1)+1,m)&&hA[o].get(j,i)==hS.get(i-j+2,2*(i-j+1)))
					add(f[i][o][2*(i-j+1)],(m==2*(i-j+1)?(mod+1>>1):1));
			for(int j=0;j<i*2;++j)
				if(f[i-1][o][j]){
					if(j+1<=m&&S[j+1]==A[o][i]){
						add(f[i][o][j+1],f[i-1][o][j]);
						if(j+2<=m&&S[j+2]==A[!o][i])add(f[i][!o][j+2],f[i-1][o][j]);
					}
				}
		}
		add(ret,f[i][0][m]);
		add(ret,f[i][1][m]);
	}
	return ret;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",A[0]+1);scanf("%s",A[1]+1);
	scanf("%s",S+1);
	n=strlen(A[0]+1),m=strlen(S+1),N=std::max(n,m);
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;++i)ans+=(A[0][i]==S[1])+(A[1][i]==S[1]);
		return printf("%d\n",ans),0;
	}
	if(m==2){
		int ans=0;
		for(int o=0;o<2;++o){
			for(int i=1;i<n;++i)ans+=(A[o][i]==S[1])&&(A[o][i+1]==S[2]);
			for(int i=1;i<n;++i)ans+=(A[o][i]==S[2])&&(A[o][i+1]==S[1]);
		}
		for(int i=1;i<=n;++i)ans+=(A[0][i]==S[1])&&(A[1][i]==S[2]);
		for(int i=1;i<=n;++i)ans+=(A[1][i]==S[1])&&(A[0][i]==S[2]);
		return printf("%d\n",ans),0;
	}
	Base[0]=1;for(int i=1;i<=N;++i)Base[i]=19260817ll*Base[i-1]%hmod;
	for(int i=0;i<2;++i)hA[i].pre(A[i],n);
	for(int i=1;i<=m;++i)rS[m-i+1]=S[i];
	hS.pre(S,m),hrS.pre(rS,m);
	int ans=work();
	for(int i=1,j=m;i<j;++i,--j)std::swap(S[i],S[j]),std::swap(rS[i],rS[j]);
	hS.pre(S,m),hrS.pre(rS,m);
	ans=(ans+work())%mod;
	printf("%d\n",ans);
	return 0;
}