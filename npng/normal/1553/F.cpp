#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=300000;
const int Maxb=540;
const int Maxv=(Maxn-1)/Maxb+1;
int find_belong(int x){
	return (x-1)/Maxb+1;
}
int find_bel_l(int x){
	return (x-1)*Maxb+1;
}
int find_bel_r(int x){
	return std::min(x*Maxb,Maxn);
}
int all_bel;
namespace Block_1{
	ll s_f[Maxn+5],s_b[Maxv+5];
	void add(int x,int a){
		int bel_x=find_belong(x);
		for(int i=bel_x;i<=all_bel;i++){
			s_b[i]+=a;
		}
		int r_bel=find_bel_r(bel_x);
		for(int i=x;i<=r_bel;i++){
			s_f[i]+=a;
		}
	}
	ll query(int x){
		if(x==0){
			return 0;
		}
		int bel_x=find_belong(x);
		return s_b[bel_x-1]+s_f[x];
	}
	ll query(int l,int r){
		return query(r)-query(l-1);
	}
}
namespace Block_2{
	ll s_f[Maxn+5],s_b[Maxv+5];
	void add(int x,int a){
		if(x>Maxn){
			return;
		}
		int bel_x=find_belong(x);
		s_f[x]+=a,s_b[bel_x]+=a;
	}
	void add(int l,int r,int a){
		add(l,a),add(r+1,-a);
	}
	ll query(int x){
		int bel_x=find_belong(x);
		ll ans=0;
		for(int i=1;i<bel_x;i++){
			ans+=s_b[i];
		}
		int l_bel=find_bel_l(bel_x);
		for(int i=l_bel;i<=x;i++){
			ans+=s_f[i];
		}
		return ans;
	}
}
int n;
int a[Maxn+5];
int main(){
	all_bel=find_belong(Maxn);
	scanf("%d",&n);
	ll sum=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		Block_1::add(a[i],a[i]);
		ans+=a[i]*Block_2::query(a[i]);
		for(int j=1,k;j<=a[i];j=k+1){
			k=a[i]/(a[i]/j);
			ans+=(a[i]/j)*Block_1::query(j,k);
			Block_2::add(j,k,a[i]/j);
		}
		printf("%lld ",sum*i-ans);
	}
	puts("");
	return 0;
}