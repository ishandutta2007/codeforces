#include <bits/stdc++.h>
#include <time.h>   
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m,k;
int a[200005],b[200005];
pair<int,int> c[200005];
ll dp[200005][2];
bool ans[200005];



int main() {
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++) {
		scanf("%d",&b[i]);
		c[i].fst=a[i]-b[i];
		c[i].snd=i;
	}
	sort(c,c+n);
	for(int i=0;i<k;i++) {
		ans[c[i].snd]=0;
	}
	for(int i=k;i<n;i++) {
		if(c[i].fst<=0) ans[c[i].snd]=0;
		else ans[c[i].snd]=1;
	}
	ll r=0;
	for(int i=0;i<n;i++) {
		if(ans[i]==0) r+=a[i];
		else r+=b[i];
	}
	printf("%lld\n",r);
	return 0;
}