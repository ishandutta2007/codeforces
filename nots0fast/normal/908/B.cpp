#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define double long double
#define MAX 26
#define N 100000
// #define cout out
// #define cin in
lli inf = pow(10,9);
lli modulo = inf+ 7;
double eps = 1e-10;
ifstream in;
ofstream out;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main(){
	int n,m;
	cin>>n>>m;
	int s1,s2;
	char arr[n][m];
	fori(n)
		forj(m){
			cin>>arr[i][j];
			if(arr[i][j]=='S')
				s1 = i, s2 = j;
		}
	string a;
	cin>>a;
	int dir[4];
	int sy = 0;
	fori(4)
		dir[i] = i;
	do{
		int x = s1, y = s2;
		bool ye = 0;
		fori(a.length()){
			x+=dx[dir[a[i]-'0']], y+=dy[dir[a[i]-'0']];
			if(x<0 || y<0 || x>n-1 || y>m-1 || arr[x][y]=='#')
				break;
			if(arr[x][y]=='E'){
				ye = 1;
				break;
			}
		}
		sy+=ye;
	}while(next_permutation(dir,dir+4));
	cout<<sy;
}