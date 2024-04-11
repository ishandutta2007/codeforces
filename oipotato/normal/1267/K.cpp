#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
ll n,C[61][61];int T;
int cnt[61];
int main()
{
	C[0][0]=1;
	rep(i,60){
		C[i][0]=1;
		rep(j,i)C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	for(scanf("%d",&T);T--;){
		scanf("%lld",&n);
		memset(cnt,0,sizeof cnt);
		int siz=0;
		for(int i=2;n;++i)
			++cnt[n%i],n/=i,++siz;
		ll ans1=1;
		int inn=0;
		for(int i=siz;~i;--i){
			ans1*=C[siz-max(1,i)+1-inn][cnt[i]];
			inn+=cnt[i];
		}
		//printf("%lld\n",ans1);
		ll ans2;
		if(cnt[0]==0)ans2=0;else{
			ans2=1;--cnt[0];--siz;
			inn=0;
			for(int i=siz+1;~i;--i){
				if(siz-max(1,i)+1-inn<0){ans2=0;break;}
				ans2*=C[siz-max(1,i)+1-inn][cnt[i]];
				inn+=cnt[i];
			}
		}
		//printf("%lld\n",ans2);
		ll ans=ans1-ans2-1;
		printf("%lld\n",ans);
	}
	return 0;
}