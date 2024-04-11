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
#define MAX 200100
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
	set<int> zeros;
	set<int> ones;
	string a;
	cin>>a;
	fori(a.length()){
		if(a[i]=='0')
			zeros.insert(i);
		else
			ones.insert(i);
	}
	vector<vector<int> > all;
	while(zeros.size()){
		vector<int> inp;
		int ind = (*zeros.begin());
		zeros.erase(zeros.begin());
		int kd = 0;
		set<int> :: iterator it, it1;
		while(1){
			inp.push_back(ind);
			if(!kd){
				ones.insert(ind);
				it = ones.find(ind);
				it1 = it, ++it;
				ones.erase(it1);
				if(it==ones.end())
					break;
				ind = *it;
				ones.erase(it);
			}
			else{
				zeros.insert(ind);
				it = zeros.find(ind);
				it1 = it, ++it;
				zeros.erase(it1);
				if(it==zeros.end())
					break;
				ind = *it;
				zeros.erase(it);
			}
			kd = !kd;
		}
		if(kd){
			cout<<-1;
			return;
		}
		all.push_back(inp);
	}
	if(ones.size()){
		cout<<-1;
		return;
	}
	cout<<all.size()<<'\n';
	fori(all.size()){
		cout<<all[i].size()<<' ';
		forj(all[i].size())
			cout<<all[i][j]+1<<' ';
		cout<<'\n';
	}
}
int main() {
	deal();
}