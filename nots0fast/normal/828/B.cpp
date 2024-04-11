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
#define MAX 100001
int inf = pow(10,9);
double eps = pow(10,-18);
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main(){
   int minx = inf ,miny =inf, maxx = -inf,maxy=-inf;
   int n,m;
   cin>>n>>m;
   char arr[n][m];
   fori(n)
   	forj(m){
   		cin>>arr[i][j];
   		if(arr[i][j]=='B'){
   			minx = min(minx,i);
   			maxx = max(maxx,i);
   			maxy = max(maxy,j);
   			miny = min(miny,j);
   		}
   	}
   	if(minx == inf)
   		cout<<1;
   	else{
   		int ferq1 = maxx-minx;
   		int ferq2 = maxy-miny;
   		int ferq = ferq1 - ferq2;
   			int minsay = inf;
   		if(ferq1>ferq2){
   			maxy+=ferq;
   			fori(ferq+1){
   				if(maxy<m && miny>-1){
   					int say = 0;
   					for(int i=minx; i<=maxx; i++)
   						for(int j=miny; j<=maxy; j++)
   							if(arr[i][j]=='W')
   								++say;
   					minsay = min(say,minsay);
				}
				--maxy, --miny;
			}
   		}
   		else{
   			ferq = -ferq;
   			maxx+=ferq;
   			fori(ferq+1){
   				if(maxx<n && minx>-1){
   					int say = 0;
   					for(int i=minx; i<=maxx; i++)
   						for(int j=miny; j<=maxy; j++)
   							if(arr[i][j]=='W')
   								++say;
   					minsay = min(say,minsay);
				}
				--maxx, --minx;
			}
   		}
   		if(minsay==inf)
   			cout<<-1;
   		else
   			cout<<minsay;
	}
}