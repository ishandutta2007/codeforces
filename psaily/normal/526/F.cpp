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

const int N=3e5+5;
int n,a[N];
ll ans;

int lmi[N],lmx[N];
int rmi[N],rmx[N];
int cnt[N*3];
int que[N];

void solve(int L,int R) {
	if (L>=R) return;
	int mid=(L+R)>>1;
	solve(L,mid);
	solve(mid+1,R);
	
	// [L,mid] [mid+1,R]
	int l,r,s,t,mi,mx;
	
	l=mid,r=mid+1;
	lmi[l]=lmx[l]=a[l];
	rmi[r]=rmx[r]=a[r];
	per(i,mid,L) {
		lmi[i]=min(lmi[i+1],a[i]);
		lmx[i]=max(lmx[i+1],a[i]);
	}
	rep(i,mid+2,R+1) {
		rmi[i]=min(rmi[i-1],a[i]);
		rmx[i]=max(rmx[i-1],a[i]);
	}
	// same side
	l=mid;
	rep(i,mid+1,R+1) {
		mi=rmi[i],mx=rmx[i];
		while (l>=L&&lmi[l]>mi&&lmx[l]<mx) cnt[l]++,l--;
		int tmp=i-rmx[i]+rmi[i];
		if (tmp>=0) ans+=cnt[tmp];
	}
	rep(i,L,mid+1) cnt[i]=0;
	
	r=mid+1;
	per(i,mid+1,L) {
		mi=lmi[i],mx=lmx[i];
		while (r<=R&&rmi[r]>mi&&rmx[r]<mx) cnt[r]++,r++;
		int tmp=i+lmx[i]-lmi[i];
		ans+=cnt[tmp];
	}
	rep(i,mid+1,R+1) cnt[i]=0;
	// diff side
	s=1,t=0,l=mid,r=mid+1;
	rep(i,mid+1,R+1) {
		int mi=rmi[i],mx=rmx[i];
		while (l>=L&&lmi[l]>mi) que[++t]=l,cnt[l+lmx[l]]++,l--;
		while (s<=t&&lmx[que[s]]<mx) cnt[que[s]+lmx[que[s]]]--,s++;
		int tmp=i+rmi[i];
		ans+=cnt[tmp];
	}
	rep(i,L,mid+1) cnt[i+lmx[i]]=0;
	
	s=1,t=0,l=mid,r=mid+1;
	rep(i,mid+1,R+1) {
		int mi=rmi[i],mx=rmx[i];
		while (l>=L&&lmx[l]<mx) que[++t]=l,cnt[l-lmi[l]+n]++,l--;
		while (s<=t&&lmi[que[s]]>mi) cnt[que[s]-lmi[que[s]]+n]--,s++;
		int tmp=i-rmx[i]+n;
		ans+=cnt[tmp];
	}
	rep(i,L,mid+1) cnt[i-lmi[i]+n]=0;
}

int main() {
	cin>>n; ans=n;
	rep(i,1,n+1) {
		int r,c;
		scanf("%d%d",&r,&c); a[r]=c;
	}
	// rep(i,1,n+1) printf("%d ",a[i]); puts("");
	solve(1,n);
	printf("%lld\n",ans);
	return 0;	
}