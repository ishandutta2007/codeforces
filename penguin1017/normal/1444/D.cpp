#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(),x.end()
#define lb(x) ((x)&(-x))
#define ll long long
#define vi vector<int>
using namespace std;
const int N=1e6+1;
bitset<1000001> dp[1001];
int x[1001],y[1001],a[1001];
bool vis[1001];
int main(){
	int T;
	scanf("%d",&T);
	dp[0][0]=1;
	while(T--){
		int h;
		scanf("%d",&h);
		int sum=0,ok=0,cnt=0,cnt2=0;
		rep(i,1,h+1)scanf("%d",&a[i]),sum+=a[i],vis[i]=0;
		sort(a+1,a+1+h,[](int x,int y){return x>y;});
		if(sum&1)ok=1;
		if(!ok){
			rep(i,1,h+1)dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
			//cout<<ok<<"check\n";
			if(!dp[h][sum>>1])ok=1;
			else{
				int pos=sum>>1;
				per(i,1,h+1){
					if(!dp[i-1][pos]){
						vis[i]=1;
						pos-=a[i];
					}
				}
				rep(i,1,h+1){
					if(vis[i])x[++cnt]=a[i];
				}
					rep(i,1,h+1)if(!vis[i])x[++cnt]=-a[i];
			}
		}
		scanf("%d",&h);
		sum=0;
		rep(i,1,h+1)scanf("%d",&a[i]),sum+=a[i],vis[i]=0;
		sort(a+1,a+1+h);
		if(sum&1)ok=1;
		if(!ok){
			rep(i,1,h+1)dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
			if(!dp[h][sum>>1])ok=1;
			else{
				int pos=sum>>1;
				per(i,1,h+1){
					if(!dp[i-1][pos]){
						vis[i]=1;
						pos-=a[i];
					}
				}
				rep(i,1,h+1){
					if(vis[i])y[++cnt2]=a[i];
				}
					rep(i,1,h+1)if(!vis[i])y[++cnt2]=-a[i];
			}
		}
		dp[0].reset();
		dp[0][0]=1;
	//	cout<<y[1]<<' '<<y[2]<<"check\n";
		if(ok||cnt!=cnt2){
			puts("No");
		}
		else {
			puts("Yes");
			int px=0,py=0,id=1,id2=1;
			rep(t,0,cnt+cnt2){
				printf("%d %d\n",px,py);
				if(~t&1)px+=x[id++];
				else py+=y[id2++];
			}
		}
	}
	
}