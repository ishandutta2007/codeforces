#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m[2],t,cnt;
int p[3000005],vis[3000005][2],d[3000005][2],fr[3000005][2];
vector<int> a[2],ans1;
vector<pii> ans2;

int main(){
	n=readint(); m[0]=readint(); m[1]=readint(); t=readint();
	for(int i=0;i<2;i++){
		for(int j=0;j<m[i];j++){
			int x=readint();
			a[i].push_back(x);
			p[++cnt]=x-1;
			p[++cnt]=x;
			p[++cnt]=x+1;
		}
	}
	p[++cnt]=0,p[++cnt]=n+1;
	sort(p+1,p+cnt+1);
	cnt=unique(p+1,p+cnt+1)-p-1;
	for(int i=0;i<2;i++) for(auto x:a[i]) vis[lower_bound(p+1,p+cnt+1,x)-p][i]=1;
	memset(d,-1,sizeof(d));
	d[1][0]=d[1][1]=0;
	for(int i=1;i<cnt;i++){
		for(int j=0;j<2;j++){
			if(d[i][j]<0) continue;
			int dis=p[i+1]-p[i];
			if(!vis[i+1][j]){
				if(chkmax(d[i+1][j],d[i][j]+dis)) fr[i+1][j]=j;
				if(!vis[i+1][j^1]&&chkmax(d[i+1][j^1],min(t,d[i][j]+dis))) fr[i+1][j^1]=j;
			}
			else{
				if(d[i][j]<t) continue;
				if(chkmax(d[i+1][j],d[i][j]-t+dis)) fr[i+1][j]=j;
				if(!vis[i+1][j^1]&&chkmax(d[i+1][j^1],min(t,d[i][j]-t+dis))) fr[i+1][j^1]=j;
			}
		}
	}
	if(d[cnt][0]<0&&d[cnt][1]<0) return printf("No\n"),0;
	printf("Yes\n");
	int pl=0;
	if(d[cnt][0]<0) pl=1;
	for(int i=cnt;i>=2;i--){
		int tpl=fr[i][pl];
		if(tpl!=pl){
			if(vis[i][pl^1]){
				ans2.push_back(mp(p[i]-d[i][pl],tpl+1));
				ans1.push_back(p[i-1]+1);
			}
			else ans1.push_back(p[i-1]+1);
		}
		else{
			if(vis[i][pl]) ans2.push_back(mp(p[i]-d[i][pl],pl+1));
		}
		pl=tpl;
	}
	if(pl==1) ans1.push_back(0);
	reverse(ans1.begin(),ans1.end());
	reverse(ans2.begin(),ans2.end());
	printf("%d\n",ans1.size());
	for(auto x:ans1) printf("%d ",x);
	printf("\n%d\n",ans2.size());
	for(auto x:ans2) printf("%d %d\n",x.fi,x.se);
	return 0;
}