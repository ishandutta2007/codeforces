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

struct per
{
        string name; int a,x;
};
bool cmp(per x,per y) { return x.a < y.a; };
per p[3010]; int n;

int main() {
   scanf("%d\n",&n);
   for (int i=1;i<=n;i++)
   {
           cin>>p[i].name>>p[i].a; p[i].x = i;
           scanf("\n");
   };
   sort(p+1,p+n+1,cmp);
   if (p[1].a!=0) {puts("-1"); return 0;}
   
   
   bool was[n+1];
   memset(was,false,sizeof(was));
   
   for (int i=n;i>=1;i--)
   {
         int k = 0; int res = -1;
         for (int j=n;j>=1;j--)
         {
                 if (!was[j]) k++;
                 if (k == (p[i].a)+1) { res = j; break;}
         }
         if (res == -1) {puts("-1");return 0;}
         p[i].x = res; was[res] = true;
   }
   
   for (int i=1;i<=n;i++)
           cout << p[i].name << " " << p[i].x << endl;
   

   return 0;
}