#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long LL;

int n, m, a[100010], b[100010];
vector<int>v;
int cnt[500][100010];
int l, r, ans;

int main(){
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; i++) {
	scanf("%d", a+i);
	if (a[i]<=n) b[a[i]]++;
  }
  for (int i=1; i<=n; i++) {
	if (b[i]>=i) v.push_back(i);
  }

  for (int i=0; i<(int)v.size(); i++) {
	for (int j=1; j<=n; j++) {
	  cnt[i][j]=cnt[i][j-1]+(v[i]==a[j-1]?1:0);
	}
  }
	

  for (int i=0; i<m; i++) {
	scanf("%d%d", &l, &r);
	ans=0;
	for (int j=0; j<(int)v.size(); j++) {
	  if (v[j]>r-l+1) break;
	  if (cnt[j][r]-cnt[j][l-1]==v[j]) ans++;
	}
	printf("%d\n", ans);
  }

  return 0;
}