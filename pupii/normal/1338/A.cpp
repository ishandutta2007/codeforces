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
long long a[100010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int qwq=gi();
	while(qwq--){
		int n=gi(),m=0;
		for(int i=1;i<=n;++i)a[i]=gi();
		int l=0,r=32,mid;
		while(l<r){
			mid=l+r>>1;
			ll X=(1<<mid)-1,f=1;
			ll lst=a[1];
			for(int i=2;i<=n;++i){
				ll now=std::max(lst,a[i]);
				if(now>a[i]+X)f=0;
				lst=now;
			}
			if(f)r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}