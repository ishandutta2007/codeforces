#include<bits\stdc++.h>
using namespace std;
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
const int Maxn=1005;
int l[Maxn],r[Maxn];
int ans[Maxn];
void solve(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d %d",&l[i],&r[i]);
	}
	int nt=0;
	for (int i=1;i<=n;i++){
		nt=max(nt,l[i]);
		if (nt>r[i]){
			ans[i]=0;
			continue;
		}
		ans[i]=nt;
		nt++;
	}
	for (int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		solve();
	}
	return 0;
}