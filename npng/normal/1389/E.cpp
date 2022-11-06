#include <cstdio>
typedef long long ll;
const int Maxb=50000;
int min(int a,int b){
	return a<b?a:b;
}
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m,d,w;
		scanf("%d%d%d",&m,&d,&w);
		m=min(m,d);
		d--;
		if(d==0){
			puts("0");
			continue;
		}
		int g=gcd(d,w);
		w/=g;
		d/=g;
		ll ans=0;
		if(w<=Maxb){
			for(int i=1;i<=w;i++){
				int num=(m-i)/w+1;
				ans+=1ll*num*(num-1)/2;
			}
		}
		else{
			for(int i=1;i*w<=m;i++){
				ans+=(m-i*w);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}