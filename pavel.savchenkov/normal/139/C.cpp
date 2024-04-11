//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#define pb push_back
#define eps 1e-9
#define inf 2000000000
using namespace std;
int n,k;
string q[4];
bool can[4];

bool okey(char  c)
{
	//return true;
	if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
	return false;
}

bool ok(string a,string b) {
	if ((int)a.length()<k||(int)b.length()<k) return false;
	int aa=a.length(); int bb=b.length();
    int an=-1,ans1=0; int bn=-1,ans2=0;
	for (int i=aa-1;i>=0;i--)
		{ if (okey(a[i])) ans1++; if (ans1==k) {an=i;break;} }
	if (an==-1) return false;
	for (int i=bb-1;i>=0;i--)
		{ if (okey(b[i])) ans2++; if (ans2==k) {bn=i;break;} }
	if (bn==-1) return false;
	
	if (a.substr(an,aa-an)==b.substr(bn,bb-bn)) return true;
	return false;
}

void go(string g[4]) 
{
	if ( !(ok(g[0],g[1])&&ok(g[2],g[3])) ) can[0]=false;
	if ( ! ( ok(g[0],g[2])&&ok(g[1],g[3]) )  ) can[1]=false;
	if (! (ok(g[0],g[3])&&ok(g[1],g[2]))  ) can[2]=false;

	for (int i=0;i<4;i++)
		for (int j=i+1;j<4;j++)
          if (!ok(g[i],g[j])) {can[3]=false;return;}
					
}


int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   q[0]="aabb"; q[1]="abab"; q[2]="abba"; q[3]="aaaa";
   for (int i=0;i<=3;i++) can[i]=true;
   
   scanf("%d%d\n",&n,&k);
   for (int i=1;i<=n;i++)
   {
	   
	   string g[4]; char c='+';
	   for (int j=0;j<4;j++)
	   {
		   g[j]="";c='+';
	       while (scanf("%c",&c)==1) if (c!='\n') g[j]+=c; else break;
           //cout<<g[j]<<endl;		   
	   }
	   go(g);
   }
    
    for (int i=3;i>=0;i--)
	   if (can[i]) {cout<<q[i];return 0;}
	cout<<"NO";
   return 0;
}