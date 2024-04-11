#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(lli k=0; k<v; k++)
#define forl(v) for(lli l=0; l<v; l++)
#define fort(v) for(lli t=0; t<v; t++)
#define forz(v) for(lli z=0; z<v; z++)
#define forx(v) for(lli x=0; x<v; x++)
#define lli long long int
#define MAX 100010
#define ch 51
#define double long double
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-15;
ifstream in;
ofstream out;
void deal(){
	int n;
	cin>>n;
	string names[3] = {"Kuro", "Shiro", "Katie"};
	int nums[3];
	forj(3){
		int arr[52] = {};
		string a;
		cin>>a;
		fori(a.length()){
			if(a[i]>='A' && a[i]<='Z')
				arr[a[i]-'A'+26]++;
			else
				arr[a[i]-'a']++;
		}
		int mx = 0;
		fori(52)
			mx = max(mx,arr[i]);
		if(mx+n>a.length() && mx==(int)a.length() && n==1)
			nums[j] = (int)a.length()-1;
		else
			nums[j] = min(mx+n,(int)a.length());
	}
	fori(3){
		bool ok = 1;
		forj(3){
			if(i==j)
				continue;
			if(nums[i]<=nums[j])
				ok = 0;
		}
		if(ok){
			cout<<names[i];
			return;
		}
	}
	cout<<"Draw";
}
int main() {
    deal();
}