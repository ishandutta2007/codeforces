#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=100000;
char s[Maxn+5];
int n,x,y;
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	scanf("%d%d",&x,&y);
	int sum_0=0,sum_1=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			ans+=1ll*sum_0*x;
			sum_1++;
		}
		else{
			ans+=1ll*sum_1*y;
			sum_0++;
		}
	}
	int b_0=sum_0,b_1=sum_1;
	ll tmp=ans;
	sum_0=0,sum_1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			sum_0++;
			b_0--;
		}
		else if(s[i]=='1'){
			sum_1++;
			b_1--;
		}
		else{
			b_0--;
			tmp-=1ll*sum_1*y;
			tmp-=1ll*b_1*x;
			tmp+=1ll*sum_0*x;
			tmp+=1ll*b_0*y;
			sum_1++;
			ans=min(ans,tmp);
		}
	}
	sum_0=sum_1=0;
	tmp=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			tmp+=1ll*sum_1*y;
			sum_0++;
		}
		else{
			tmp+=1ll*sum_0*x;
			sum_1++;
		}
	}
	ans=min(ans,tmp);
	b_0=sum_0,b_1=sum_1;
	sum_0=0,sum_1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			sum_0++;
			b_0--;
		}
		else if(s[i]=='1'){
			sum_1++;
			b_1--;
		}
		else{
			b_1--;
			tmp-=1ll*sum_0*x;
			tmp-=1ll*b_0*y;
			tmp+=1ll*sum_1*y;
			tmp+=1ll*b_1*x;
			sum_0++;
			ans=min(ans,tmp);
		}
	}
	printf("%lld\n",ans);
	return 0;
}