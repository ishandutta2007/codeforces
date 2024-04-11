#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

struct point{
	int x,y;
};

struct seg{
	point f,s;
};

bool operator==(point a,point b){
	return a.x==b.x && a.y==b.y;
}

bool betwin(int l,int v,int r){
	return v>=min(l,r) && v<=max(l,r);
}

bool point_on_seg(seg s,point A){
	int64 a=s.s.y-s.f.y;
	int64 b=s.f.x-s.s.x;
	int64 c=-s.f.x*a-s.f.y*b;
	int64 val=a*A.x+b*A.y+c;
	if (val!=0)
		return false;
	if (!betwin(s.f.x,A.x,s.s.x))
		return false;
	if (!betwin(s.f.y,A.y,s.s.y))
		return false;
	return true;
}

ld dest(point a,point b){
	return sqrt((ld)((a.x-b.x)*1ll*(a.x-b.x)+(a.y-b.y)*1ll*(a.y-b.y)));
}

bool check(seg a,seg b,seg c){
	if (a.f==b.f){}		
	else if (a.s==b.f)	
		swap(a.s,a.f);
	else if (b.s==a.f)
		swap(b.s,b.f);
	else if (a.s==b.s){
					swap(a.s,a.f);
					swap(b.s,b.f);
				}
	else 
		return false;
	point v1,v2;
	v1.x=a.s.x-a.f.x;
	v1.y=a.s.y-a.f.y;
	v2.x=b.s.x-b.f.x;
	v2.y=b.s.y-b.f.y;
	int64 scal=v1.x*1ll*v2.x+v1.y*1ll*v2.y;
	int64 vec=v1.x*1ll*v2.y-v1.y*1ll*v2.x;
	if (!(scal>=0 && vec>0))
		return false;
	if (!point_on_seg(a,c.f))
		swap(c.f,c.s);
	if (!point_on_seg(a,c.f))
		return false;
	if (!point_on_seg(b,c.s))	
		return false;
	ld l1,l2;
	l1=dest(c.f,a.f);
	l2=dest(c.f,a.s);
	if (l1<l2)
		swap(l1,l2);
	if (4-l1/l2<-(1E-09))
		return false;
		
		
	l1=dest(c.s,b.f);
	l2=dest(c.s,b.s);
	if (l1<l2)
		swap(l1,l2);
	if (4-l1/l2<-(1E-09))
		return false;
	return true;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  for (int i=0;i<t;i++){
  	seg a,b,c;
  	cin>>a.f.x>>a.f.y>>a.s.x>>a.s.y;
  	cin>>b.f.x>>b.f.y>>b.s.x>>b.s.y;
  	cin>>c.f.x>>c.f.y>>c.s.x>>c.s.y;
  	bool q=false;
  	q|=check(a,b,c);
  	q|=check(a,c,b);
  	q|=check(b,a,c);
  	q|=check(b,c,a);
  	q|=check(c,a,b);
  	q|=check(c,b,a);
  	if (q)
  		printf("YES\n");
  	else
  		printf("NO\n");
  }
  return 0;
}