#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
	long long n,m,i,j,k,x,y,ss[1001],tt[1001]; string s,t;
 
int main()
{
	cin>>s>>t;
	for (i=0;i<s.length();i++) if ((s[i]=='a')or(s[i]=='e')or(s[i]=='i')or(s[i]=='o')or(s[i]=='u')) ss[i]=1; else ss[i]=0;
	for (i=0;i<t.length();i++) if ((t[i]=='a')or(t[i]=='e')or(t[i]=='i')or(t[i]=='o')or(t[i]=='u')) tt[i]=1; else tt[i]=0;
	if (s.length()!=t.length()) {cout<<"NO"; return 0;}
	for (i=0; i<s.length();i++) if(ss[i]!=tt[i]) {cout<<"NO"; return 0;}
	cout<<"YES";
}