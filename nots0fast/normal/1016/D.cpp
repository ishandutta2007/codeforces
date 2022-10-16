#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<(lli)v; i++)
#define forj(v) for(lli j=0; j<(lli)v; j++)
#define fork(v) for(lli k=0; k<(lli)v; k++)
#define forl(v) for(lli l=0; l<(lli)v; l++)
#define fort(v) for(lli t=0; t<(lli)v; t++)
#define forz(v) for(lli z=0; z<(lli)v; z++)
#define lli long long int
#define MAX 500002
#define double long double
#define ch  1430
#define pb push_back
lli inf = 8*pow(10,18);
lli modulo = pow(10,9)+7;
double eps = 1e-8;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
	int n,m;
	cin>>n>>m;
	int arr1[n], arr2[m];
	int arr[n][m] = {};
	fori(n)
		cin>>arr1[i];
	fori(m)
		cin>>arr2[i];
	fori(30){
		int sy[2] = {};
		deque<int> to[2];
		forj(n)
			if((1<<i) & arr1[j])
				sy[0]++, to[0].push_back(j);
		forj(m)
			if((1<<i) & arr2[j])
				sy[1]++, to[1].pb(j);
		int mx = max(sy[1],sy[0]), mn = min(sy[1],sy[0]);
		if((mx-mn)&1){
			cout<<"NO";
			return;
		}
		if(!sy[0] && !sy[1])
			continue;
		if(!sy[0])
			to[0].pb(0);
		if(!sy[1])
			to[1].pb(0);
		if(sy[0]>sy[1]){
			while(to[1].size()){
				int wh = to[1][0];
				to[1].pop_front();
				while(to[0].size() > to[1].size())
					arr[to[0][0]][wh]|=(1<<i) , to[0].pop_front();
			}
		}
		else{
			while(to[0].size()){
				int wh = to[0][0];
				to[0].pop_front();
				while(to[1].size() > to[0].size())
					arr[wh][to[1][0]]|=(1<<i) , to[1].pop_front();
			}
		}
	}
	cout<<"YES\n";
	fori(n){
		forj(m)
			cout<<arr[i][j]<<" ";
		cout<<'\n';
	}
}
int main(){
	srand(time(NULL));
	in.open("i.txt");
	out.open("o.txt");
	deal();
}