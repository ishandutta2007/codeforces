#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
	long double n,m,i,j,k,x,y,countt=0,counts=0,minn,maxx, found,fr,bk; long double nn,mm;
 
int main()
{
	cin>>n>>m>>k;
	nn=n/k;
	mm=m/k;
	cout<<fixed<<setprecision(0)<<ceil(nn)*ceil(mm);
}