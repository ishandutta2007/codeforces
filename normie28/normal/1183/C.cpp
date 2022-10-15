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
	for (k=1;k<=t;k++) { cin>>count>>n>>hi>>lo;
	count-=(n*lo);
	if (count<=0) cout<<-1<<endl; else {err=((count-1)/(hi-lo)); if (err>n) cout<<n<<endl; else cout<<err<<endl;}
}
}