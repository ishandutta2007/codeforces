#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define lb(x) ((x)&(-x))
using namespace std;
const int N=3e5+9;
const ll mod=1e9+7;
int sum[N],sum2[N];
void Set(int p,int val){
	for(int i=p;i<N;i+=lb(i))sum[i]+=val;
}
int Get(int p){
	int res=0;
	for(int i=p;i;i^=lb(i))res+=sum[i];
	return res;
}
void Set2(int p,int val){
	for(int i=p;i<N;i+=lb(i))sum2[i]+=val;
}
int Get2(int p){
	int res=0;
	for(int i=p;i;i^=lb(i))res+=sum2[i];
	return res;
}
int mini[N],maxn[N],flag[N],a[N],last[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)mini[i]=maxn[i]=i;
	rep(i,1,m+1){
		scanf("%d",&a[i]);
		if(!last[a[i]]){
			Set(a[i],1);
			Set2(i,1); 
			maxn[a[i]]=max(maxn[a[i]],a[i]+Get(n)-Get(a[i]));
	//		cout<<a[i]<<' '<<maxn[a[i]]<<"Max1\n";
		}
		else{
			Set2(i,1);
			Set2(last[a[i]],-1);
			maxn[a[i]]=max(maxn[a[i]],Get2(i)-Get2(last[a[i]]));
		//cout<<a[i]<<' '<<maxn[a[i]]<<i<<' '<<last[a[i]]<<"Max2\n";
		}
		last[a[i]]=i;
		mini[a[i]]=1;
	}
	Set2(m+1,1);
//	cout<<maxn[3]<<"check\n";
	rep(i,1,n+1){
	//	cout<<last[i]<<"Last\n";
		if(!last[i]){
			maxn[i]=max(maxn[i],i+Get(n)-Get(i));
		}
		else{
			maxn[i]=max(maxn[i],Get2(m+1)-Get2(last[i]));
		}
		printf("%d %d\n",mini[i],maxn[i]);
	}
}