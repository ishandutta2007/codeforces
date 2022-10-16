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
#define slt set<line> :: iterator 
int inf = pow(10,9);
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void norm(string& a){
	fori(a.length()){
		if(a[i]>='A' && a[i]<='Z')
			a[i] = 'a' + (a[i]-'A');
		if(a[i]=='0')
			a[i] = 'o';
		if(a[i]=='1' || a[i]=='i')
			a[i] = 'l';
	}
			
}
void deal(){
	string a;
	cin>>a;
	int n;
	cin>>n;
	norm(a);
	fori(n){
		string b;
		cin>>b;
		norm(b);
		if(b==a){
			cout<<"No";
			return;
		}
	}
	cout<<"Yes";
}
int main() {
	deal();
}