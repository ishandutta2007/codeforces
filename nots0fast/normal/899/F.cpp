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
#define MAX 200001
#define ch 2000
#define nm 50
int inf = pow(10,9);
lli modulo = inf;
double eps = 1e-10;
ifstream in;
ofstream out;
int fen[MAX] = { };
void upd(int ind, int vl){
	while(ind<MAX){
		fen[ind]+= vl;
		ind+=ind&-ind;
	}
}
int que(int ind){
	int sum = 0;
	while(ind){
		sum+=fen[ind];
		ind-=ind&-ind;
	}
	return sum;
}
int hash_fr(char a){
	if(a>='a' && a<='z')
		return a-'a';
	else if(a>='A' && a<='Z')
		return a-'A' + 26;
	else 
		return a-'0' + 52;
}
char hash_rev(int ind){
	if(ind<26)
		return 'a' + ind;
	else if(ind<52)
		return 'A' + (ind-26);
	else
		return '0' +  (ind-52);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	set<int> arr[62];
	string a;
	cin>>a;
	fori(n)
		arr[hash_fr(a[i])].insert(i+1);
	fori(m){
		int l,r;
		char f;
		cin>>l>>r>>f;
		int a = l , b = n;
		while(a<b){
			int c = (a+b)/2;
			if(c-que(c)>=l)
				b=c;
			else
				a=c+1;
		} 
		l = a;
		a = r , b = n;
		while(a<b){
			int c = (a+b)/2;
			if(c-que(c)>=r)
				b=c;
			else
				a=c+1;
		} 
		r = a;
		int wh = hash_fr(f);
		set<int> :: iterator it1,it = arr[wh].find(l);
		if(it==arr[wh].end()){
			arr[wh].insert(l);
			it = arr[wh].find(l);
			upd(l,-1);
		}
		while(it!=arr[wh].end() && *it <= r){
			it1 = it; ++it1;
			upd(*it,1);
			arr[wh].erase(it);
			it = it1;
		}
	}
	map<int,char> ls;
	fori(62){
		char tap = hash_rev(i);
		set<int> :: iterator it = arr[i].begin();
		while(it!=arr[i].end()){
			ls.insert(mp(*it,tap));
			++it;
		}
	}
	map<int,char> :: iterator it = ls.begin();
	string ans ="";
	while(it!=ls.end()){
		ans+=(*it).ss;
		++it;
	}
	cout<<ans<<'\n';
}