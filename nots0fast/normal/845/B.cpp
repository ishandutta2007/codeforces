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
int MAX  =  100;
int inf = pow(10,9);
int modulo = inf+7;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
string a;
bool yas = 0;
void checker(int say,int tak, int mx){
	if(say==mx){
		int l = 0, r = 0;
		fori(3)
			l+=a[i],r+=a[3+i];
		if(l>=r)
			yas = 1;
		return;
	}
	fori(6)
		if(!(tak&(1<<i))){
			tak^=(1<<i);
			char kox = a[i];
			if(i>2)
				a[i] = '0';
			else
				a[i] = '9';
			checker(say+1,tak,mx);
			a[i] = kox;
			tak^=(1<<i);
		}
}
int main()
{
	cin>>a;
	int f = 0, l = 0;
	fori(3)
		f+=a[i]-'0';
	fori(3)
		l+=a[3+i]-'0';
	if(f>l)
		fori(3){
			char tm = a[i];
			a[i] = a[3+i], a[3+i] = tm;
		}
	int mn = 0;
	while(1){
		checker(0,0,mn);
		if(yas)
			break;
		else
			++mn;
	}
	cout<<mn;
}