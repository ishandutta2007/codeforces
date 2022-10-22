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
long double a[100005];
int p[100005],num[100005],n,l[100005],r[100005],m,b[100005],h[100005],tp[100005];
P<int,int> tb[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>b[i]>>h[i]>>l[i]>>r[i];
	FOR(i,1,m)cin>>tb[i].F>>tb[i].S;
	sort(tb+1,tb+m+1);
	FOR(i,1,m){
		p[i]=tb[i].F,num[i]=tb[i].S;
	}
	FOR(i,0,m)a[i]=1;
	FOR(i,1,n){
		int tl=lwb(p+1,p+m+1,b[i]-h[i])-p,tr=lwb(p+1,p+m+1,b[i])-1-p;
		if(tl<=tr&&l[i]<100){
			a[tl]*=(100-l[i])/100.0;
			a[tr+1]*=100.0/(100-l[i]);
		}else if(tl<=tr){
			tp[tl]++;tp[tr+1]--;
		}
		tl=upb(p+1,p+m+1,b[i])-p,tr=upb(p+1,p+m+1,b[i]+h[i])-p-1;
		if(tl<=tr&&r[i]<100){
			a[tl]*=(100-r[i])/100.0;
			a[tr+1]*=100.0/(100-r[i]);
		}else if(tl<=tr){
			tp[tl]++;tp[tr+1]--;
		}
	}
	double ans=0;
	FOR(i,1,m){
		a[i]*=a[i-1],tp[i]+=tp[i-1];
		if(!tp[i])ans+=a[i]*num[i];
	}
	printf("%.10f",ans); 
	RE 0;
}