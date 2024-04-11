///kk
#include<cstdio>
#include<cstring>
#define lg(x) (31-__builtin_clz(x))
#define llg(x) (63-__builtin_clzll(x))
const int N=5050,MOD=998244353;
int n,cnt[N],f[N][N],fac[10086],ifac[10086];
int Abs(int x){return x<0?-x:x;}
int lowbit(int x){return x&(-x);}
int Max(int a,int b){return a>b?a:b;}
int Min(int a,int b){return a<b?a:b;}
int Swap(int &a,int &b){a^=b^=a^=b;return true;}
int Add(int &a,int b){return(a+=b)>=MOD?a-=MOD:a;}
int vAdd(int a,int b){return(a+=b)>=MOD?a-=MOD:a;}
int Sub(int &a,int b){return(a-=b)<0?a+=MOD:a;}
int vSub(int a,int b){return(a-=b)<0?a+=MOD:a;}
int Mul(int a,int b){return 1ll*a*b%MOD;}
int qpow(int a,int b){
	int ret=1;
	while(b){if(b&1)ret=Mul(ret,a);a=Mul(a,a);b>>=1;}
	return ret;
}
int C(int n,int m){if(n<0||m<0||n<m)return 0;return Mul(fac[n],Mul(ifac[m],ifac[n-m]));}
int read(){
	char ch=getchar();int nn=0,ssss=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ssss*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){nn=nn*10+(ch-'0');ch=getchar();}
	return nn*ssss;
}
bool solve(){
	n=read();std::memset(cnt,0,sizeof(int)*(n+10));
	for(int i=0;i<=n;i++)std::memset(f[i],0,sizeof(int)*(n+10));
	for(int i=1;i<=n;i++)cnt[read()]++;
	int pos=0;while(!cnt[pos])pos++;
	f[pos][cnt[pos]]=1;int lst=pos,tot=cnt[pos];
	for(int i=pos+1;i<=n;i++){
		if(!cnt[i])continue;
		for(int j=0;j<=tot;j++){
			if(j>0){
				if(cnt[i]==1)Add(f[i][j-1],f[lst][j]);
				if(cnt[i]>1&&j>1)Add(f[i][j-2+cnt[i]],Mul(f[lst][j],C(cnt[i]-3+j,j-2)));
				Add(f[i][j+cnt[i]],Mul(f[lst][j],C(cnt[i]+j-1+(j==tot),j-1+(j==tot))));
			}
		}
		lst=i;tot+=cnt[i];
//		for(int j=0;j<=tot;j++)printf("f[%d][%d]=%d\n",i,j,f[i][j]);
	}
	printf("%d\n",f[lst][0]);return true;
}
int main(){
//	freopen("F.in","r",stdin);
	fac[0]=ifac[0]=1;for(int i=1;i<=10000;i++)fac[i]=Mul(fac[i-1],i);
	ifac[10000]=qpow(fac[10000],MOD-2);
	for(int i=9999;i;i--)ifac[i]=Mul(ifac[i+1],i+1);
	int T=read();
	while(T--)solve();
}