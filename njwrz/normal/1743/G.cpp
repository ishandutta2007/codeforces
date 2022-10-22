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
const int mod=998244353;
int f[35];
int len[35],val[35];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int get(int x,int pos){
	if(x<=1)RE x;
	if(pos>f[x-1])RE get(x-2,pos-f[x-1]);
	else RE get(x-1,pos);
}
map<int,int> mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=f[1]=1;
	FOR(i,2,31)f[i]=f[i-1]+f[i-2];
	FOR(i,1,31)mp[f[i]]=1;
	int sum=1,lst=1,n,cnt=0;cin>>n;
	FOR(_,1,n){
		string s;
		cin>>s;
		for(auto u:s){
			int now=sum;
			int to=0;
			FOR(i,1,cnt){
				if(get(31,len[i]+1)+'0'==u){
					++to;len[to]=len[i]+1;val[to]=val[i];
				}
			}
			if(u=='0')add(now,mod-lst);
			else {
				++to;
				len[to]=1;val[to]=lst;
			}
			cnt=to;
			FOR(i,1,cnt)if(mp.count(len[i]))add(now,mod-val[i]);
			lst=now;add(sum,now);
		}
		cout<<lst<<'\n';
	}
	RE 0;
}