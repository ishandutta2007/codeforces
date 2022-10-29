#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

void chkmax(int &a,int b){if(a<b)a=b;}
void chkmin(int &a,int b){if(a>b)a=b;}

const int mo=1e9+7;
int q;

int max(int a,int b,int c){return max(max(a,b),c);}
void add(int &a,int b){(a+=b)%=mo;}

int X[33],p1;
int Y[33],p2;
int K[33],p3;

struct node {
	int cnt,val;
	node() {cnt=val=0;}
	node(int cnt,int val):cnt(cnt),val(val){}
};
node f[33][2][2][2];

// node dfs(int p,int l1,int l2,int l3) {// x,y,k
// 	if (!l1&&!l2&&vis[p][l3]) return f[p][l3];
// 	if (!p) return node(1,0);
// 	int up1=l1?X[p]:1,up2=l2?Y[p]:1,up3=l3?K[p]:1;
// 	node res;
// 	rep(i,0,up1+1) rep(j,0,up2+1) {
// 		if ((i^j)>up3) continue;
// 		node e=dfs(p-1,l1&&(i==up1),l2&&(j==up2),l3&&((i^j)==up3));
// 		add(res.cnt,e.cnt);
// 		add(res.val,e.val);
// 		if (i^j) add(res.val,1ll*(1<<(p-1))*e.cnt%mo);
// 	}
// 	if (!l1&&!l2) vis[p][l3]=1,f[p][l3]=res;
// 	return res;
// }
int solve(int x,int y) {
	if (!x||!y) return 0;
	x--,y--; p1=p2=0;
	memset(X,0,sizeof(X));
	memset(Y,0,sizeof(Y));
	while (x) X[++p1]=x%2,x/=2;
	while (y) Y[++p2]=y%2,y/=2;
	// x,y,k
	
	int t=max(p1,p2,p3);
	rep(j,0,2) rep(k,0,2) rep(t,0,2) f[0][j][k][t]=node(1,0);
	rep(p,1,t+1) rep(l1,0,2) rep(l2,0,2) rep(l3,0,2) {
		int up1=l1?X[p]:1,up2=l2?Y[p]:1,up3=l3?K[p]:1;
		node res;
		rep(i,0,up1+1) rep(j,0,up2+1) {
			if ((i^j)>up3) continue;
			node e=f[p-1][l1&&i==up1][l2&&j==up2][l3&&(i^j)==up3];
			add(res.cnt,e.cnt);
			add(res.val,e.val);
			if (i^j) add(res.val,1ll*(1<<(p-1))*e.cnt%mo);
		}
		f[p][l1][l2][l3]=res;
	};
	node ans=f[t][1][1][1];
	return (ans.cnt+ans.val)%mo;
}

int main() {
	cin>>q;
	while (q--) {
		int x1,y1,x2,y2,k;
		cin>>x1>>y1>>x2>>y2>>k;
		memset(K,0,sizeof(K));
		p3=0,k--;
		while (k) K[++p3]=k%2,k/=2;
		// rep(i,1,p3+1) printf("%d",K[i]);puts("");
		
		int tmp=0;
		add(tmp,+solve(x2,y2));
		// debug(tmp);
		add(tmp,-solve(x2,y1-1));
		add(tmp,-solve(x1-1,y2));
		add(tmp,+solve(x1-1,y1-1));
	
		printf("%d\n",(tmp+mo)%mo);	
	}
	return 0;	
}
/*

1
3 2 5 4 4


*/