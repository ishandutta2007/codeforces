#include<bits\stdc++.h>
using namespace std;
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
const int Maxn=1000005;
int d[1000005];
bool isp[1000005];
bool ff[1000005];
vector<int> fa[1000005];
int mu[1000005]; 
void _init(){
	LL cur=0;
	memset(isp,true,sizeof(isp));
	memset(ff,true,sizeof(ff));
	for (int i=1;i<=1000000;i++) d[i]=i,mu[i]=1;
	for (int i=2;i<=1000000;i++){
		if (isp[i]){
			d[i]=i-1;
			mu[i]=-1;
			for (int j=i+i;j<=1000000;j+=i){
				d[j]/=i;
				d[j]*=(i-1);
				if ((j/i)%i==0) mu[j]=0;
				mu[j]*=-1;
				isp[j]=false;
			}
		}
	}
	for (int i=2;i<=1000000;i++){
		for (int j=1;j*j<=i;j++){
			if (i%j==0){
				fa[i].pb(j);
				if (j*j!=i) fa[i].pb(i/j);
			}
		}
	}
}
int Get(int kk,int xx){
	int ans=0;
	for (int i=0;i<fa[xx].size();i++){
		ans+=mu[fa[xx][i]]*(kk/fa[xx][i]+1);
	//	if (kk==7) cout<<mu[fa[xx][i]]*(kk/fa[xx][i]+1)<<endl;
	}
	return ans;
}
void solve(){
	int x,p,k;
	scanf("%d %d %d",&x,&p,&k);
//	cout<<d[x]<<endl;
	if (p==1){
		printf("%d\n",x+k);
		return;
	}
	int ans=0;
	int lo,hi;
	int pre=Get(x,p);
	lo=0,hi=1e7;
	while (hi-lo>1){
		int mid=lo+hi>>1;
		//cout<<lo<<hi<<endl;
		if (Get(mid,p)-pre>=k){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	//2333
	if (Get(lo,p)-pre>=k){
		ans=lo;
	}
	else{
		ans=hi;
	}
	if (ans==1e7){
		throw p;
	}
	printf("%d\n",ans);
}
int main(){
	_init();
//	cerr<<"ok"<<endl;
//	cerr<<Get(8,9)<<endl;
	int t;
	scanf("%d",&t);
	while (t--){
		solve();
	}
	return 0;
}