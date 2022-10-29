#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int op[30],last[30];
const int n=1e9+1;
ll dp[35];
ll dfs(int l,int lim1,int r,int lim2,int pos){
	if(pos==0)return 1;
	if(!lim1&&!lim2&&dp[pos])return dp[pos];
	//if(pos==2)cout<<lim1<<' '<<lim2<<' '<<dp[pos]<<"ok\n";
	ll ans=0;
	pos--;
	if(lim1){
		if(l&op[pos]){
			if(lim2){
				if(r&op[pos]){
					ans+=dfs(last[pos]^op[pos],0,r^op[pos],1,pos);
				//	cout<<ans<<"ans1\n";
					ans+=dfs(l^op[pos],1,last[pos]^op[pos],0,pos);
				//	cout<<ans<<"ans2\n";
					ans+=dfs(last[pos]^op[pos],0,last[pos]^op[pos],0,pos);
				//	cout<<pos<<' '<<ans<<"comein\n";
				}
				else{
					ans+=dfs(l^op[pos],1,r,1,pos);
				//	if(pos==0)cout<<ans<<"ans1\n";
					ans+=dfs(last[pos]^op[pos],0,r,1,pos); 
				//	if(pos==0)cout<<ans<<"ans2\n";
				}
			}
			else{
					ans+=dfs(l^op[pos],1,last[pos]^op[pos],0,pos);
					ans+=2*dfs(last[pos]^op[pos],0,last[pos]^op[pos],0,pos);
			}
		}
		else{
			if(lim2){
				if(r&op[pos]){
					ans+=dfs(l,1,last[pos]^op[pos],0,pos);
					ans+=dfs(l,1,r^op[pos],1,pos);
				}
				else{
					ans+=dfs(l,1,r,1,pos);
				} 
			}
			else{
				ans+=2*dfs(l,1,last[pos]^op[pos],0,pos);
			}
		}
	}
	else{
		if(lim2){
			if(r&op[pos]){
				ans+=dfs(last[pos]^op[pos],0,r^op[pos],1,pos);
				ans+=2*dfs(last[pos]^op[pos],0,last[pos]^op[pos],0,pos);
			}
			else{
				ans+=2*dfs(last[pos]^op[pos],0,r,1,pos);
			}
		}
		else{
			ans+=3*dfs(last[pos]^op[pos],0,last[pos]^op[pos],0,pos);
		}
	}
	if(!lim1&&!lim2)dp[pos+1]=ans;
//	if(pos==1)cout<<lim1<<' '<<lim2<<' '<<ans<<"ans\n"; 
	return ans;
}
int main()
{
	rep(i,0,30)op[i]=1<<i,last[i]=(1<<(i+1))-1;
	int t;
	scanf("%d",&t);
	while(t--){
		int l,r;
		scanf("%d%d",&l,&r); 
		if(!l){
			printf("%lld\n",dfs(r,1,r,1,30));
			continue;
		}
		//ll ans;
	//	cout<<dfs(r,1,r,1,30)<<"check\n";
	//	cout<<dfs(1,0,0,1,1)<<"check2\n";
		ll ans=dfs(l-1,1,l-1,1,30)-2*dfs(l-1,1,r,1,30)+dfs(r,1,r,1,30);
		printf("%lld\n",ans); 
	}
}
/*
3
1 4
323 323
1 1000000

1
1 4
*/