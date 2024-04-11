#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
	long long n,m,i,j,k,minn,maxx,counta=0,countb=0,a[100001],b[100001],page,removed=0,temp; long double aa;
 
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) {cin>>aa; if (aa>=0) {a[i]=floor(aa);  b[i]=ceil(aa);counta+=min(a[i],b[i]);} else {a[i]=ceil(aa);  b[i]=floor(aa);counta+=min(a[i],b[i]);}}
	i=1;
	while (i<=n) {if ((a[i]!=b[i])and(counta<0)) {cout<<max(a[i],b[i]);counta++;} else cout<<min(a[i],b[i]); cout<<endl; i++;}
	
}