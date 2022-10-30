#include<bits/stdc++.h>
#define int long long
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
int n,m,k;
string s[205],t[205]; 
int dp[205],cnt[20][20];
bool ff;
int p[605],c[605],len;
void z(){
	int maxi=0;
	FOR(i,2,len){
		if(maxi+p[maxi]-1>=i){
			p[i]=min(maxi+p[maxi]-i,p[i-maxi+1]);
		}else p[i]=0;
		while(i+p[i]<=len&&c[i+p[i]]==c[p[i]+1])p[i]++;
		if(i+p[i]>maxi+p[maxi])maxi=i;
	}
}
int tff;
int get(int x,int y,string &s,string *ts){
	if(x>13)RE cnt[13][14];
	len=0;
	for(auto u:s)c[++len]=u;
	int l=len+1,tl=min(m-1,(int)t[x].size());
	for(int i=(int)t[x].size()-tl;i<t[x].size();i++)c[++len]=t[x][i];
	int r=len;
	for(auto u:ts[y])c[++len]=u;
	z();
	int re=0;
	FOR(i,l,r)if(i+m-1<=len){
		if(p[i]>=s.size()||s[p[i]]>c[i+p[i]]){
			if(p[i]<s.size()||tff)re++;
		}
	}
	cnt[x][y]=re;
	RE re;
}
int get2(int x,string &s,int siz){
	len=0;
	for(auto u:s)c[++len]=u;
	int tl=min(m-1,(int)t[x].size());
	for(int i=(int)t[x].size()-tl;i<t[x].size();i++)c[++len]=t[x][i];
	z();
	int re=0;
	FOR(i,len-tl+1,len){
		if(tff){
			if(p[i]+i-1==len||p[i]>=siz||c[p[i]+i]<s[p[i]]){
				if(len-i+1==siz&&p[i]+i-1==len){
					ff=1;
				}
				re++;
			}
		}else if(p[i]<siz&&(c[p[i]+i]<s[p[i]]||p[i]+i-1==len)){
			if(len-i+1==siz&&p[i]+i-1==len){
				ff=1;
			}
			re++;
		}
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>m;
	s[0]="0";s[1]="1";
	t[0]="0";t[1]="1";
	FOR(i,2,n){
		s[i]=s[i-2]+s[i-1];
		t[i]=t[i-2]+t[i-1];
		if(s[i].size()>m){
			s[i]=s[i].substr(0,m);
			t[i]=t[i].substr(t[i].size()-m,m);
		}
	}
	string ans="";
	FOR(i,1,m){
		string now=ans+"0";
		tff=1;
		FILL(dp,0); FILL(cnt,-1);
		if(m==1){
			dp[0]=1;
			if(i>1&&ans[0]=='1')dp[1]=1;
		}
		FOR(j,2,n){
			dp[j]=dp[j-2]+dp[j-1]+get(j-2,j-1,now,s);
			gmin(dp[j],k+1);
		}
		int sum=dp[n];
		ff=0;
		sum+=get2(n,now,i);
		int nowf=ff;
		if(sum>=k){
			ans+="0";
			FILL(dp,0); FILL(cnt,-1);
			tff=0;
			FOR(j,2,n){
				dp[j]=dp[j-2]+dp[j-1]+get(j-2,j-1,now,s);
				gmin(dp[j],k+1);
			}
			int sum=dp[n];
			ff=0;
			sum+=get2(n,now,i);
			if(sum==k-1&&nowf){
				cout<<ans;
			}
		}else {
			ans+="1";
			if(sum==k-1){
				ff=0;
				get2(n,ans,i);
				if(ff){
					cout<<ans;RE 0;
				}
			}
		}
	}
	cout<<ans;
	RE 0;
}