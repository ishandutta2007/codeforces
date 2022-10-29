#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=(int)2e5+9;
struct peo{
	int p,s;
}hero[N];
int a[N],cnt;
bool cmp(peo a,peo b){
	if(a.s^b.s)return a.s>b.s;
	return a.p>b.p;
}
int find(int s){
	int l=0,r=cnt-1;
	while(l<r){
		int mid=l+r>>1;
		if(hero[mid].s>=s)l=mid+1;
		else r=mid;
	}
	if(hero[l].s>=s)return hero[l].p;
	return hero[l-1].p;
}
int main() 
{
	int t;
	cin>>t;
	while(t--){
		int n,m,maxn1=0,maxn2=0;
		scanf("%d",&n);
		rep(i,0,n)scanf("%d",&a[i]),maxn1=max(maxn1,a[i]);
		scanf("%d",&m);
		rep(i,0,m)scanf("%d%d",&hero[i].p,&hero[i].s),maxn2=max(maxn2,hero[i].p);
		if(maxn2<maxn1){
			printf("-1\n");
			continue;
		}
		sort(hero,hero+m,cmp);
		cnt=0;
		rep(i,1,m)if(hero[i].p>hero[cnt].p)hero[++cnt]=hero[i];
		++cnt;
		int last=0,ans=0,maxn=0;
		rep(i,0,n){
			++last;
			if(last>hero[0].s){
				last=1;
				++ans;
				maxn=a[i];
			//	cout<<ans<<"ans1\n";
				continue;
			}
			maxn=max(a[i],maxn);
			if(find(last)<maxn){
			//	cout<<last<<"last\n";
				last=1;
				++ans;
				maxn=a[i];
			//	cout<<ans<<"ans2\n";
				continue;
			}
			//cout<<ans<<"ans\n";
		}
		++ans;
		printf("%d\n",ans);
	}
}