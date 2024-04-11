#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t val; int64_t pos;};
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,x,y,fail, last,po=0,countb=0,countc=0,page,removed=0,temp,op=0,fina[500001],used[500001]; 
	long double r,xx,yy,dist,aa,bb,cc,dd;
vector <int64_t> bui(int64_t x)
{
	vector <int64_t> ii,jj; 
	if (x>=2) {ii=bui(x/2); jj=ii; ii.push_back(x%2); ii.insert(ii.end(),jj.begin(),jj.end());} else {ii.push_back(x);}
	return ii;
}



int main()
{ 
	cin>>i; for (j=1;j<=i;j++) {
	cin>>a>>b>>c>>x>>y;
	d=a/2;
	if (d==0) cout<<0;
	else if (x>y) { countb=(d>b)?b:d;
	d-=countb; if (d<0) d=0;
	countc=(d>c)?c:d;
	cout<<countb*x+countc*y;
} else {countc=(d>c)?c:d;
	d-=countc; if (d<0) d=0;
	countb=(d>b)?b:d;
	cout<<countb*x+countc*y;

}
	cout<<endl;
}
}