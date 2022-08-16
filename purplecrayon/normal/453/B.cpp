#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<cmath>
#include<vector>
#define int64 long long
#define mk make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define VI vector<int>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define N 110
using namespace std;
const double pi=acos(-1);
const int pri[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int a[N],mask[66],f[N][(1<<10)+10],pos[N][(1<<10)+10],n,id[N],id1,id2,
	ans[N],Minn=1e9;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),id[i]=i;
	rep(i,1,60){
		rep(j,0,9)if(i%pri[j]==0)mask[i]|=1<<j;
	}
	sort(id+1,id+n+1,[](int x,int y){ return a[x]<a[y];} );
	memset(f,3,sizeof(f));
	f[0][0]=0;
	rep(i,1,n){
		rep(j,0,(1<<10)-1)if(f[i-1][j]<1e5)
			rep(k,1,60)if(k==1 || (mask[k] && (mask[k]&j)==0))
				if(f[i-1][j]+abs(k-a[id[i]])<f[i][j|mask[k]]){
					f[i][j|mask[k]]=f[i-1][j]+abs(k-a[id[i]]);
					pos[i][j|mask[k]]=k;
				}
		if(n-i>7)continue;
		int minn=1e9,tmp;
		rep(j,0,(1<<10)-1)if(f[i][j]<minn)minn=f[i][j],tmp=j;
		rep(j,i+1,n)minn+=abs(a[id[j]]-pri[j-i-1+10]);
		if(minn<Minn){
			Minn=minn;
			id1=i;
			id2=tmp;
		}
	}
	for(int i=n;i>id1;--i)ans[i]=pri[i-id1-1+10];
	for(int i=id1;i>=1;--i){
		ans[i]=pos[i][id2];
		id2^=mask[ans[i]];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(id[j]==i)printf("%d ",ans[j]);
}