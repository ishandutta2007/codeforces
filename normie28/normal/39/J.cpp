#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
 
using namespace std;
	int64_t n,m,i,j,jj,k,s,e,minn,maxx,countt=0,counts=0,page,flag,removed=0,temp,op=0;vector <int64_t> a; string s1,s2; char c;
int cmp(int64_t a,int64_t b) {return a>b;}
int main()
{
	cin>>s1>>s2; s2+='/';
	for (i=0;i<s2.length();i++) {if (s1[i]!=s2[i]){c=s1[i]; break;} }
	s1.erase(i,1); s2.erase(s2.length()-1,1); 
	if (s1!=s2) cout<<0; else {countt++; a.push_back(i+1); i--; while (i>=0) if (s1[i]==c) {countt++; a.push_back(i+1); i--;} else break; cout<<countt<<endl; for (j=countt-1;j>=0;j--) cout<<a[j]<<' ';}
}