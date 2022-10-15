#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#define WT '.'
#define LA '*'
using namespace std;
struct lk {int64_t ox; int64_t oy; int64_t size;};
struct sq {int64_t x; int64_t y;};
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,e,f,x,y,z,fail, last,po=0, count0=0,count1=0,izlake,page,removed=0,temp,op=0,used[52][52]; char map[52][52]; 
	long double r,xx,yy,dist,aa,bb,cc,dd;
	vector <sq> patches[51][51]; vector <lk> lakes; lk h; sq hl;

int operator<(lk a, lk b) {return a.size>b.size;}
int main()
{ 	cin>>n;
	for (i=1;i<=n;i++) {cin>>x; if (x%2) count1++; else count0++;}
	if (count1<count0) cout<<count1; else cout<<count0;
}