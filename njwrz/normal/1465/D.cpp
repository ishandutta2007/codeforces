/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
char c[100005];
int cnt[2];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	scanf("%s",c+1);
	int n=strlen(c+1);
	int cx,cy;
	cin>>cx>>cy;
	if(cx<cy){
		swap(cx,cy);
		FOR(i,1,n){
			if(c[i]=='1')c[i]='0';
			else if(c[i]=='0')c[i]='1';
		}
	}
	int tot1=0,tot0=0,ans=0;
	FOR(i,1,n){
		if(c[i]=='?'||c[i]=='0'){
			tot0++;ans+=tot1*cy;
		}else tot1++,ans+=tot0*cx;
	}
	int now=ans;
	FOR(i,1,n){
		if(c[i]=='1'){
			cnt[1]++;
		}else{
			cnt[0]++;
		}
		if(c[i]=='?'){
			now=now-(tot1-cnt[1])*cx-cnt[1]*cy;
			tot1++;cnt[1]++;
			tot0--;cnt[0]--;
			now=now+(tot0-cnt[0])*cy+cnt[0]*cx;
//			cout<<now<<'\n';
			gmin(ans,now);
		}
	}
	cout<<ans;
	RE 0;
}