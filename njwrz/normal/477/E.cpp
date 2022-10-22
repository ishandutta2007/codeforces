#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
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
#define gmin(a,b) a=min(a,b)
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
struct query{
	int stx,sty,edx,edy,id,add;
};
V<query> v1,v2;
int n,Q;
int ans[400005],a[400005],l2[400005]; 
struct sol{
	int mi[20][400005],mi2[20][400005];
	int getmi(int l,int r){
		int t=l2[r-l+1];
		RE (mi[t][l]<mi[t][r-(1<<t)+1])?mi[t][l]:mi[t][r-(1<<t)+1];
	}
	int getmi2(int l,int r){
		int t=l2[r-l+1];
		RE (mi2[t][l]<mi2[t][r-(1<<t)+1])?mi2[t][l]:mi2[t][r-(1<<t)+1];
	}
	int mini[1<<20];
	V<query> v[400005];
	void update(int x,int l,int r,int to,int val){
		if(l==r){
			mini[x]=val;RE;
		}
		int mid=(l+r)>>1;
		if(mid>=to)update(lc,l,mid,to,val);
		else update(rc,mid+1,r,to,val);
		mini[x]=min(mini[lc],mini[rc]);
	}
	int find(int x,int l,int r,int val){
		if(l==r)RE l;
		int mid=(l+r)>>1;
		if(mini[lc]<=val)RE find(lc,l,mid,val);
		else RE find(rc,mid+1,r,val);
	}
	void solve(){
		FOR(i,1,n)mi[0][i]=a[i],mi2[0][i]=a[i]+i*2;
		rep(j,1,20){
			FOR(i,1,n-(1<<j)+1){
				mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
				mi2[j][i]=min(mi2[j-1][i],mi2[j-1][i+(1<<(j-1))]);
			}
		}
		for(auto u:v1)v[u.edx].PB(u);
		rep(i,0,(1<<20))mini[i]=1e9;
		for(int i=n;i>=1;i--){
			update(1,1,n,i,a[i]);
			for(auto u:v[i]){
				if(u.sty<=u.edy){
					int now=find(1,1,n,u.edy);
					int ta=u.stx-u.edx;
					if(now<=u.stx&&a[now]<=u.edy){
						gmin(u.sty,getmi(now,u.stx));
						u.stx=now;
						int t=u.edy-u.sty;
						gmin(t,u.edy-a[now]+1);
						gmin(now,u.stx);
						if(now-1>=u.edx)gmin(t,getmi(u.edx,now-1)-u.edy+1);
						ta+=t;
					}else{
						int t=min(u.edy+1,u.edy-u.sty);
						if(a[now]<=u.edy){
							gmin(t,2*(now-u.stx)+u.edy-a[now]+1);
						}else now++;
						if(now-1>=u.stx)gmin(t,getmi2(u.stx,now-1)-u.stx*2-u.edy+1);
						gmin(t,getmi(u.edx,u.stx)-u.edy+1);
						ta+=t;
					}
					ta+=u.add;
					gmin(ans[u.id],ta);
				}else{
					int now=find(1,1,n,u.edy);
					int ta=u.stx-u.edx;
					if(now<=u.stx&&a[now]<=u.edy){
						gmin(u.sty,getmi(now,u.stx));
						u.stx=now;
						int t=u.edy-u.sty;
						gmin(t,u.edy-a[now]+1);
						gmin(now,u.stx);
						if(now-1>=u.edx)gmin(t,getmi(u.edx,now-1)-u.edy+1);
						ta+=t;
					}else{
						int t=min(u.edy+1,min(u.sty,getmi(u.edx,u.stx))-u.edy);
						if(a[now]<=u.edy){
							gmin(t,2*(now-u.stx)+u.edy-a[now]);
						}else now++;
						if(now-1>=u.stx)gmin(t,getmi2(u.stx,now-1)-u.stx*2-u.edy);
						ta+=t;
					}
					ta+=u.add;
					gmin(ans[u.id],ta);
				}
			}
		}
	}
}T1,T2;
int mi[20][400005];
int getmi(int l,int r){
	int t=l2[r-l+1];
	RE min(mi[t][l],mi[t][r-(1<<t)+1]);
}
void read(int &x){
	x=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-'0',c=getchar();
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
signed main(){
//	freopen("paimon.in","r",stdin);
//	freopen("paimon.out","w",stdout);
//	freopen("in.txt","r",stdin);
//	freopen("out1.txt","w",stdout);
	FOR(i,2,400000)l2[i]=l2[i/2]+1;
	read(n);
	FOR(i,1,n)read(a[i]);
	FOR(i,1,n)mi[0][i]=a[i];
	rep(j,1,20){
		FOR(i,1,n-(1<<j)+1){
			mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
		}
	}
	read(Q);
	FOR(i,1,Q){
		ans[i]=1e9;
		query now;
		now.add=0;
		read(now.stx);read(now.sty);read(now.edx);read(now.edy);
		now.id=i;
		if(now.stx<now.edx){
			now.stx=n-now.stx+1;
			now.edx=n-now.edx+1;
			v2.PB(now);
			now.stx=n-now.stx+1;
			now.edx=n-now.edx+1;
			gmin(now.sty,getmi(now.stx,now.edx));
			now.add+=now.edx-now.stx;
			now.stx=now.edx;
			v1.PB(now);
		}else {
			v1.PB(now);
			gmin(now.sty,getmi(now.edx,now.stx));
			now.add+=now.stx-now.edx;
			now.stx=now.edx;
			now.stx=n-now.stx+1;
			now.edx=n-now.edx+1;
			v2.PB(now);
		}
	}
	T1.solve();
	reverse(a+1,a+n+1);
	v1=v2;
	T2.solve();
	FOR(i,1,Q)write(ans[i]),putchar('\n');
	RE 0;
}