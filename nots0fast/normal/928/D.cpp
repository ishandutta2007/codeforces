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
#define double long double
int inf = pow(10,9);
lli modulo = pow(10,9)+7;
double eps = 1e-15;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int sy = 0;
struct Trie{
	int sy = 0;
	bool nd = 0;
	map<char,Trie*>  yen;
};
Trie *root = new Trie();
void fix(Trie* rt, string a, int ind){
	while(1){
		--rt->sy;
		if(ind==a.length())
			return;
		map<char,Trie*> :: iterator it = rt->yen.find(a[ind]);
		++ind;
		rt = (*it).ss;
	}
}
bool fx ;
void Ins(Trie* rt, string a, int ind, bool ended, int tr){
	while(1){
	//	cout<<"the index: "<<ind<<" say: "<<rt->sy<<endl;
		if(rt!=root && rt->sy == 1)
			++tr;
		if(rt->nd && rt->sy == 1)
			ended = 1;
		rt->sy++;
		if(ind==a.length()){
	//		cout<<"did it end "<<ended<<" for how long "<<tr<<endl;
			if(ended)
				sy+=min(ind,ind-tr+2);
			else
				sy+=ind;
			if(rt->nd)
				fx = 1;
			rt->nd = 1;
			return ;
		}
		if(rt->yen.find(a[ind]) == rt->yen.end())
			rt->yen.insert(mp(a[ind],new Trie()));
		map<char,Trie*> :: iterator it = rt->yen.find(a[ind]);
		rt = (*it).ss; ++ind;
	}
}
void deal(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string a;
	while(getline(cin,a)){
		vector<string> wrd;
		string wd = "";
		fori(a.length()){
			if(a[i]>='a' && a[i]<='z')
				wd+=a[i];
			else{
				if(wd!="")
					wrd.push_back(wd);
				wd = "";
				++sy;
			}
		}
		if(wd!="")
			wrd.push_back(wd);
		fori(wrd.size()){
			fx = 0;
//			cout<<wrd[i]<<" "<<sy<<endl;
			Ins(root,wrd[i],0,0,0);
			if(fx)
				fix(root,wrd[i],0);
		}
		++sy;
	}
	cout<<sy<<'\n';
}
int main() {
	deal();
}