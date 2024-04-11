#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
int a[N],b[N],f[N],cnt,num[N],p,n;
ll D,sum,sum2;
pii d[N];
bool find(int x){
	int l=0,r=cnt;
	while(l<r){
		int mid=l+r>>1;
		if(d[mid].fi<x)l=mid+1;
		else r=mid;
	}
	D=d[l].se;
	return x==d[l].fi;
}
ll get(ll fir){
	ll res=0;
	res=fir*fir%p*n%p+1ll*(n-1)*n*(2*n-1)/6%p*D%p*D%p+1ll*(n-1)*n%p*D%p*fir%p;
	return res%p;
}
int main(){
	scanf("%d%d",&p,&n);
	rep(i,0,n)scanf("%d",&a[i]),sum+=a[i],sum2+=1ll*a[i]*a[i]%p;
	sort(a,a+n);sum%=p;sum2%=p;
	ll m=1ll*n*(n-1)/2%p;
	num[0]=1;
	rep(i,1,n){
		if(a[i]!=a[i-1])d[cnt++]={(sum-(a[i]-a[0])*m%p+p)%p,a[i]-a[0]},num[cnt]++;
		else num[cnt]++;
	}
	sort(num,num+cnt+1);
	sort(d,d+cnt);
//	rep(i,0,cnt)cout<<d[i].fi<<" ";
//	cout<<"D\n";
	if(cnt==0){
		printf("%d %d",a[0],0);
		return 0;
	}
	if(n<=p){
		if(num[cnt]>=2){
			printf("-1");
			return 0;
		}
	}
	else{
		if(num[cnt]-num[0]>1){
			printf("-1");
			return 0;
		}
	}
	if(n%p==0){
	//	cout<<num[cnt]<<' '<<num[0]<<"cnt\n";
		if(num[cnt]!=num[0]||cnt!=p-1){
			printf("-1");
		}
		else printf("%d %d",a[0],1);
		return 0;
	}
	int cnt2=0;
	per(i,0,n){
		if(a[i]==a[i+1])continue;
		int born=1ll*a[i]*n%p;
		if(find(born)&&get(a[i])==sum2){
			cnt2++;
//		cout<<a[i]<<' '<<D<<"born\n";
			rep(j,0,n)b[j]=(a[i]+j*D)%p;
		//	cout<<"bbb\n";
			sort(b,b+n);
			int flag=1;
			rep(j,0,n)if(a[j]!=b[j]){
			//	cout<<a[j]<<' '<<b[j]<<"which\n";
				flag=0;
				break;
			}
			if(flag){
				printf("%d %lld",a[i],D);
				return 0;
			}
			else if(cnt2>350){
				printf("-1");
				return 0;
			}
		}
	}
	printf("-1");
}