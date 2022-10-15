#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;
int64_t i,cur,minh,t,n,m,k,count,err=0,minn,maxx,lo,hi; string s="";

int main()
{ 
	cin>>t;
	for (k=1;k<=t;k++) { cin>>n>>m; minn=100000001; maxx=0;
	for (i=1;i<=n;i++) {cin>>cur; if (cur<minn) minn=cur; if (cur>maxx) maxx=cur;}
	lo=maxx-m; hi=minn+m; if (hi>=lo) cout<<hi<<endl; else cout<<-1<<endl;
}
}