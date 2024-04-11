#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
#define ass(n,l,r) assert(n>=l and n<=r)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}


char ch[1001];
int a[1002][1002];

const double bc = log2((double)3);
vi operator-(const vi&x, const vi&y){
	vi ans(4);
	FOR(i,0,3)ans[i]=x[i]-y[i];
	return ans;
}
vi operator+(const vi&x, const vi&y){
	vi ans(4);
	FOR(i,0,3)ans[i]=x[i]+y[i];
	return ans;
}
bool operator>(const vi&x, const vi&y){
	if(x[0])return 0;
	return y[0] or ((x[2]-y[2])>(y[3]-x[3])*bc);
}
struct dis_set
{
	vi p,r,mn,mx;
	dis_set(int n){p.rz(n);r.rz(n);mn.rz(n);mx.rz(n);FOR(i,0,n-1)p[i]=mn[i]=mx[i]=i;}

	int get(int i)
	{
		if(p[i]!=i)p[i]=get(p[i]);
		return p[i];
	}
	int connect(int i, int j)
	{
		int x=get(i),y=get(j);
		if(x==y) return 0;
		if(r[x]<r[y])p[x]=y,mn[y]=min(mn[y],mn[x]),mx[y]=max(mx[y],mx[x]);
		else {p[y]=x;if(r[x]==r[y])++r[x];mn[x]=min(mn[y],mn[x]),mx[x]=max(mx[y],mx[x]);}
		return 1;
	}
};
vi pr[1002][1002];
vi pc[1002][1002];
vi pad[3002][1002];
vi pmd[3002][1002];
#define min(a,b,c,d) min(min(a,b),min(c,d))
int main()
{
  // boost;
  int n;scanf("%d",&n);
  for(int i=1;i<=n;++i){scanf("%s",ch);FOR(j,1,n)a[i][j]=ch[j-1]-'0';}
  FOR(i,0,n+1)FOR(j,0,n+1)
	pr[i][j].rz(4),pc[i][j].rz(4);
  FOR(i,0,2*n)FOR(j,0,n+1)
	pad[i][j].rz(4),pmd[i][j].rz(4);
  FOR(i,1,n){
  	FOR(j,1,n){
  		pr[i][j]=pr[i][j-1];
  		pr[i][j][a[i][j]]++;
  		
  		pc[i][j]=pc[i][j-1];
  		pc[i][j][a[j][i]]++;

  		pad[i-j+n][i]=pad[i-j+n][i-1];
  		pad[i-j+n][i][a[i][j]]++;

  	}
  }
  // FOR(i,1,n){
  // 	FOR(j,1,n){
  // 		cout<<pr[i][j][2];
  // 	}
  // 	cout<<endl;
  // }
  // FOR(i,1,n){
  // 	FOR(j,1,n){
  // 		cout<<pc[i][j][2];
  // 	}
  // 	cout<<endl;
  // }
  FOR(k,2,n+n)
  	FOR(i,1,n){
  	pmd[k][i]=pmd[k][i-1];
  	pmd[k][i][a[i][k-i]]++;
  }
  FOR(k,1,2*n-1)
  	FOR(i,1,n){
  	pad[k][i]=pad[k][i-1];
  	pad[k][i][a[i][i-k+n]]++;
  }
  vector<dis_set> r(n+1,n+1),c(n+1,n+1),md(2*n+10,n+1),ad(2*n+10,n+1);
  FOR(i,1,n)FOR(j,2,n)
  if(a[i][j]!=0 and a[i][j-1]!=0)r[i].connect(j,j-1);
  FOR(i,2,n)FOR(j,1,n)
  if(a[i][j]!=0 and a[i-1][j]!=0)c[j].connect(i,i-1);
  FOR(i,1,n-1)FOR(j,2,n)
  if(a[i][j]!=0 and a[i+1][j-1]!=0)md[i+j].connect(i,i+1);
  FOR(i,1,n-1)FOR(j,1,n-1)
  if(a[i][j]!=0 and a[i+1][j+1]!=0)ad[i-j+n].connect(i,i+1);
  vi ans(4);
  ans[0]=1;
  FOR(i,1,n){
  	FOR(j,1,n){
  		if(a[i][j]==0){continue;}
  		int RL = r[i].mn[r[i].get(j)];
  		int RR = r[i].mx[r[i].get(j)];
  		int CL = c[j].mn[c[j].get(i)];
  		int CR = c[j].mx[c[j].get(i)];
  		int x = min(j-RL+1,RR-j+1,i-CL+1,CR-i+1);
  		vi now = pr[i][j+x-1] - pr[i][j-x];
  		now = now + pc[j][i+x-1] - pc[j][i-x];
  		now[a[i][j]]--;
  		
  		if(now>ans)ans=now;
  		

  		int MDL = md[i+j].mn[md[i+j].get(i)];
  		int MDR = md[i+j].mx[md[i+j].get(i)];
  		int ADL = ad[i-j+n].mn[ad[i-j+n].get(i)];
  		int ADR = ad[i-j+n].mx[ad[i-j+n].get(i)];
  		x = min(i-MDL+1,MDR-i+1,i-ADL+1,ADR-i+1);
  		now = pmd[i+j][i+x-1] - pmd[i+j][i-x];
  		
  		now = now + pad[i-j+n][i+x-1] - pad[i-j+n][i-x];
  		now[a[i][j]]--;
  		
  		if(now>ans)ans=now;
  		
  	}
  	
  }
  
  int yo=ans[1]>0 or ans[2]>0 or ans[3]>0;
  
  FOR(i,0,3)
  while(ans[i]--)
  	yo=mul(yo,i);

  printf("%d",yo);
  return 0;
}