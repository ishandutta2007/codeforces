#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;char s[10];
 
bool check(ll l,ll r)
{
  printf("%I64d %I64d\n",l,r);
  fflush(stdout);
  scanf("%s",s);
  return s[0]=='Y';
}
 
int main()
{
  ll l,r,mid,len,x;srand(time(0));
  scanf("%I64d%I64d",&n,&k);
  l=1;r=n;
  while(1)
  {
  	l=max(1LL,l-k);r=min(n,r+k);
    if(r-l+1<=4*k+1)
	{
	  len=r-l+1;x=l+rand()%len;
	  if(check(x,x))return 0;
	}
	else
	{
      mid=l+r>>1;
      if(check(l,mid))r=mid;
      else l=mid+1;
    }
  }
}