#include<bits\stdc++.h>

#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
using namespace std;
const int Maxn=205;
void solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> v;
	for (int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		v.pb(x);
	}
	int ans=0;
	for (int i=0;i<k-1;i++){
		int vv=v[i+1]-v[i];
		ans=max(ans,(vv)/2+1);
	} 
	ans=max(ans,v[0]);
	ans=max(ans,n-v[k-1]+1);
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		solve();
	}
	return 0;
}