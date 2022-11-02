#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n,m;
bool a[777][777];
int b[777][777];
int c[777][777];

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif


	cin>>n>>m;

	//n = 20;
	//m = 50;
	//srand(time(0));
	//n=700;
	//REP(i,n)REP(j,n)if(i!=j)a[i][j]=1;
	REP(i,m){
		int x=0,y=0;
		scanf("%d %d",&x,&y);
		x--,y--;
		/*while(x==y){
			x=rand()%n;
			y=rand()%n;
		}*/

		a[x][y]=a[y][x]=1;
	}
	REP(k,n)REP(i,n)REP(j,n)if(i!=j)if(a[i][k] && a[k][j])b[i][j]++;
	REP(k,n)REP(i,n)REP(j,n)if(i!=j)if(a[i][k] && b[k][j])c[i][j]+=(b[k][j]+(a[i][j]?-1:0));

	ll num = 0;
	REP(i,n)REP(j,n)if(i!=j)REP(k,n)if(k!=i && j!=k)if(a[i][k] && a[k][j]){
		int cc = c[i][j];
		cc -= (b[k][j]+(a[i][j]?-1:0));
		cc -= (b[k][i]+(a[i][j]?-1:0));
		num += cc;
	}
	cout<<num/10<<endl;
	/*ll st = 0;
	REP(i,n)REP(j,n)REP(k,n)REP(l,n)REP(m,n)if(i!=j && i!=k && i!=l && i!=m && j!=k && j!=l && j!=m && k!=l && k!=m && l!=m) if(a[i][j] && a[j][k] && a[k][l] && a[l][m] && a[m][i]) st++;
	cout<<st<<endl;*/
	return 0;
}