//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#define pb push_back
#define i64 long long
const double eps = 1e-9;
const int inf = 2000000000;
const double pi = acos(-1.0);
using namespace std;
int ks[100100][300];
int kp[300];
int k[300];
char s[100100]; char p[100100];
int sn; int pn;

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   memset(ks,0,sizeof(ks)); memset(kp,0,sizeof(kp));
   gets(s); gets(p);
   
   sn = (int)strlen(s); pn = (int)strlen(p);
   if (pn > sn) { cout << "0"; return 0; }
   
   for (int i=0; i<sn; i++)
   {
	   if (i > 0) 
		   for (int j='a'; j<='z'; j++) ks[i][j] = ks[i-1][j];
	   ks[i][(int)s[i]]++;
   }
   for (int i=0; i<pn; i++) kp[(int)p[i]]++;
   
   int res = 0;
   
   for (int i=pn-1; i<sn; i++)
   {
	   memset(k,0,sizeof(k));
	   for (int j='a'; j<='z'; j++)
		   if (i >= pn) k[j] = ks[i][j] - ks[i-pn][j]; else k[j] = ks[i][j];
	   bool ok = true;
	   for (int j='a'; j<='z'; j++)
		   if (k[j] > kp[j]) { ok = false; break; }
	   if (ok) res++;
   }
   
   cout << res;
   return 0;
}