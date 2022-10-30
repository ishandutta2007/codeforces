/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll unsigned long long
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
int cnt,root,ch[300005][26],cntb,val[300005];
string s;
string ts[600];
ll h[600],pow_37[300005],p[300005],mod=998244353;
bool f[600];
void update(int now,string &s,int &x,int add){
	if(!x)x=++cnt;
	if(now==-1){
		val[x]+=add;RE ;
	}
	update(now-1,s,ch[x][s[now]-'a'],add);
}
int get(int x,string &s,int now){
	if(!x)RE 0;
	int re=val[x];
	if(now==-1)RE re;
	else RE get(ch[x][s[now]-'a'],s,now-1)+re;
}
signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	int q;
//	scanf("%d",&q);
	cin>>q;
	int B=547;
	pow_37[0]=1;
	FOR(i,1,300000)pow_37[i]=pow_37[i-1]*37%mod;
	FOR(i,1,q){
		int x;
		cin>>x;
		cin>>s;
		if(x==1){
			if(s.size()<B){
				update(s.size()-1,s,root,1);
			}else{
				ts[++cntb]=s;
				rep(j,0,s.size()){
					h[cntb]=(h[cntb]*37+s[j]-'a')%mod;
				}
			}
		}else if(x==2){
			if(s.size()<B){
				update(s.size()-1,s,root,-1);
			}else {
				ll now=0;
				rep(j,0,s.size()){
					now=(now*37+s[j]-'a')%mod;
				}
				FOR(j,1,cntb)if(!f[j]){
					if(h[j]==now){
						f[j]=1;break;
					}
				}
			}
		}else{
			p[0]=0;
			rep(j,0,s.size())p[j+1]=(p[j]*37+s[j]-'a')%mod;
			int ans=0;
			FOR(j,1,cntb)if(!f[j]){
				int len=ts[j].size();
				if(len<=s.size()){
					rep(k,len-1,s.size()){
						if((p[k+1]-p[k-len+1]*pow_37[len]%mod+mod)%mod==h[j]){
							ans++;
						}
					}
				}
			}
			rep(j,0,s.size()){
				ans+=get(root,s,j);
			}
			cout<<ans<<'\n';
		}
	}
	RE 0;
}