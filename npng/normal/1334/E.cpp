#include <cstdio>
#include <iostream>
using namespace std;
template<typename Elem>
Elem gcd(Elem a,Elem b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
template<typename Elem>
Elem lcm(Elem a,Elem b){
	return a/gcd(a,b)*b;
}
template<typename Elem_1,typename Elem_2>
Elem_1 quick_power(Elem_1 a,Elem_2 b,Elem_1 Mod){
	Elem_1 ans=1;
	while(b){
		if(b&1){
			ans=ans*a%Mod;
		}
		b>>=1;
		a=a*a%Mod;
	}
	return ans;
}
typedef long long ll;
const int Maxn=100;
const ll Mod=998244353;
ll D;
ll u,v;
ll p[Maxn+5],p_len;
void init_div(ll n){
	p_len=0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			p[++p_len]=i;
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		p[++p_len]=n;
	}
}
ll frac[Maxn+5],inv_f[Maxn+5];
void init_frac(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2,Mod);
	for(int i=Maxn-1;i>0;i--){
		inv_f[i]=inv_f[i+1]*(i+1)%Mod;
	}
	inv_f[0]=1;
}
int num[Maxn+5];
ll count_num(ll n){
	ll ans=1;
	for(int i=1;i<=p_len;i++){
		num[i]=0;
		while(n%p[i]==0){
			n/=p[i];
			num[i]++;
		}
		ans*=(num[i]+1);
	}
	return ans;
}
ll calc(ll n){
	count_num(n);
	ll sum=0,ans=1;
	for(int i=1;i<=p_len;i++){
		sum+=num[i];
	}
	ans=frac[sum];
	for(int i=1;i<=p_len;i++){
		ans=ans*inv_f[num[i]]%Mod;
	}
	return ans;
}
int main(){
	scanf("%lld",&D);
	init_div(D);
	init_frac();
	int q;
	scanf("%d",&q);
	bool flag;
	ll ans;
	ll sum_1,sum_2;
	while(q--){
		scanf("%lld%lld",&u,&v);
		if(u==v){
			puts("1");
			continue;
		}
		ll g=gcd(u,v),l;
		flag=1;
		ll now_ans=0,now=u/g,tmp=v;
		while(tmp){
			if(tmp&1){
				ans=ans+now;
				if(ans>D){
					flag=0;
					break;
				}
			}
			tmp>>=1;
			now=now+now;
			if(now>D){
				flag=0;
				break;
			}
		}
		if(flag){
			l=u/g*v;
			if(D%l!=0){
				flag=0;
			}
		}
		if(g==u||g==v){
			flag=0;
		}
		sum_1=count_num(u)+count_num(v)-count_num(g)*2;
		ans=calc(u/g)*calc(v/g)%Mod;
		if(flag){
			sum_2=count_num(l)*2-count_num(u)-count_num(v);
			if(sum_1==sum_2){
				ans=(ans+calc(l/u)*calc(l/v)%Mod)%Mod;
			}
			else if(sum_1>sum_2){
				ans=calc(l/u)*calc(l/v)%Mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}