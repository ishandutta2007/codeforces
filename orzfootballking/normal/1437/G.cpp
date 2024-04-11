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
int n;
int ch[300005][26];
int id[300005],c[300005];P<int,int> ham[300005];
string name[300005];
set<P<int,int> > s[300005];
V<int> d[300005]; 
int len=550,cnt=1,type[300005],nowl,nowr,totlen,nal[300005],mod1=1e9+7,mod2=1e9+9;
int cha[600005];
int pow1[600005],pow2[600005],nowid;
int Bit=31;
int toa1[600005],toa2[600005];
bool vis[300005];
V<int> vv;
void solve(int l,int r){
	FOR(i,l,r){
		pow1[i]=1ll*pow1[i-1]*Bit%mod1;
		pow2[i]=1ll*pow2[i-1]*Bit%mod2;
		toa1[i]=(1ll*toa1[i-1]*Bit+cha[i])%mod1;
		toa2[i]=(1ll*toa2[i-1]*Bit+cha[i])%mod2;
	}
}
P<int,int> get(int l,int r){
	RE MP((toa1[r]-toa1[l-1]*pow1[r-l]%mod1+mod1)%mod1,
	(toa2[r]-toa2[l-1]*pow2[r-l]%mod2+mod2)%mod2);
}
int find(int x,string &now,int iter,int lst){
	if(!x)RE -1;
	int re;
	if(s[x].empty())re=-1;
	else re=-(*s[x].begin()).F;
	if(lst==0){
		for(auto u:d[x]){
			if(!vis[u]&&ham[u]==get(nowr-nal[u]+1,nowr)){
				gmax(re,c[u]);vis[u]=1;vv.PB(u);
			}
		}
		RE re;
	}
	if(iter==-1)RE re;
	int t=ch[x][now[iter]-'a'];
	RE max(re,find(t,now,--iter,--lst));
}
void up1(int x,string &now,int iter){
	if(iter==-1){
		id[nowid]=x;
		s[x].emplace(MP(0,nowid));RE;
	}
	if(ch[x][now[iter]-'a']==0){
		ch[x][now[iter]-'a']=++cnt;
	}
	int t=ch[x][now[iter]-'a'];
	up1(t,now,--iter);
}
void add1(int x){
	up1(1,name[x],nal[x]-1);
}
void up2(int x,string &now,int iter,int lst){
	if(!lst){
		id[nowid]=x;
		d[x].PB(nowid);RE;
	}
	if(!ch[x][now[iter]-'a']){
		ch[x][now[iter]-'a']=++cnt;
		up2(cnt,now,--iter,--lst);
	}else {
		int t=ch[x][now[iter]-'a'];
		up2(t,now,--iter,--lst);
	}
}
void add2(int x){
	ham[x]=get(nowl,nowr);
	up2(1,name[x],nal[x]-1,len);
}
signed main(){
	pow1[0]=1;pow2[0]=1;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	FOR(i,1,n){
		nowid=i;
		cin>>name[i];
		nal[i]=name[i].size();
		if(name[i].size()>550){
			add2(i);type[i]=2;
		}else add1(i),type[i]=1;
		nowl=totlen+1;
		for(auto u:name[i]){
			cha[++totlen]=u-'a';
		}
		nowr=totlen;
		solve(nowl,nowr);
//		cout<<'\n';
//		cout<<id[i]<<' ';
	}
//	cout<<'\n';
	FOR(i,1,m){
		int f;
		cin>>f;
		if(f==1){
			int pp,to;
			cin>>pp>>to;
			if(type[pp]==1){
				s[id[pp]].erase(MP(-c[pp],pp));
				c[pp]=to;
				s[id[pp]].emplace(MP(-c[pp],pp));
			}else{
				c[pp]=to;
			}
		}else{
			vv.clear();
			string now;
			cin>>now;
			nowl=totlen+1;
			for(auto u:now){
				cha[++totlen]=u-'a';
			}
			nowr=totlen;
			solve(nowl,nowr);
			int ans=-1;
			rep(j,0,now.size()){
				gmax(ans,find(1,now,j,len));
			}
			cout<<ans<<'\n';
			for(auto u:vv)vis[u]=0;
		}
	}
	RE 0;
}