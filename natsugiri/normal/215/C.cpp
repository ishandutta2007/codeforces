#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;
LL n, m, s;

int main(){

  //scanf("%d%d%d", &n, &m, &s);
  cin>>n>>m>>s;
  if (s%2==0) { puts("0"); return 0; }
  LL ans=0;
  for (LL i=1; i<=s; i+=2) {
    if (s%i==0) {
      if (i<=m && s/i<=n) {
	ans+=((i/2+1)*(s/i/2+1)*2-1)*(m-i+1)*(n-s/i+1);
      }
    }
  }
  for (LL a=1; a<=n; a+=2) {
    for (LL b=1; b<=m; b+=2) {
      for (LL d=1; d<b; d+=2) {
	if ((s-a*(b-d))%d==0) {
	  LL c=(s-a*(b-d))/d;
	  if (c>a && c<=n) {
	    ans+=(n-c+1)*(m-b+1)*2;
	  }
	}
      }
    }
  }
  
  cout<<ans<<endl;
  return 0;
}