#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
vector<pair<int,int> >bin[25];
struct frac{
	int fz,fm;
	bool operator<(const frac&rhs)const{
		return 1LL*fz*rhs.fm<1LL*rhs.fz*fm;
	}
};
int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int,int> >v(n);
	rep(i,0,n-1)scanf("%d%d",&v[i].first,&v[i].second);
	sort(v.begin(),v.end());
	int m=0;
	for(int i=0,j;i<n;i=j){
		j=i+1;
		while(j<n&&v[i].first==v[j].first)++j;
		rep(x,1,20){
			int cur=0;
			rep(k,i,j-1){
				cur+=min(x,v[k].second);
			}
			bin[x].eb(cur,v[i].first);
		}
		++m;
	}
	frac best=(frac){0,1};
	rep(x,1,20)if(x<=m){
		nth_element(bin[x].begin(),bin[x].begin()+x-1,bin[x].end(),greater<pair<int,int> >());
		int cur=0;
		rep(i,0,x-1)cur+=bin[x][i].first;
		best=max(best,(frac){cur,x});
		if(x==20){
			sort(bin[x].begin(),bin[x].end(),greater<pair<int,int> >());
			rep(i,x,SZ(bin[x])-1){
				cur+=bin[x][i].first;
				best=max(best,(frac){cur,i+1});
			}
		}
	}
	printf("%d\n",best.fm);
	rep(i,0,best.fm-1){
		printf("%d ",bin[min(20,best.fm)][i].second);
	}
	return 0;
}