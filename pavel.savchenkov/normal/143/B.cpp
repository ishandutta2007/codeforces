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
#define i64 long long
const double eps = 1e-9;
const int inf = 2000000000;
using namespace std;

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   string cel="",drob=""; bool znak = true; bool was = false;
   string w;
   cin>>w; int n = (int)w.length();
   for (int i=0;i<n;i++)
   {
	char c = w[i];
	if (c=='-') { znak = false; continue; }
	if (c=='.') { was = true; continue; }
	if (was) drob+=c; else cel+=c;
   }
   
   if (drob.empty()) drob = "00"; else if ((int)drob.length()==1) drob+='0';
   
   //cout << cel <<" " << drob << endl;
   if (!znak) cout << '(';
   cout << '$';
   if ((int)cel.length()<=3)
   {
	   cout << cel << "." << drob[0] << drob[1];
	   if (!znak) cout << ')'; return 0;
   }
   int s; n = (int)cel.length(); 
   if (n%3==0) s = 2; else if (n%3==1) s = 0; else s = 1;
   
   for (int i=0;i<n;i++)
	   if (i==s+1) { cout << ',' << cel[i]; s+=3; } else cout << cel[i];
   cout << '.' << drob[0] << drob[1];
   if (!znak) cout << ')';
   return 0;
}