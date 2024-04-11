#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(6)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define MAX 220020
#define ld long double
#define vi vector<int>
int inf = pow(10,9);
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
	int n,m;
	cin>>n>>m;
	char arr[n][m];
	int s1 = 0, s2 = 0, s = 0;
	fori(n)
		forj(m){
			cin>>arr[i][j];
			if(arr[i][j] == 'B')
				s1+=i, s2+=j, s++;
		}
	s1/=s, s2/=s;
	cout<<s1+1<<" "<<s2+1;
}
int main() {
	deal();
}