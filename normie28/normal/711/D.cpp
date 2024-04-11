#include <bits/stdc++.h>
 
using namespace std;
 
#define x first
#define y second
 
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
 
typedef pair<int, int> pii;
typedef long long INT;
 
template <class T> inline void smin(T &a, T b) {if (a>b) a=b;}
template <class T> inline void smax(T &a, T b) {if (a<b) a=b;}
 
#define mod 1000000007
#define NN 211111
int to[NN], cnt[NN], dst[NN];
int qf, qb, q[NN], vst[NN];
 
INT calc_p(int n) {
	if (n==0) return 1;
	INT mid=calc_p(n/2);
	mid*=mid; mid%=mod;
	if (n%2) mid=mid*2%mod;
	return mid;	
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, nn, u, v;
	
	cin>>N;
	for (i=0; i<N; i++) cin>>to[i];
	for (i=0; i<N; i++) to[i]--;
	
	memset(vst, -1, sizeof(vst));
	int flag=0, liko=0;
 
	nn=0;
	
	for (i=0; i<N; i++) {
		if (vst[i]!=-1) continue;
		flag++;
		qf=qb=0;
		q[qb++]=i; vst[i]=flag; dst[i]=0;
 
		int mx=0;
 
		while (qf<qb) {
			u=q[qf++];
			v=to[u];
			
			if (vst[v]==flag) {
				mx=max(dst[u]+1-dst[v], mx);
			}
			
			if (vst[v]!=-1) continue;
 
			dst[v]=dst[u]+1;
			vst[v]=flag; q[qb++]=v;
		}
		
		liko+=qb-mx;
		if (mx) cnt[nn++]=mx;
	}
 
	INT res=calc_p(liko);
	for (i=0; i<nn; i++) {
		res*=(calc_p(cnt[i])-2); res%=mod;
	}
	if (res<0) res+=mod;
	
	cout<<res;
}