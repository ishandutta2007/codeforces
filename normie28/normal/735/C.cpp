#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#define ll long long
using namespace std;
 
	int64_t n,m,i,j,cycles,needed,hol,remain,k,e,ee,minn,maxx, si,sj, countt=0,counts=0,page,removed=0,temp,op=0,f[200001],og[200001],used[200001]; 
vector <int64_t> edge[200001],vqueue,finl,samp;  
int main()
{
	cin>>n;
	f[0]=2;
	f[1]=3;
	i=0;
	while (f[i]<=n) {i++; if (i>1) f[i]=f[i-1]+f[i-2]; }
	cout<<i;
}