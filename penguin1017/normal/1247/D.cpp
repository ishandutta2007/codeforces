#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
using namespace std;
const int N=(int)1e5+9;
int a[N],tot[N],pos[N];
int main(){
	ll ans=0;
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n)scanf("%d",&a[i]);
	rep(i,0,n){
		ll mod=1,last=1;
		//int Sqr=sqrt(a[i]);
		for(int j=2;j<=a[i]/j;j++){
			if(a[i]%j==0){
				int cnt=0;
				while(a[i]%j==0){
					a[i]/=j;
					cnt++;
				}
				cnt%=k;
				rep(mask,0,cnt)mod*=j;
				if(last)rep(mask,0,(k-cnt)%k){
					last*=j;
					if(last>100000){
						last=0;
						break;
					}
				}
			}
		}
		if(a[i]>1){
			mod*=a[i];
			if(last)rep(mask,0,k-1){
				last*=a[i];
				if(last>100000){
					last=0;
					break;
				}
			} 
		}
		pos[i]=last;
		tot[mod]++;
	//	cout<<last<<' '<<mod<<"mod\n";
		if(last==mod)ans--;
	}
//	cout<<ans<<"ans\n";
	rep(i,0,n)ans+=tot[pos[i]];
	printf("%lld",ans/2);
}