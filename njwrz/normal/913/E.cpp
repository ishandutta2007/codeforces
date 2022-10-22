#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
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
int p[8],it[3];
int a[8][3]={
0,0,0,
0,0,1,
0,1,0,
0,1,1,
1,0,0,
1,0,1,
1,1,0,
1,1,1
};
void gmin(string &x,string y){
	if(x.size()>y.size())x=y;
	else if(x.size()==y.size()){
		x=min(x,y);
	}
}
string s[3]={"x","y","z"};
string dp[1<<8][2],ans[1<<8];
int to(int now,int tap,int t){
	if(tap==1){
		rep(i,0,8){
			if(a[i][t]==0){
				now&=(1<<i);
			}
		}
	}else{
		rep(i,0,8){
			if(a[i][t]==1){
				now|=(1<<i);
			}
		}
	}
	RE now;
}
int rev(int now){
	RE now^((1<<8)-1);
}
bool check(string a,string b){
	RE a.size()<b.size()||(a.size()==b.size()&&a<b);
}
void solve(){
	int num=0;
	rep(i,0,8){
		char c;
		cin>>c;
		p[i]=c-'0';
		if(p[i])num|=1<<i;
	}
	if(ans[num][0]=='z'&&ans[num][ans[num].size()-1]=='z'&&ans[num].size()>1){
		cout<<"-1\n";
	}else{
		cout<<ans[num]<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	rep(i,0,1<<8)dp[i][0]=dp[i][1]=ans[i]="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	dp[to(0,0,0)][0]="x";
	dp[to(0,0,1)][0]="y";
	dp[to(0,0,2)][0]="z";
	dp[rev(to(0,0,0))][0]="!x";
	dp[rev(to(0,0,1))][0]="!y";
	dp[rev(to(0,0,2))][0]="!z";
	priority_queue<P<P<int,string>,P<int,bool> >,V<P<P<int,string>,P<int,bool> > >,greater<P<P<int,string>,P<int,bool> > > > q;
	q.emplace(MP(MP(1,"x"),MP(to(0,0,0),0)));
	q.emplace(MP(MP(1,"y"),MP(to(0,0,1),0)));
	q.emplace(MP(MP(1,"z"),MP(to(0,0,2),0)));
	q.emplace(MP(MP(2,"!x"),MP(rev(to(0,0,0)),0)));
	q.emplace(MP(MP(2,"!y"),MP(rev(to(0,0,1)),0)));
	q.emplace(MP(MP(2,"!z"),MP(rev(to(0,0,2)),0)));
	V<P<int,bool> > out;
	while(!q.empty()){
		P<P<int,string>,P<int,bool> > cur=q.top();q.pop();
//		cout<<cur.S<<' '<<cur.F.S<<'\n';
		if(cur.F.S!=dp[cur.S.F][cur.S.S])continue;
		gmin(ans[cur.S.F],cur.F.S);
		string t="!("+cur.F.S+")";
		if(check(t,dp[rev(cur.S.F)][0])){
			dp[rev(cur.S.F)][0]=t;
			q.emplace(MP(t.size(),t),MP(rev(cur.S.F),0));
		}
		for(auto u:out){
			string t1=dp[u.F][u.S],t2=cur.F.S;
			if(u.S==1)t1="("+t1+")";
			if(cur.S.S==1)t2="("+t2+")";
			string t=t1+"&"+t2;
			int to=u.F&cur.S.F;
			gmin(t,t2+"&"+t1);
			if(check(t,dp[to][0])){
				dp[to][0]=t;
				q.emplace(MP(MP(t.size(),t),MP(to,0)));
			}
			t1=dp[u.F][u.S],t2=cur.F.S;
			t=t1+"|"+t2;
			to=u.F|cur.S.F;
			gmin(t,t2+"|"+t1);
			if(check(t,dp[to][1])){
				dp[to][1]=t;
				q.emplace(MP(MP(t.size(),t),MP(to,1)));
			}
		}
		out.PB(cur.S);
	}
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}