#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double db;
// head 

const int N=1e5+5;

int n;
bool ans[N];
pii A[N],B[N];
int a[N],b[N];
int sumA[N],sumB[N],sufA[N];
struct node {
	int a,b,id;	
}c[N];

bool cmp1(pii a,pii b) {return a.fi<b.fi||(a.fi==b.fi&&a.se<b.se);}
bool cmp2(pii a,pii b) {return a.se<b.se||(a.se==b.se&&a.fi<b.fi);}
bool cmpc(node a,node b) {return a.a<b.a;}

int main() {
	int _;
	for (cin>>_;_;_--) {
		cin>>n;
		int maxA=0,maxB=0;
		rep(i,1,n+1) scanf("%d",&a[i]),maxA=max(maxA,a[i]);
		rep(i,1,n+1) scanf("%d",&b[i]),maxB=max(maxB,b[i]);
		rep(i,1,n+1) A[i]=B[i]=mp(a[i],b[i]),c[i]=(node) {a[i],b[i],i};
		
		sort(A+1,A+1+n,cmp1),sort(B+1,B+1+n,cmp2);
		rep(i,1,n+1) sumA[i]=max(A[i].se,sumA[i-1]);//sort with A
		sufA[n+1]=0;
		per(i,n+1,1) sufA[i]=max(A[i].se,sufA[i+1]);
		rep(i,1,n+1) sumB[i]=max(B[i].fi,sumB[i-1]);//sort with B
		
		sort(c+1,c+1+n,cmpc);
		
		int beatA=0,beatB=0;
		rep(i,1,n+1) {
			node e=c[i];
			beatA=max(beatA,e.a),beatB=max(beatB,e.b);

			while (true) {
				int pba=lower_bound(A+1,A+1+n,mp(beatA,0),cmp1)-A;
				int pbb=lower_bound(B+1,B+1+n,mp(0,beatB),cmp2)-B;
				int newB=sumA[pba],newA=sumB[pbb];
				if (newA==beatA&&newB==beatB) break;
				beatA=newA,beatB=newB;
			}
			if (beatA==maxA&&beatB==maxB) ans[e.id]=1;
			else ans[e.id]=0;
		}
		rep(i,1,n+1) printf("%c",ans[i]?'1':'0');
		puts("");
	}
	return 0;	
}