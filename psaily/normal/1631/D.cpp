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

const int N=2e5+5;
int T;
int n,k,rur;
int a[N];
int cnt[N];

struct tup {
	int x,y;
	bool operator < (const tup&_)const {
		return y-x<_.y-_.x;
	}		
};
int main() {
	cin>>T;
	while(T--) {
		cin>>n>>k;
		rur=(n+k+1)/2;
		int lim=0,mx=0,cur=0;
		
		rep(i,1,n+1) scanf("%d",&a[i]),cnt[a[i]]++,lim=max(lim,a[i]);
		
		tup ans=(tup) {0,inf};
		rep(mn,0,lim+1) {
			while (cur<rur&&mx+1<=lim) cur+=cnt[++mx];
			if (cur>=rur) ans=min(ans,(tup) {mn,mx});
			cur-=cnt[mn];
		}
		
		int gop=1,sum=0,lst=1;
		
		printf("%d %d\n",ans.x,ans.y);
		rep(i,1,n+1) {
			if (a[i]>=ans.x&&a[i]<=ans.y) sum++;
			else sum--;
			if (gop<k) {
				if (sum>0) printf("%d %d\n",lst,i),gop++,lst=i+1,sum=0;
			}else {printf("%d %d\n",lst,n); break;}
		}
		
		rep(i,1,n+1) cnt[a[i]]=0;
		// puts("------");
	}
	return 0;	
}