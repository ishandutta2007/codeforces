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

int n,k;
int a[300005],f[300005],cnt[300005][2],ans[300005],loc[300005],val[300005];
vector<int> v[300005];
char s[300005];
bool vis[300005];

int getf(int x){
	if(x==f[x]) return x;
	int ret=getf(f[x]);
	val[x]^=val[f[x]];
	f[x]=ret;
	return ret;
}

int getmin(int x){return loc[x]<0?min(cnt[x][0],cnt[x][1]):cnt[x][loc[x]^1];}

int main(){
	n=readint(); k=readint();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	int x;
	for(int i=1;i<=k;i++){
		x=readint();
		while(x--) v[readint()].push_back(i);
	}
	for(int i=1;i<=k;i++) f[i]=i,cnt[i][0]=1,vis[i]=0,loc[i]=-1;
	for(int i=1;i<=n;i++){
		if(!v[i].size()) ans[i]=ans[i-1];
		else if(v[i].size()==1){
			ans[i]=ans[i-1];
			int tmp=v[i][0],fx=getf(tmp);
			if(vis[fx]) ans[i]-=getmin(fx);
			loc[tmp]=a[i]^1,vis[tmp]=1;
			if(fx!=tmp) loc[fx]=loc[tmp]^val[tmp];
			ans[i]+=getmin(fx);
		}
		else{
			int fx=getf(v[i][0]),fy=getf(v[i][1]),z;
			if(fx!=fy){
				if(a[i]) z=0;
				else z=1;
				ans[i]=ans[i-1];
				if(vis[fx]) ans[i]-=getmin(fx);
				if(vis[fy]) ans[i]-=getmin(fy);
				f[fx]=fy,val[fx]=z^val[v[i][0]]^val[v[i][1]];
				cnt[fy][0]+=cnt[fx][val[fx]],cnt[fy][1]+=cnt[fx][val[fx]^1];
				vis[fy]=1;
				if(loc[fx]>=0) loc[fy]=loc[fx]^val[fx];
				ans[i]+=getmin(fy);
			}
			else ans[i]=ans[i-1];
		}
		printf("%d\n",ans[i]);
	}
	return 0;
}