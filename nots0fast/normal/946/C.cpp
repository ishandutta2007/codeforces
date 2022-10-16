#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(4)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define MAX 100010
#define double long double
#define ch 400
int inf = pow(10,9);
lli modulo = pow(10,9)+7;
lli md = pow(10,9)+7;
double eps = 1e-13;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
	string a;
	cin>>a;
	int len = a.length();
	int Mn[len][26] ;
	int wh[len][26] ;
	fori(len)
		forj(26)
			Mn[i][j] = inf;
	fori(len){
		if(i)
			forj(26)
				Mn[i][j] = Mn[i-1][j], wh[i][j] = j;
		for(int j=25; j>-1; j--)
			if(a[i]-'a' <= j ){
				int bif = 0;
				if(j)
					bif = Mn[i][j-1];
				int dif = a[i]-'a';
				if(bif + dif < Mn[i][j])
					Mn[i][j] = bif+dif, wh[i][j] = j-1;
			}
	}
	if(Mn[len-1][25] == inf)
		cout<<-1;
	else{
		int ind = len-1;
		int st = 25;
		string ans = "";
		while(st>-1){
			if(wh[ind][st] == st-1){
				ans+='a'+st;
				--st;
			}
			else
				ans+=a[ind];
			--ind;
		}
		for(ind; ind>-1; --ind)
			ans+=a[ind];
		reverse(ans.begin(),ans.end());
		cout<<ans;
	}
}
int main() {
	deal();
}