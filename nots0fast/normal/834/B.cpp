#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define lli long long int
#define double long double
#define MAX 300001
int inf = pow(10,9);
int modulo = 20011;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	string a;
	cin>>a;
	int arr[26];
	int ol[26] = { };
	fori(a.length())
		arr[a[i]-'A'] = i;
	int say  =0;
	fori(a.length()){
		if(!ol[a[i]-'A'])
			ol[a[i]-'A']=1, ++say;
		if(say>k){
			cout<<"YES";
			return 0;
		}
		if(arr[a[i]-'A']==i)
			--say;
	}
	cout<<"NO";
}