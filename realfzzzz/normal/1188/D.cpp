#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n;
ll a[maxn];
const int inf=2e9;
inline void cmin(int& x,int y){
	x=min(x,y);
}
int f[2][maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) f[1][i]=inf;
	for(int i=0;i<=60;i++){
		bool d=i%2;
		for(int j=0;j<=n;j++) f[d][j]=inf;
		sort(a+1,a+n+1,[i](ll x,ll y){
			return (x&((1ll<<i)-1))>(y&((1ll<<i)-1));
		});
		int cnt1[2],cnt2[2];
		cnt1[0]=cnt1[1]=cnt2[0]=cnt2[1]=0;
		for(int j=1;j<=n;j++)
			if(a[j]>>i&1){
				cnt1[0]++;
				cnt2[0]++;
			}
			else cnt2[1]++;
		for(int j=0;j<=n;j++){
			if(j){
				if(a[j]>>i&1){
					cnt1[1]++;
					cnt2[0]--;
					cnt2[1]++;
				}
				else{
					cnt1[0]++;
					cnt2[0]++;
					cnt2[1]--;
				}
			}
			int res=f[!d][j];
			if(res<inf){
				cmin(f[d][cnt1[0]],res+cnt2[0]);
				cmin(f[d][cnt1[1]],res+cnt2[1]);
			}
		}
	}
	printf("%d\n",f[0][0]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}