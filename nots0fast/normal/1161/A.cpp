#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define forx(v) for(int x=0; x<v; x++)
#define fory(v) for(int y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX 100100
#define MAX2 220
#define pb(a) push_back(a)
double eps = 1e-12;
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

int fr[MAX];
int ls[MAX];
int cnt[MAX];

void deal(){
	int n,k;
	cin>>n>>k;
	fori(MAX)
		fr[i] = MAX;
	fori(MAX)
		ls[i] = -1;
	fori(k){
		int x;
		cin>>x;
		ls[x] = max(ls[x], i);
		fr[x] = min(fr[x], i);
	}
	ll s = 0;
	ls[0] = MAX;
	ls[n+1] = MAX;
	for(int i=1; i<=n; i++){
		if(ls[i] == -1){
			++s;
			if(i-1!=0)
				++s;
			if(i!=n )
				++s;
		}		
		else{
			if(ls[i-1] < fr[i])
				++s;
			if(ls[i+1] < fr[i])
				++s;
		}
	}
	cout<<s;
	
	
}



int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}