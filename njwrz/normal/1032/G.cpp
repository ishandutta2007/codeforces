#include<bits/stdc++.h>
#define ll long long
#define lb long double
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
int n,a[100005],l2[100005];
int l[18][100005],r[18][100005],mi[17][17][100005],mx[17][17][100005];
int getmi2(int x,int l,int r){
	int t=l2[r-l+1];
	RE min(mi[x][t][l],mi[x][t][r-(1<<t)+1]);
}
int getmi(int x,int l,int r){
	if(l<1&&r>n){
		RE min(getmi2(x,1,n),getmi2(x,l+n,n)-n);
	}else if(l<1){
		RE min(getmi2(x,1,r),getmi2(x,l+n,n)-n);
	}else if(r>n){
		RE min(getmi2(x,l,n),getmi2(x,1,r-n)+n);
	}else RE getmi2(x,l,r);
}
int getmx2(int x,int l,int r){
	int t=l2[r-l+1];
	RE max(mx[x][t][l],mx[x][t][r-(1<<t)+1]);
}
int getmx(int x,int l,int r){
	if(l<1&&r>n){
		RE max(getmx2(x,1,n),getmx2(x,1,r-n)+n);
	}else if(l<1){
		RE max(getmx2(x,1,r),getmx2(x,l+n,n)-n);
	}else if(r>n){
		RE max(getmx2(x,l,n),getmx2(x,1,r-n)+n);
	}else RE getmx2(x,l,r);
}
void build(int x){
	FOR(i,1,n)mi[x][0][i]=l[x][i],mx[x][0][i]=r[x][i];
	FOR(i,1,17){
		FOR(j,1,n-(1<<i)+1){
			mi[x][i][j]=min(mi[x][i-1][j],mi[x][i-1][j+(1<<(i-1))]);
			mx[x][i][j]=max(mx[x][i-1][j],mx[x][i-1][j+(1<<(i-1))]);
		}
	}
}
signed main(){
//	freopen("sn.in","r",stdin);
//	freopen("sn.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,2,n)l2[i]=l2[i/2]+1;
	FOR(i,1,n){
		l[0][i]=i-a[i];
		r[0][i]=i+a[i];
	}
	if(n==1){
		cout<<0;RE 0;
	}
	build(0);
	FOR(i,1,16){
		FOR(j,1,n){
			if(r[i-1][j]-l[i-1][j]+1>=n){
				l[i][j]=l[i-1][j];r[i][j]=r[i-1][j];continue;
			}
			l[i][j]=getmi(i-1,l[i-1][j],r[i-1][j]);gmax(l[i][j],-n+1);
			r[i][j]=getmx(i-1,l[i-1][j],r[i-1][j]);gmin(r[i][j],n+n);
		}
		build(i);
	}
	FOR(i,1,n){
		int l=i,r=i;
		int step=0;
		for(int i=16;i>=0;i--){
			int tol=getmi(i,l,r),tor=getmx(i,l,r);
			if(tor-tol+1>=n)continue;
			step+=1<<i;
			l=tol;r=tor;
		}
		cout<<step+1<<' ';
	}
	RE 0;
}