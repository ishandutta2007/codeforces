#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=1e6+1;
int pri[N],a[N],cnt;
ll tot,p[20],ans=1e18;
void pre(){
	rep(i,2,N){
		if(!pri[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<N;++j){
			pri[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int main(){
	pre();
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&a[i]),tot+=a[i];
	if(tot<=1){
		cout<<"-1";
		return 0;
	}
	for(int i=1;i<=pri[0];++i){
		if(1ll*pri[i]*pri[i]>tot)break;
		if(tot%pri[i]==0){
			p[cnt++]=pri[i];
			while(tot%pri[i]==0)tot/=pri[i];
		}
	}
	if(tot>1)p[cnt++]=tot;
	rep(i,0,cnt){
		ll d=p[i];
		ll sum=0,k=d/2,ans2=0;
		if(d&1)++k;
		rep(j,0,n){
			ll last=a[j]%d;
			if(sum>=k){
				if(last+sum>=d){
					ans2+=(d-sum)*j;
					sum=last+sum-d;
					if(sum>=k){
						ans2-=k*j;
						ans2+=k*j-(d-k)*j;
						ans2+=(sum-k)*j;
					} 
					else{
						ans2-=sum*j;
					}
				}
				else{
					ans2+=last*j;
					sum+=last;
				}
			}
			else{
				if(last+sum>=k){
					ans2+=k*j-(d-k)*j;
					ans2-=(k-sum)*j;
					if(last+sum>=d){
						ans2+=(d-k)*j;
						sum=last+sum-d;
						ans2-=sum*j;
					}
					else{
						sum=last+sum;
						ans2+=(sum-k)*j;
					}
				}
				else{
					ans2-=last*j;
					sum+=last;
				}
			}
		}
		//cout<<d<<' '<<sum<<"check\n";
		ans=min(ans,ans2);
	}
	printf("%lld",ans);
}