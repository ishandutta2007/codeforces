// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[1000005];
bool vis[1000005];
bool dp[1000005][30];
int fr[1000005][30];
vector<pii> ans;

void solve1(){
	vector<int> vec;
	for(int i=1;i<=n;i++) if(s[i]=='1') vec.pb(i);
	for(int i=1;i<=n;i++) vis[i]=0;
	vector<int> d;
	for(int i=vec[3]+1;i<=n-2;i++){
		if(s[i]=='1'){
			d.pb(i);
			vis[i]=vis[i+1]=vis[i+2]=1;
			i+=2;
		}
	}
	int k=vec.size();
	int now=1;
	while(now<k) now<<=1;
	int rem=now-k;
	for(auto r:d){
		if(s[r+1]=='0'&&s[r+2]=='0'){
			if(rem>=3) ans.pb(mp(r,r+2)),rem-=3;
			else ans.pb(mp(r,r)),ans.pb(mp(r+1,r+1)),ans.pb(mp(r+2,r+2));
		}
		else if(s[r+1]=='0'&&s[r+2]=='1'){
			if(rem>=3) ans.pb(mp(r,r+2)),rem-=3;
			else ans.pb(mp(r,r)),ans.pb(mp(r+1,r+1)),ans.pb(mp(r+2,r+2));
		}
		else if(s[r+1]=='1'&&s[r+2]=='0'){
			if(rem>=4) ans.pb(mp(r,r+2)),rem-=4;
			else if(rem>=1) ans.pb(mp(r,r)),ans.pb(mp(r+1,r+2)),rem--;
			else ans.pb(mp(r,r)),ans.pb(mp(r+1,r+1)),ans.pb(mp(r+2,r+2));
		}
		else{
			if(rem>=4) ans.pb(mp(r,r+2)),rem-=4;
			else if(rem>=1) ans.pb(mp(r,r)),ans.pb(mp(r+1,r+2)),rem--;
			else ans.pb(mp(r,r)),ans.pb(mp(r+1,r+1)),ans.pb(mp(r+2,r+2));
		}
	}
	if(rem==1){
		vis[vec[0]]=vis[vec[0]+1]=1;
		ans.pb(mp(vec[0],vec[0]+1));
	}
	else if(rem==2){
		vis[vec[0]]=vis[vec[0]+1]=vis[vec[2]]=vis[vec[2]+1]=1;
		ans.pb(mp(vec[0],vec[0]+1));
		ans.pb(mp(vec[2],vec[2]+1));
	}
	for(int i=1;i<=n;i++) if(!vis[i]) ans.pb(mp(i,i));
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto r:ans) printf("%d %d\n",r.fi,r.se);
}

void solve2(){
	vector<int> vec;
	for(int i=1;i<=n;i++) if(s[i]=='1') vec.pb(i);
	for(int i=1;i<=n;i++) vis[i]=0;
	int now=1;
	int k=vec.size();
	while(now<k) now<<=1;
	int rem=now-k;
	dp[0][0]=1;
	for(int i=1;i<=n;i++) for(int j=0;j<=28;j++) dp[i][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=max(0,i-4);j<i;j++){
			int num=0;
			for(int l=j+1;l<=i;l++) num+=(s[l]-'0')<<(i-l),num-=(s[l]-'0');
			for(int l=0;l<=28-num;l++) if(chkmax(dp[i][l+num],dp[j][l])) fr[i][l+num]=j;
		}
	}
	int tx=n,ty=rem;
	if(dp[n][rem]) ty=rem;
	else if(dp[n][now*2-k]) ty=now*2-k;
	else if(dp[n][now*4-k]) ty=now*4-k;
	while(tx){
		ans.pb(mp(fr[tx][ty]+1,tx));
		int tmp=fr[tx][ty];
		int num=0;
		for(int l=tmp+1;l<=tx;l++) num+=(s[l]-'0')<<(tx-l),num-=(s[l]-'0');
		tx=tmp,ty-=num;
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto r:ans) printf("%d %d\n",r.fi,r.se);
}

int main(){
	int T=readint();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int k=0;
		for(int i=1;i<=n;i++) k+=s[i]=='1';
		if(!k){
			printf("-1\n");
			continue;
		}
		ans.clear();
		if(k>16) solve1();
		else solve2();
	}
	return 0;
}