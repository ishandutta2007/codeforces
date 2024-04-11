#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
ll f[30010][210][4],A[30010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi();
	for(int i=1;i<=n;++i)A[i]=gi();
	memset(f,-63,sizeof f);
	for(int i=0;i<4;++i)f[1][i<=1][i]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i&&j<=k;++j)
			for(int o=0;o<4;++o)
				if(f[i][j][o]>-1e17){
					//printf("%d %d %d %lld\n",i,j,o,f[i][j][o]);
					std::vector<int>v;int d=0;
					if(o==0)v={0,1,2},d=2*A[i];
					else if(o==1)v={0,1,3},d=-2*A[i];
					else if(o==2)v={2,1};
					else v={3,0};
					if(j==1||j==k)d/=2;
					for(int s:v){
						cxk(f[i+1][j+(s<=1&&s!=o)][s],f[i][j][o]+d);
						if(j>=1&&j+1<k&&s>1)cxk(f[i+1][j+1][s],f[i][j][o]+d);
					}
				}
	printf("%lld\n",std::max(f[n+1][k][2],f[n+1][k][3]));
	return 0;
}