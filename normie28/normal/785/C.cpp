#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;
     int64_t n,m,res,bot,top,mid,i;
lint dp[100005];
const long double spd=10;
 
int64_t calc (int64_t x){
return ((x+1)*x/2)-1;
}
int main(){
	cin >> n>>m;
	if (m>=n) {cout<<n; return 0;}
	res=m+1;
	n-=m+1;
	if (n<=0) {cout<<res; return 0;}
	bot=1;
	top=2000000000;
	while (bot!=top)
{
//	cout<<mid<<endl;
	mid=(bot+top)/2;
	if ((calc(mid)>=n)and(calc(mid-1)<n)) break; 
	else if ((calc(mid)>=n)and(calc(mid-1)>=n)) top=mid;
	else bot=mid;
}
//	for (i=1;i<=mid;i++) cout<<calc(i)<<endl;
	cout<<res+mid-1;
}
//s=4,9*t^2 cout<<fixed<<setprecision(3)<<