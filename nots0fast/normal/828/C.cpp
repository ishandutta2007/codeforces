#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(1)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define lli long long int
#define double long double
#define MAX 2000002
int inf = pow(10,9);
double eps = pow(10,-18);
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
   char qaa[MAX];
   fori(MAX)
   	qaa[i]='a';
   int n;
   cin>>n;
   set<int> ind;
   fori(MAX)
   	ind.insert(i);
   int maxx = 0;
   fori(n){
   	string a;
   	cin>>a;
   	int k;
   	cin>>k;
   	forj(k){
   		int aa;
   		cin>>aa;
   		ind.insert(aa);
   		set<int> :: iterator it1,it = ind.find(aa);
   		while(it!=ind.end() && *it<aa+a.length()){
   			qaa[*it] = a[*it-aa];
   			maxx = max(maxx,*it);
   			it1 = it;
   			++it;
   			ind.erase(it1);
		}
	}
   }
   for(int i=1; i<=maxx; i++)
   	cout<<qaa[i];
}