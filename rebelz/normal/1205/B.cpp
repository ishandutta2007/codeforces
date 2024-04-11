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

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
ll a[100005],p[1005],c[125][125],q[125][2];
bool vis[125];
vector<pll> v;

int bfs(int st,int ed){
	int front=0,rear=0;
	memset(vis,false,sizeof(vis));
	q[rear++][0]=st; vis[st]=true;
	while(front<rear){
		int t=q[front][0],step=q[front][1]; front++;
		if(t==ed) return step;
		for(int i=1;i<=tot;i++){
			if(t==st&&i==ed) continue;
			if(vis[i]) continue;
			if(c[t][i]!=1) continue;
			vis[i]=true;
			q[rear][0]=i,q[rear][1]=step+1;
			rear++;
		}
	}
	return (1<<30)-1;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=0;i<=60;i++){
		int cnt=0;
		for(int j=1;j<=n;j++) if((a[j]>>i)&1) cnt++;
		if(cnt>=3) return printf("3\n"),0;
		if(cnt==2){
			int tmp=-1;
			for(int j=1;j<=n;j++){
				if((a[j]>>i)&1){
					if(tmp==-1) tmp=j;
					else p[++tot]=tmp,p[++tot]=j,v.push_back(mp(tmp,j));
				}
			}
		}
	}
	sort(p+1,p+tot+1); tot=unique(p+1,p+tot+1)-p-1;
	for(int i=0;i<v.size();i++) v[i].fi=lower_bound(p+1,p+tot+1,v[i].fi)-p,v[i].se=lower_bound(p+1,p+tot+1,v[i].se)-p;
//	for(auto x:v) cout<<"tt "<<x.fi<<' '<<x.se<<endl;
	for(auto x:v) c[x.fi][x.se]=c[x.se][x.fi]=1;
	int ans=1<<30;
	for(auto x:v) ans=min(ans,bfs(x.fi,x.se)+1);
	if(ans==(1<<30)) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}