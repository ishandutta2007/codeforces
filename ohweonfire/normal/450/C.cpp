#include <iostream>
#include <cstdio>
#include <cstring> 
#include <algorithm>
using namespace std;
typedef long long int LL;
LL n,m,k,ans=0LL;
int main() {
	cin>>n>>m>>k;
	if(n+m-2<k)
	{ puts("-1"); return 0; }
	if(n+m-2==k) { puts("1"); return 0; }
	LL t; if(m>=k+1) ans=max(ans,n*(m/(k+1)));
 else { t=k-m+1; 
 ans=max(ans,n/(t+1)); }
  if(n>=k+1) ans=max(ans,m*(n/(k+1)));
   else { t=k-n+1; ans=max(ans,m/(t+1)); } cout<<ans<<endl; 
   return 0; 
}