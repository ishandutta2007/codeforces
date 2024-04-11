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
int mod;
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
int a[2097200],ua[1048589],pos[1048589];
void Swap(int x,int y){
	std::swap(a[x],a[y]);
	std::swap(pos[a[x]],pos[a[y]]);
}
void Down(int x){
	int l=x<<1,r=x<<1|1;
	if(!a[l]&&!a[r]){a[x]=0;return;}
	if(a[l]>a[r])Swap(x,l),Down(l);
	else Swap(x,r),Down(r);
}
int ans[1048589],m;
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int qwq=gi();
	while(qwq--){
		int n=gi(),g=gi(),N=(1<<n)-1,G=(1<<g)-1;
		for(int i=1;i<=N;++i)a[i]=ua[i]=gi();
		std::sort(ua+1,ua+N+1);
		for(int i=1;i<=N;++i)a[i]=std::lower_bound(ua+1,ua+N+1,a[i])-ua;
		for(int i=1;i<=N;++i)pos[a[i]]=i;
		m=0;ll sum=0;
		for(int i=N;i;--i){
			int x=pos[i];
			while(1){
				int l=x<<1,r=x<<1|1;
				if(!a[l]&&!a[r])break;
				if(a[l]>a[r])x=l;
				else x=r;
			}
			if(x<=G){sum+=ua[i];continue;}
			Down(ans[++m]=pos[i]);
		}
		printf("%lld\n",sum);
		for(int i=1;i<=m;++i)printf("%d ",ans[i]);
		puts("");
		for(int i=1;i<=N;++i)a[i]=pos[i]=0;
	}
	return 0;
}