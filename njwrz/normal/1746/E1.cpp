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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int node[100005],len,n;
int ask(int l,int r){
	V<int> nd;
	FOR(i,l,r){
		if(node[i]<=n)nd.PB(node[i]);
	}
	if(nd.empty())RE 0;
	cout<<"? ";
	cout<<nd.size()<<' ';
	for(auto u:nd)cout<<u<<' ';
	cout<<'\n';cout.flush();
	string s;
	cin>>s;
	RE s=="YES";
}
mt19937_64 rnd(time(0));
void solve(V<int> v,int lst){
	if(v.size()<=3){
		len=0;
		for(auto u:v)node[++len]=u;
		if(len==3){
			int t1=ask(1,1);
			if(t1){
				int t2=ask(2,2);
				if(t1&&t2){
					len=2;
				}
				if(t1&&!t2){
					len=2;
					node[2]=node[3];
				}
			}else{
				t1=ask(1,1);
				if(!t1){
					node[1]=node[2];node[2]=node[3];len=2;
				}
				int t2=ask(2,2);
				if(t1&&t2){
					len=2;
				}
				if(t1&&!t2){
					len=2;
					node[2]=node[3];
				}
			}
		}
		if(len<=2){
			FOR(i,1,len){
				if(node[i]<=n){
					cout<<"! "<<node[i]<<'\n';
					cout.flush();
					string s;
					cin>>s;
					if(s==":)")exit(0);
				}
			}
		}
	}
	int res=v.size()-lst;
	int t1=(lst+1)/2,t2=res/2;
	len=0;
	rep(i,0,t1)node[++len]=v[i];//1
	rep(i,lst,lst+t2)node[++len]=v[i];//  0
	rep(i,t1,lst)node[++len]=v[i];//1
	rep(i,lst+t2,sz(v))node[++len]=v[i];//0
	int t=!ask(1,t1+t2);
	if(t){
		V<int> now;
		rep(i,lst,lst+t2)now.PB(v[i]);
		rep(i,t1,lst)now.PB(v[i]); 
		rep(i,lst+t2,sz(v))now.PB(v[i]);
		solve(now,t2);
	}else{
		V<int> now;
		rep(i,lst+t2,sz(v))now.PB(v[i]);
		int val=now.size();
		rep(i,0,t1)now.PB(v[i]);
		rep(i,lst,lst+t2)now.PB(v[i]);
		solve(now,val);
	}
}
signed main(){
	cin>>n;
	V<int> v; 
	if(n>=90000){
		FOR(i,1,100000)v.PB(i);
	}else FOR(i,1,n)v.PB(i);
	solve(v,0);
	RE 0;
}