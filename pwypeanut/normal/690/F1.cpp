#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
int n,a,b;
int d[10005];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		scanf("%d%d",&a,&b);
		d[a-1]++;
		d[b-1]++;
	}
	int ans=0;
	for (int i=0;i<n;i++) {
		ans+=(d[i]*(d[i]-1))/2;
	}
	printf("%d\n", ans);
}