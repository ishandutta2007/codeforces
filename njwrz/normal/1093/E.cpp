#pragma GCC optimize("Ofast")
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
const int len=1000,ln=2e5+5;
bool f[ln];
int lazy[ln],la,mp[ln],a[ln],b[ln],c[ln],d[ln],n,t[ln];
int bl[len+5][len+5],lb[len+5];
void solve(){
	la=0;
	rep(i,0,n){
		f[i]=0;c[i]=d[i];
	}
	rep(i,0,len)lb[i]=0;
	rep(i,0,n)t[d[i]]=i;
	int p;
	rep(i,0,n){
		p=t[i]/len;
		bl[p][lb[p]++]=i;
	}
} 
void solve1(){
	if(la>=len*2)solve();
	int l1,r1,l2,r2;
	cin>>l2>>r2>>l1>>r1;l2--;r2--;l1--;r1--;
	int tl=l1,tr=r1,re=0;
	r1++;
	while(l1<r1&&l1%len){
		if(l2<=c[l1]&&c[l1]<=r2)re++;
		l1++;
	}
	while(l1<r1&&r1%len){
		r1--;
		if(l2<=c[r1]&&c[r1]<=r2)re++;
	}
	int lenl=l1/len,lenr=r1/len;
	while(lenl<lenr){
		re+=lwb(bl[lenl],bl[lenl]+lb[lenl],r2+1)-lwb(bl[lenl],bl[lenl]+lb[lenl],l2);
		lenl++;
	}
	l1=tl;r1=tr;
	int id;
	rep(i,0,la){
		id=lazy[i];
		if(l1<=id&&r1>=id){
			re-=(l2<=c[id]&&c[id]<=r2);
			re+=(l2<=d[id]&&d[id]<=r2);
		}
	}
	cout<<re<<'\n';
}
void solve2(){
	int l,r;
	cin>>l>>r;l--;r--;
	swap(d[l],d[r]);
	if(!f[l]){
		f[l]=1;lazy[la++]=l;
	}
	if(!f[r]){
		f[r]=1;lazy[la++]=r;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	rep(i,0,n)cin>>a[i],a[i]--,mp[a[i]]=i;
	rep(i,0,n)cin>>b[i],b[i]--,d[i]=mp[b[i]];
	solve();
	int type;
	rep(_,0,m){
		cin>>type;
		if(type==1){
			solve1();
		}else{
			solve2();
		}
	}
	RE 0;
}