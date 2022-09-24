#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
string s[111];
int a[110][20010];
const int INF=0x3f3f3f3f;

int main(){
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; i++) cin>>s[i];
  for (int i=0; i<n; i++) s[i]+=s[i];
  memset(a, 0x3f, sizeof a);

  for (int i=0; i<n; i++) {
	int p=-1;
	for (int j=0; j<m*2; j++) {
	  if (s[i][j]=='1') p=j;
	  if (p>=0) a[i][j]=j-p;
	}
	p=-1;
	for (int j=m*2-1; j>=0; j--) {
	  if (s[i][j]=='1') p=j;
	  if (p>=0) a[i][j]=min(a[i][j], p-j);
	}
  }
  int ans=INF;
  for (int j=0; j<2*m; j++) {
	int cnt=0;
	for (int i=0; i<n; i++) {
	  if (a[i][j]>m) { cnt=INF; break; }
	  cnt+=a[i][j];
	}
	ans=min(ans, cnt);
  }
  
	
  if (ans==INF) puts("-1");
  else printf("%d\n", ans);
  return 0;
}