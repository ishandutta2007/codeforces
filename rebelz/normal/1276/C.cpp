#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,fr,tnx,an,am,tans;
int a[400005],p[400005],cnt[400005],ans[400005];
pii g[400005];
vector<int> v[400005];

int id(int x,int y){return (x-1)*am+y;}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) p[i]=a[i]=readint();
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+n+1,a[i])-p;
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
		v[cnt[a[i]]].push_back(a[i]);
	}
	int now=0;
	for(int i=1;i<=n;i++){
		now+=v[i].size();
		if(now>=1ll*i*i){
			int nans=i*(now/i);
			if(chkmax(tans,nans)) fr=i,tnx=now;
		}
	}
	an=fr,am=tnx/fr;
	for(int i=1;i<=n;i++) g[++m]=mp(min(fr,cnt[i]),p[i]);
	sort(g+1,g+m+1); reverse(g+1,g+m+1);
	int nowx=1,nowy=1,ccnt=0,all=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=g[i].fi;j++){
			ans[id(nowx,nowy)]=g[i].se;
			nowx++,nowy++,ccnt++,all++;
			if(nowx>an) nowx-=an;
			if(ccnt==fr) ccnt=0,nowy-=an-1;
			while(nowy>am) nowy-=am;
			while(nowy<=0) nowy+=am;
			if(all==an*am) break;
		}
		if(all==an*am) break;
	}
	printf("%d\n%d %d\n",an*am,an,am);
	for(int i=1;i<=an;i++){
		for(int j=1;j<=am;j++) printf("%d ",ans[id(i,j)]);
		printf("\n");
	}
	return 0;
}