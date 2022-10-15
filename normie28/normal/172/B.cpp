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
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,e,f,x,y,z,fail, last,po=0, countl=0,izlake,page,removed=0,temp,op=0,used[52][52]; char map[52][52]; 
	long double r,xx,yy,dist,aa,bb,cc,dd;
	vector <sq> patches[51][51]; vector <lk> lakes; lk h; sq hl;
void process()
{
	x=(a*x+b)%m;
	y=(a*y+b)%m;
	y=(a*y+b)%m;
}
void process2()
{
	y=(a*y+b)%m;
	countl++;
}
int operator<(lk a, lk b) {return a.size>b.size;}
int main()
{ 	cin>>a>>b>>m>>n;
	x=n;y=n;
	process();
	while (x!=y) process();
	process2();
	while (x!=y) process2();
	cout<<countl;
}