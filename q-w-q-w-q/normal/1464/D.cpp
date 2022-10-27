#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
int t,n,p[1000001],cnt;
int a[1000001],b[1000001];
bool v[1000001];
inline int power(int a,int n){
	int tp=1;
	while(n){
		if(n&1) tp=1ll*tp*a%mod;
		a=1ll*a*a%mod,n>>=1;
	}
	return tp;
}
inline int solve0(int n){
	int ans=0,x=0,y=0;
	for(int i=1;i<=n;i++){
		ans+=(a[i]-1)/3,a[i]%=3;
		if(a[i]==1) x++;
		if(a[i]==2) y++;
	}
	int tp=min(x,y);
	ans+=tp,x-=tp,y-=tp;
	if(x) return ans+x/3*2;
	return ans+y;
}
inline int solve1_0(int n){
	for(int i=1;i<=n;i++) b[i]=a[i];
	int ans=0,x=0,y=0;
	for(int i=1;i<=n;i++)
		if(a[i]%3==2) x++;
	if(x>=2){
		x=2;
		for(int i=1;i<=n&&x;i++)
			if(a[i]%3==2) ans+=(a[i]>2),a[i]-=2,x--;
		for(int i=1;i<=n;i++){
			ans+=(a[i]-1)/3,a[i]%=3;
			if(a[i]==1) x++;
			if(a[i]==2) y++;
		}
		int tp=min(x,y);
		ans+=tp,x-=tp,y-=tp;
		for(int i=1;i<=n;i++) a[i]=b[i];
		if(x) return ans+x/3*2;
		return ans+y;
	}
	return 1<<30;
}
inline int solve1_1(int n){
	for(int i=1;i<=n;i++) b[i]=a[i];
	int ans=0,x=0,y=0;
	for(int i=1;i<=n;i++)
		if(a[i]%3==2) x++;
		else if(a[i]%3==1) y++;
	if(x>=1&&y>=2){
		x=1;
		for(int i=1;i<=n&&x;i++)
			if(a[i]%3==2) ans+=(a[i]>2),a[i]-=2,x--;
		y=2;
		for(int i=1;i<=n&&y;i++)
			if(a[i]%3==1) a[i]+=(a[i]>1),a[i]--,y--;
		ans++;
		for(int i=1;i<=n;i++){
			ans+=(a[i]-1)/3,a[i]%=3;
			if(a[i]==1) x++;
			if(a[i]==2) y++;
		}
		int tp=min(x,y);
		ans+=tp,x-=tp,y-=tp;
		for(int i=1;i<=n;i++) a[i]=b[i];
		if(x) return ans+x/3*2;
		return ans+y;
	}
	return 1<<30;
}
inline int solve1_2(int n){
	for(int i=1;i<=n;i++) b[i]=a[i];
	int ans=0,x=0,y=0;
	bool ok=0;
	for(int i=1;i<=n;i++)
		if(a[i]>=4&&a[i]%3==1){
			ans+=(a[i]>4),a[i]-=4,ok=1;
			break;
		}
	if(ok){
		for(int i=1;i<=n;i++){
			ans+=(a[i]-1)/3,a[i]%=3;
			if(a[i]==1) x++;
			if(a[i]==2) y++;
		}
		int tp=min(x,y);
		ans+=tp,x-=tp,y-=tp;
		for(int i=1;i<=n;i++) a[i]=b[i];
		if(x) return ans+x/3*2;
		return ans+y;
	}
	return 1<<30;
}
inline int solve1(int n){
	int ans=0,x=0,y=0,g=0;
	bool ok=0;
	ans=min(solve1_0(n),min(solve1_1(n),solve1_2(n)));
	if(ans!=(1<<30)) return ans;
	ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1) x++;
	if(x>1){
		ans+=2,x=4;
		for(int i=1;i<=n&&x;i++)
			if(a[i]==1) a[i]--,x--;
		for(int i=1;i<=n;i++){
			if(a[i]==1) x++;
			else if(a[i]) ans+=a[i]/3-1;
		}
		return ans+x/3*2;
	}
	ans++;
	for(int i=1;i<=n;i++)
		if(a[i]==1){
			a[i]=0;
			break;
		}
	for(int i=1;i<=n;i++)
		if(a[i]>=3){
			ans+=(a[i]>3),a[i]-=3;
			break;
		}
	for(int i=1;i<=n;i++) if(a[i]) ans+=a[i]/3-1;
	return ans;
}
inline int solve2(int n){
	int ans=0,x=0,y=0;
	for(int i=1;i<=n;i++){
		ans+=(a[i]-1)/3,a[i]%=3;
		if(a[i]==1) x++;
		if(a[i]==2) y++;
	}
	if(y) y--;
	else x-=2,ans++;
	int tp=min(x,y);
	ans+=tp,x-=tp,y-=tp;
	if(x) return ans+x/3*2;
	return ans+y;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",p+i);
		cnt=0;
		for(int i=1;i<=n;i++){
			if(v[i]) continue;
			a[++cnt]=v[i]=1;
			for(int x=p[i];x!=i;x=p[x]) a[cnt]++,v[x]=1;
		}
		for(int i=1;i<=n;i++) v[i]=0;
		if(n%3==0) cout<<power(3,n/3)<<' '<<solve0(cnt)<<endl;
		if(n%3==1) cout<<4ll*power(3,(n-4)/3)%mod<<' '<<solve1(cnt)<<endl;
		if(n%3==2) cout<<2ll*power(3,(n-2)/3)%mod<<' '<<solve2(cnt)<<endl;
	}
}