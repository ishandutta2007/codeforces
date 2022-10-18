#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n=0;
	cin>>n;
   int p[n+1]; int max=0;
   for (int i=1;i<=n;i++)
    cin>>p[i];

   for (int i=1;i<=n;i++)
   {   int v=p[i]; int e=1;
	   while (v!=-1) {
	    e++;
	    v=p[v];
	   }
	   if (e>max) max=e;
   }
   cout<<max;
   return 0;
}