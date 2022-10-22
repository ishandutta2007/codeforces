#include<bits/stdc++.h>
#define ll long long
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
int p[100005];
int num[100005],siz;
int n,a,b,c;
ll solve(int cnt1,int cnt0,int ts,int tp){
	siz=0;
	int cnt=0,fir=0;ll re=0;
	bool st=0;
	FOR(i,1,n){
		if(p[i]==0){
			cnt++;
		}else{
			if(!st)fir=cnt;
			if(cnt&&st)num[++siz]=cnt;
			st=1;
			cnt=0;
		}
	}
	int lst=cnt;
	int cn0=0;
	FOR(i,1,n)cn0+=p[i]==0;
	if(b>c){
		sort(num+1,num+siz+1);
		cnt1-=ts+tp;
		FOR(i,1,siz){
			if(ts>=num[i]-1){
				ts-=num[i]-1;
				cn0-=num[i];
				re+=(b-c);
				num[i]=0;
			}else {
				num[i]-=ts;
				cn0-=ts;ts=0;
				break;
			}
		}
		cn0-=ts;
		if(lst>fir)swap(lst,fir);
		num[++siz]=lst;num[++siz]=fir;
		if(ts){
			FOR(i,1,siz)if(num[i]>0){
				if(num[i]-1>=ts){
					num[i]-=ts;break;
				}else ts-=num[i]-1,num[i]=1;
			}
		}
		ll tre=re;
		FOR(i,1,siz){
			if(num[i]>1){
				cn0--;
				int t=min(cnt1,cn0);
				tre+=1ll*t*(b-c);
				tre+=a;
				cn0++;
				break;
			}
		}
		if(cnt1>0){
			int t=min(cnt1,cn0);
			re+=1ll*t*(b-c);
		}
		gmax(re,tre);
	}
	RE re;
}
void solve(){
	ll ans1=0,ans2=0,ans3=0;
	cin>>n>>a>>b>>c;
	FOR(i,1,n){
		char c;
		cin>>c;
		p[i]=c-'0';
	}
	int cnt0=0,cnt1=0;
	FOR(i,2,n){
		cnt0+=p[i]==p[i-1]&&p[i]==0;
		cnt1+=p[i]==p[i-1]&&p[i]==1;
	}
	ans1=1ll*min(cnt0,cnt1+1)*(a+b)-b;
	ans2=1ll*min(cnt0+1,cnt1)*(a+b)-a;
	ans3=1ll*min(cnt0,cnt1)*(a+b);
	ans2+=solve(cnt1,cnt0,min(cnt0+1,cnt1)-1,1);
	ans3+=solve(cnt1,cnt0,min(cnt0,cnt1),0);
	cout<<max(max(ans1,ans2),ans3)<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}