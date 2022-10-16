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
#define MAX 100001
#define ch 2000
#define nm 50
int inf = pow(10,9);
lli modulo = inf;
double eps = 1e-10;
ifstream in;
ofstream out;
struct srt{   // ss length , ff where it starts
	bool operator () (const pair<int,int> &a, const pair<int,int> &b){
		if(a.ss == b.ss)
			return a.ff < b.ff;
		return a.ss > b.ss;
	}
};
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	set<pair<int,int> , srt> all;
	int n;
	cin>>n;
	int arr[n+2];
	arr[n] = -1, arr[n+1] = -2;
	fori(n)
		cin>>arr[i];
	int len[n];
	set<int> left;
	for(int i=0; i<n; ){
		int st = i;
		while(i<n && arr[st]==arr[i])
			++i;
		len[st] = i-st;
		left.insert(st);
		all.insert(mp(st,i-st));
	}
	int sy = 0;
	while(all.size()){
		int whe = (*all.begin()).ff;
		all.erase(all.begin());
		set<int> :: iterator it = left.find(whe);
		int bif = n;
		if(it!=left.begin()){
			--it;
			bif = *it;
			++it;
		}
		++it;
		int aft = n+1;
		if(it!=left.end())
			aft = *it;
		--it;
		left.erase(it);
		if(arr[aft]==arr[bif]){
			all.erase(all.find(mp(aft,len[aft])));
			all.erase(all.find(mp(bif,len[bif])));
			len[bif]+=len[aft];
			all.insert(mp(bif,len[bif]));
			left.erase(aft);
		}
		++sy;
	}
	cout<<sy;
}