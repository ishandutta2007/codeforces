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
int a[200005];
int B=300;
int solve1[2005],solve2[2005];
int sum1[300005],maxai=3e5;
int get(int x){
	if(x<=0)RE 0;
	int re=0;
	while(x){
		re+=sum1[x];
		x-=x&-x;
	}
	RE re;
}
void update(int x){
	if(!x)x++;
	while(x<=maxai){
		sum1[x]++;
		x+=x&-x;
	}
}
int get(int x,int y){
	RE get(y)-get(x-1);
}
int sum2[300005];
int get2(int x){
	if(x<=0)RE 0;
	int re=0;
	while(x){
		re+=sum2[x];
		x-=x&-x;
	}
	RE re;
}
void update2(int x,int y){
	if(!x)x++;
	while(x<=maxai){
		sum2[x]+=y;
		x+=x&-x;
	}
}
int cnt[2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int ans=0,sum=0,num=0;
	FOR(i,1,n){
		cin>>a[i];
		if(a[i]<B){
			ans+=solve1[a[i]];ans+=num*a[i];ans+=solve2[a[i]];
			FOR(j,1,B-1)solve2[j]+=j%a[i];
			cnt[a[i]]++;
		}else{
			//i%j 
			ans=ans+num*a[i]-get2(a[i]);
			rep(j,2,B)ans=ans+cnt[j]*(a[i]%j);
			//j%i
			ans+=sum;
			int lst=0,now;
			for(int j=0;j<=maxai;j+=a[i]){
				now=get(min(maxai,a[i]+j-1));
				ans=ans-(now-lst)*j;lst=now;
				if(j+a[i]<=maxai)update2(j+a[i],a[i]);
			} 
			num++;
		}
		sum+=a[i];
		FOR(j,1,B-1){
			solve1[j]+=a[i]%j;
		}
		update(a[i]);
		cout<<ans<<' ';
	}
	RE 0;
}