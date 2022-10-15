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
     int64_t n,m,res,bot=0,top=0,mid,i;
lint dp[100005];
const long double spd=10;
 
int64_t calc (int64_t x){
return ((x+1)*x/2)-1;
}
int main(){
	cin >> n>>m;
	if (n==1) {cout<<1<<endl<<0; return 0;} res=0;
	while (n>1)
	{
	i=2;
	while (n%i) {if (i<=sqrt(n)) i++; else {i=n; break;}}
	if (res==0) bot=i;
	if (res==1) top=i;	
	n/=i;
	res++;
//	cout<<i<<' ';
}
	if (res!=2) res=1;
	cout<<res<<endl;if (res==1) cout<<bot*top; 
}