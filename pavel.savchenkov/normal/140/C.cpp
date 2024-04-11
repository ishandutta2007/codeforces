#pragma comment (linker, "/STACK:200000000") 
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
const double eps = 1e-9;
const int inf = 2000000000;
using namespace std;

struct p
{
	int ind,k;
	p(int a,int b) {ind = a; k = b;}
	friend bool operator <(const p &a,const p &b)
	{
		return b.k <= a.k;
	};
};

vector <p> dd;

bool cmp(p a,p b)
{
	return a.ind > b.ind;
};

set < p > s; 
set < p > :: iterator it;
vector < int > res[3];

int main() {
  // freopen("input.txt","r",stdin);
   int n; cin >> n; 
   int a[100010];
   for (int i=1;i<=n;i++) scanf("%d",&a[i]);
   
   sort(a+1,a+n+1);
   int kol = 1;
   for (int i=2;i<=n;i++)
	   if (a[i]!=a[i-1]) { s.insert(p(a[i-1],kol));  kol = 1; } else kol++;
   s.insert(p(a[n],kol));
	
   while ((int)s.size()>=3)
   {
	   vector < p > q; 
	   it = s.begin(); q.pb(*it); s.erase(it);
	   it = s.begin(); q.pb(*it); s.erase(it);
	   it = s.begin(); q.pb(*it); s.erase(it);
	   sort(q.begin(),q.end(),cmp);
	   for (int i=0;i<=2;i++)
	   {
			res[i].pb(q[i].ind);
			q[i].k--;
			if (q[i].k > 0) s.insert(q[i]);
	   };
   };
   
   
   n = (int)res[0].size();
   cout << n << endl;
   for (int i=0;i<n;i++)
	   printf("%d %d %d\n",res[0][i],res[1][i],res[2][i]);

   return 0;
}