#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
int c3,c4,c5,n,s;
int a3=-1,a4,a5,ans=1e18;
void check(int k3,int k4,int k5){
	if(k3<=k4&&k4<=k5&&k3>=0){
		int now=abs(k4*c4-k3*c3)+abs(k5*c5-k4*c4);
		if(now<ans)a3=k3,a4=k4,a5=k5,ans=now;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s;
	FOR(i,1,n){
		int x;
		cin>>x;
		if(x==3)c3++;else if(x==4)c4++;else c5++;
	}
	FOR(k4,0,s)if(k4*c4<=s){
		int ts=s-k4*c4;
		rep(mk5,0,c3)if(mk5*c5<=ts){
			int nows=ts-mk5*c5;
			if(nows%c3!=0)continue;
			int k3=nows/c3;
			int k5=mk5;
			if(k4<k3){
				int t=(k3-k4+c5-1)/c5;
				k3-=t*c5;
				k5+=t*c3;
			}
			if(k5<k4){
				int t=(k4-k5+c3-1)/c3;
				k3-=t*c5;
				k5+=t*c3;
			}
			if(k3<0)continue;
			int tk5=max(k5,(k4*c4+c5-1)/c5);
			int tk3=min(k3,(k4*c4)/c3);
			check(k3,k4,k5);
			int t=k3/c5;
			check(k3-t*c5,k4,k5+t*c3);
			t=(tk5-k5)/c3;
			check(k3-t*c5,k4,k5+t*c3);
			t++;
			check(k3-t*c5,k4,k5+t*c3);
			t=(k3-tk3)/c5;
			check(k3-t*c5,k4,k5+t*c3);
			t++;
			check(k3-t*c5,k4,k5+t*c3);
		}
	}
//	cout<<a3<<' '<<a4<<' '<<a5<<'\n';
	if(a3==-1)cout<<-1;else cout<<a3<<' '<<a4<<' '<<a5;
	RE 0;
}