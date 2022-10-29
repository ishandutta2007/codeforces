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

const int N=4005;
const int T=20005;

int n,p,q,ans[T];

int que[N],l=1,r=0;
struct goods {
	int t,w,v;
}g[N];
bool cmp(goods a,goods b) {
	return a.t<b.t;	
}

struct ques {
	int id,mon;
};
vector<ques> Q[T];

//1 2
int stk1[N],top1,dp1[N][N];
int stk2[N],top2,dp2[N][N];
void add1(int x) {
	stk1[++top1]=x;
	per(i,4000+1,0) {
		dp1[top1][i]=dp1[top1-1][i];
		if (i>=g[x].w) chkmax(dp1[top1][i],dp1[top1-1][i-g[x].w]+g[x].v);
	}
}
void add2(int x) {
	stk2[++top2]=x;
	per(i,4000+1,0) {
		dp2[top2][i]=dp2[top2-1][i];
		if (i>=g[x].w) chkmax(dp2[top2][i],dp2[top2-1][i-g[x].w]+g[x].v);
	}
}
void del() {
	l++;
	if (!top1) {
		while (top2) add1(stk2[top2--]);
	}
	top1--;
}


int main() {
	scanf("%d%d",&n,&p);
	rep(i,1,n+1) {
		int c,h,t;
		scanf("%d%d%d",&c,&h,&t);
		g[i]=(goods) {t,c,h};
	}
	sort(g+1,g+1+n,cmp);
	scanf("%d",&q);
	int tmx=0;
	rep(i,1,q+1) {
		int a,b;
		scanf("%d%d",&a,&b);
		Q[a].pb((ques) {i,b});
		tmx=max(tmx,a);
	}
	
	rep(k,1,tmx+1) {
		while (r+1<=n&&g[r+1].t<=k) add2(++r);
		while (l<=r&&g[l].t+p-1<k) del();
		
		// bug(k),bug(l),debug(r);
		
		rep(i,0,SZ(Q[k])) {
			ques e=Q[k][i];
			
			rep(j,0,e.mon+1) ans[e.id]=max(ans[e.id],dp1[top1][j]+dp2[top2][e.mon-j]);
		}	
	}
	rep(i,1,q+1) printf("%d\n",ans[i]);
	return 0;
}