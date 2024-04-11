//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#define pb push_back
const double eps = 1e-9;
const int inf = 2000000000;
using namespace std;

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   string s;
   cin>>s;
   string s2;
   cin>>s2;
   s+=s2;
   string x;
   cin>>x;
   
   if ((int)x.length()!=(int)s.length()) {puts("NO");return 0;}
   int n = (int)x.length();
   for (int i=0;i<n;i++)
	   for (int j=i+1;j<n;j++)
		   if (x[j]<x[i]) swap(x[i],x[j]);
	   
   for (int i=0;i<n;i++)
	for (int j=i+1;j<n;j++)
		if (s[j]<s[i]) swap(s[i],s[j]);
	if (x==s) puts("YES"); else puts("NO");
		

   return 0;
}