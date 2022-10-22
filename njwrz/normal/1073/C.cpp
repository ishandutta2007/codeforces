#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a[200005];
P<int,int> p[200005],h[200005];
check(int x,int y,int mid,int p){
	x+=h[mid].F;y+=h[mid].S;
	RE abs(x)+abs(y)<=mid-p-1&&(!((mid-p-1-abs(x)-abs(y))&1));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int x,y;
	char c;
	FOR(i,1,n){
		cin>>c;
		if(c=='R'){
			p[i].F=1;
		}else if(c=='L'){
			p[i].F=-1;
		}else if(c=='D'){
			p[i].S=-1;
		}else p[i].S=1;
	} 
	for(int i=n;i>=1;i--){
		h[i]=h[i+1];
		h[i].F+=p[i].F;
		h[i].S+=p[i].S;
	}
	cin>>x>>y;
	int mini=2147483647,l,r,mid,ans;
	rep(i,0,n){
		x-=p[i].F;y-=p[i].S;
		l=i+1;r=n+1;ans=2147483647;
		while(r>=l){
			mid=(l+r)>>1;
			if(check(-x,-y,mid,i)){
				r=mid-1;ans=mid-i-1;
			}else l=mid+1;
		}
		mini=min(mini,ans);
	}
	if(mini==2147483647)cout<<-1;
	else cout<<mini;
	RE 0;
}