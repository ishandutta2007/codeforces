#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
int n,m;
char a[105][105];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%s",a[i]);
	}
	int ans=0;
	if (a[n-1][0]=='B') ans++;
	for (int i=1;i<m;i++) {
		if (a[n-1][i]=='B' && a[n-1][i-1]=='.') ans++;
	}
	printf("%d\n", ans);
}