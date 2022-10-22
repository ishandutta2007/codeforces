/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
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
using namespace std;
int mod=998244353;
int b[5][5];
struct matrix{
	int s[4][4],n,m;
	void mul(matrix &a){
		FOR(i,1,3){
			FOR(j,1,3)b[i][j]=0;
		}
		FOR(i,1,m){
			FOR(j,1,n){
				FOR(k,1,a.m){
					b[j][k]+=s[j][i]*a.s[i][k];
				}
			}
		}
		FOR(i,1,n){
			FOR(j,1,m){
				s[i][j]=b[i][j]%mod;
			}
		}
	}
};
matrix val[1<<20];
char a[500005];
matrix t;
int num[10]={9,8,7,6,5,4,3,2,1,0};
void build(int x,int tl,int tr){
	if(tl==tr){
		val[x].n=val[x].m=3;
		val[x].s[2][1]=val[x].s[3][2]=1;
		val[x].s[3][3]=(a[tl]-'0')+1;
		if(tl>1&&a[tl-1]-'0'==1){
			val[x].s[2][3]=num[a[tl]-'0'];
		}
		RE;
	}
	int mid=(tl+tr)>>1;
	build(x<<1,tl,mid);
	build((x<<1)|1,mid+1,tr);
	val[x]=val[x<<1];
	val[x].mul(val[(x<<1)|1]);
}
void update(int x,int l,int r,int it){
	if(l==r){
		val[x].s[3][3]=(a[l]-'0')+1;RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it){
		update(x<<1,l,mid,it);
	}else update((x<<1)|1,mid+1,r,it);
	val[x]=val[x<<1];
	val[x].mul(val[(x<<1)|1]);
}
void update1(int x,int l,int r,int it){
	if(l==r){
		val[x].s[2][3]=num[a[l]-'0'];
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it){
		update1(x<<1,l,mid,it);
	}else update1((x<<1)|1,mid+1,r,it);
	val[x]=val[x<<1];
	val[x].mul(val[(x<<1)|1]);
}
void update2(int x,int l,int r,int it){
	if(l==r){
		val[x].s[2][3]=0;RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it){
		update2(x<<1,l,mid,it);
	}else update2((x<<1)|1,mid+1,r,it);
	val[x]=val[x<<1];
	val[x].mul(val[(x<<1)|1]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	t.n=1;t.m=3;t.s[1][1]=t.s[1][2]=0;t.s[1][3]=1;
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	build(1,1,n);
	matrix now=t;
	now.mul(val[1]);
	FOR(i,1,m){
		int it;char to;
		cin>>it>>to;
		char lst=a[it];
		a[it]=to;
		if(it<n&&(to=='1'&&lst!='1'))update1(1,1,n,it+1);
		if(it<n&&(to!='1'&&lst=='1'))update2(1,1,n,it+1);
		if(it>1&&a[it-1]=='1')update1(1,1,n,it);
		update(1,1,n,it);
		now=t;
		now.mul(val[1]);
		cout<<now.s[1][3]<<'\n';
	}
	RE 0;
}