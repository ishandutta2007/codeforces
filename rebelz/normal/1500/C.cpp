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

mt19937 mrand(12);
int n,m;
int a[1505][1505],b[1505][1505],trans[1505],cnt[1505];
bool vis[1505],cut[1505];
ull val[1505];
pair<ull,int> ha[1505],hb[1505];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) b[i][j]=readint();
	for(int i=1;i<=n;i++) val[i]=((ull)mrand()<<32)+mrand();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) ha[i].fi=ha[i].fi*19260817+a[i][j],hb[i].fi=hb[i].fi*19260817+b[i][j];
		ha[i].se=hb[i].se=i;
	}
	stable_sort(ha+1,ha+n+1);
	stable_sort(hb+1,hb+n+1);
	for(int i=1;i<=n;i++){
		if(ha[i].fi!=hb[i].fi){
			printf("-1\n");
			return 0;
		}
		trans[hb[i].se]=ha[i].se;
	}
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) if(b[i][j]>b[i+1][j]) cnt[j]++;
	vector<int> ans(0);
	int ccnt=0;
	for(int i=1;i<=m;i++){
		int opt=0;
		for(int j=1;j<=m;j++) if(!vis[j]&&!cnt[j]) opt=j;
		if(!opt){
			for(int j=2;j<=n;j++){
				if(!cut[j]&&trans[j-1]>trans[j]){
					printf("-1\n");
					return 0;
				}
			}
			break;
		}
		for(int j=2;j<=n;j++){
			if(!cut[j]&&b[j-1][opt]<b[j][opt]){
				cut[j]=1,ccnt++;
				for(int k=1;k<=m;k++) if(b[j-1][k]>b[j][k]) cnt[k]--;
			}
		}
		vis[opt]=1;
		ans.pb(opt);
		if(ccnt==n-1) break;
	}
	printf("%d\n",ans.size());
	reverse(ans.begin(),ans.end());
	for(auto r:ans) printf("%d ",r);
	printf("\n");
	return 0;
}