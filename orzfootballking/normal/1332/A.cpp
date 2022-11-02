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
void solve(){
	int a,b,c,d,x1,y1,x2,y2,x3,y3;
	cin>>a>>b>>c>>d;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	x1-=a;
	x1+=b;
	y1-=c;
	y1+=d;
	if(x1>=x2&&x1<=x3&&y1>=y2&&y1<=y3&&(x2!=x3||(!a&&!b))&&(y2!=y3||(!c&&!d))){
		cout<<"Yes\n";
	}else cout<<"No\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}