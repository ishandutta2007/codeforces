#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(10)<<fixed
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
int inf = pow(10,9);
lli modulo = inf+7;
double eps = 1e-10;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
set<string> names;
vector<string> xam[2];
int num(string a){
	if(a[0]=='0')
		return -1;
	int ed = 0;
	fori(a.length()){
		if(a[i]>'9' || a[i]<'0')
			return -1;
		ed*=10;
		ed+=a[i]-'0';
	}
	return ed;
}
string nn(int a){
	stringstream ss;
	string yee;
	ss<<a;
	ss>>yee;
	ss.clear();
	return yee;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<pair<string,bool> > all(n);
	vector<string> nip[2];
	vector<int> free[2];
	vector<string> gen[2];
	vector<string > cmd;
	int say[2] = { };
	int yer[n+1] = { };
	fori(n){
		cin>>all[i].ff>>all[i].ss;
		say[all[i].ss]++;
	}
	fori(n){
		int ed = num(all[i].ff);
		if(ed!=-1 && ed<=n){
			yer[ed] = 1;
			if((!all[i].ss && ed<=say[1]) || (all[i].ss && ed>say[1]))
				nip[all[i].ss].push_back(all[i].ff);
		}
		else
			gen[all[i].ss].push_back(all[i].ff);
	}
	for(int i=1; i<=n; i++)
		if(!yer[i]){
			if(i<=say[1])
				free[1].push_back(i);
			else
				free[0].push_back(i);
		}
	if(!nip[0].size() && !nip[1].size() && !gen[0].size() && !gen[1].size()){
		cout<<0;
		return 0;
	}
	int kd = 1;
	int sv = -1;
	if(free[1].size())
		kd = 1;
	else if(free[0].size())
		kd = 0;
	else{
		sv = num(nip[0][nip[0].size()-1]);
		free[1].push_back(sv);
		cmd.push_back("move "+nip[0][nip[0].size()-1]+" 999999");
		nip[0].erase(nip[0].end()-1);
	}
	while(nip[0].size() || nip[1].size() || gen[0].size() || gen[1].size()){
		if(nip[kd].size()){
			int cav = num(nip[kd][nip[kd].size()-1]);
			free[!kd].push_back(cav);
			cmd.push_back("move "+nip[kd][nip[kd].size()-1]+" "+nn(free[kd][free[kd].size()-1]));
			nip[kd].erase(nip[kd].end()-1);
			free[kd].erase(free[kd].end()-1);
		}
		else if(gen[kd].size()){
			cmd.push_back("move "+gen[kd][gen[kd].size()-1]+" "+nn(free[kd][free[kd].size()-1]));
			gen[kd].erase(gen[kd].end()-1);
			free[kd].erase(free[kd].end()-1);
		}
		kd = !kd;
	}
	if(sv!=-1)
		cmd.push_back("move 999999 "+nn(free[0][0]));
	cout<<cmd.size()<<'\n';
	fori(cmd.size())
		cout<<cmd[i]<<'\n';
}