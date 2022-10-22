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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int pri[15]={2,3,5,7,11,13,17,19,23,29,31,37,41};
V<int> fac;
int mul(int x,int y,int mod){
	RE (__int128)(x)*y%mod;
//	int re=0;
//	while(y){
//		if(y&1){
//			re=(re+x)%mod;
//		}
//		y/=2;
//		x=(x+x)%mod;
//	}
//	RE re;
}
int POW(int x,int y,int mod){
    if(!y)RE 1;
    int t=POW(x,y/2,mod);
    t=mul(t,t,mod);
    if(y&1){
        RE mul(x,t,mod);
    }else RE t;
}
mt19937_64 rnd(time(0));
int find(int x){
	int s=0,t=0;
	int c=rnd()%(x-1)+1;
	for(int step=1;;step*=2){
		s=t;
		int now=1;
		for(int i=1;i<=step;i++){
			t=(mul(t,t,x)+c)%x;
			now=mul(now,abs(t-s),x);
			if(i%127==0||i==step){
				int d=__gcd(now,x);
				if(d>1)RE d;
			}
		}
	}
}
int ss(int x){
    if(x<2)RE 0;
    FOR(i,0,12)if(x==pri[i])RE 1;
    int cnt=0,now=x-1;
    while(!(now&1)){
        now=now/2;
        cnt++;
    }
    FOR(i,0,12){
        int t=POW(pri[i],now,x);
        int lst=1;
        FOR(j,1,cnt){
            t=mul(t,t,x);
            if(t==1&&lst!=1&&lst!=x-1)RE 0;
            lst=t;
        }
        if(t!=1)RE 0;
    }
    RE 1;
}
void findfac(int x){
    if(x==1)RE;
    if(ss(x)){
        fac.PB(x);
        RE;
    }
    int t=find(x);
    while(t==x)t=find(x);
    findfac(t);findfac(x/t);
} 
int n,X,Y; 
int cnt[1<<15],cnt2[1<<15];
signed main(){
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	cin>>n>>X>>Y;
  	int t=Y/X;
  	findfac(t);
  	sort(ALL(fac));
  	fac.erase(unique(ALL(fac)),fac.end());
    if(Y%X!=0){
    	cout<<0;RE 0;
	}
	int m=fac.size();
	FOR(i,1,n){
		int x;
		cin>>x;
		if(x%X==0){
			int t=x/X,mask=0;
			rep(j,0,m){
				if(t%fac[j]==0)mask|=1<<j;
			}
			cnt[mask]++;
//			cout<<mask<<' ';
		}
		if(Y%x==0){
			int t=Y/x,mask=0;
			rep(j,0,m){
				if(t%fac[j]==0)mask|=1<<j;
			}
			cnt2[mask]++;
//			cout<<mask<<' ';
		}
//		cout<<'\n';
	}
	rep(i,0,m){
		rep(j,0,1<<m)if(j&(1<<i)){
			cnt[j]+=cnt[j^(1<<i)];
		}
	}
	int ans=0;
	rep(i,0,1<<m)ans+=cnt2[i]*cnt[((1<<m)-1)^i];
	cout<<ans;
    RE 0;
}