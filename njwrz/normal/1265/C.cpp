#pragma GCC optimize("Ofast,unroll-loops")
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
V<P<int,int> > v;
void solve(){
	int n,x,last=-1,l;
	v.clear();
	cin>>n;
	FOR(i,1,n){
		cin>>x;
		if(x!=last){
			if(i!=1){
				v.PB(MP(last,l));
			}
			l=1;last=x;
		}else l++;
	}
	v.PB(MP(last,l));
	int t=0,sum=0;
	rep(i,0,v.size()){
		if(sum+v[i].S>n/2)break;
		t++;sum+=v[i].S;
	}
	if(t<3){
		cout<<"0 0 0\n";RE;
	}
	int a,b,c;
	a=v[0].S;b=c=0;
	rep(i,1,t){
		if(b<=a)b+=v[i].S;else c+=v[i].S;
	}
	if(b<=a||c<=a){
		cout<<"0 0 0\n";
	}else cout<<a<<' '<<b<<' '<<c<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}