//Author: ACChampionEric
//Verdict: Accepted

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <limits>
#include <stack>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <numeric>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,m,n) for(int i=m;i<=n;i++)
#define all(i,j) for(i::iterator it=j.begin;it!=j.end;it++)
using namespace std;
typedef long long ll;
ll n,k,d1,d2,t,a,b,c;
void solve()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
	if(n%3){printf("no\n");return;}
	t=n/3;
	bool ok=false;
	if((d1*2+d2+k)%3==0)
	{
		a=(k+d1*2+d2)/3;
		b=a-d1;
		c=b-d2;
		if(a<=t&&b<=t&&c<=t&&a>=0&&b>=0&&c>=0){
			printf("yes\n");
			return ;
		}
	}
	if((k-d1-d2)%3==0)
	{
		b=(k-d1-d2)/3;
		a=b+d1;
		c=b+d2;
		if(a<=t&&b<=t&&c<=t&&a>=0&&b>=0&&c>=0){
			printf("yes\n");
			return ;
		}
	}
	if((k+d1+d2)%3==0)
	{
		b=(k+d1+d2)/3;
		a=b-d1;
		c=b-d2;
		if(a<=t&&b<=t&&c<=t&&a>=0&&b>=0&&c>=0){
			printf("yes\n");
			return ;
		}
	}
	if((k+d2*2+d1)%3==0)
	{
		c=(k+d2*2+d1)/3;
		b=c-d2;
		a=b-d1;
		if(a<=t&&b<=t&&c<=t&&a>=0&&b>=0&&c>=0){
			printf("yes\n");
			return ;
		}
	}
	printf("no\n");
}
int main(){
	int q;
	scanf("%d",&q);
	while(q--)
		solve();
	return 0;
}