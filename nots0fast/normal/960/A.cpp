#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli  long long int
#define MAX 51
#define ch 300
#define double long double
int inf = pow(10,9);
unsigned lli modulo = pow(10,9)+7;
double eps = 1e-7;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	string a;
	cin>>a;
	int sy[3]=  {};
	bool ok = 1;
	fori(a.length()){
		if(a[i]=='a'){
			if(sy[1] || sy[2])	
				ok = 0;
			else
				sy[0]++;
		}
		else if(a[i]=='b'){
			if(sy[2] || !sy[0])
				ok = 0;
			else
				sy[1]++;
		}
		else if(a[i]=='c'){
			if(!sy[0] || !sy[1])
				ok = 0;
			else
				sy[2]++;
		}
		else
			ok = 0;
	}
	if(!sy[0] || !sy[1] || !sy[2])
		ok = 0;
	if(ok && (sy[0]==sy[2] || sy[1]==sy[2]))
		cout<<"YES";
	else
		cout<<"NO";
}
int main() {
//	map<int,int> aaa;
//	aaa[1] = 2;
//	aaa.insert(mp(1,3));
//	cout<<aaa[1]<<endl;
	deal();
}