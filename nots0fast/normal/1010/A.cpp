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
#define MAX 200002
#define double long double
#define ch 121
#define pb push_back
lli inf = 8*pow(10,18);
int modulo = pow(10,9)+7;
double eps = 1e-8;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
vector<int> dsu[MAX];
int aid[MAX];
map<int,int> xs,ys;
void ini(){
	fori(MAX)
		aid[i] = i, dsu[i].clear(), dsu[i].push_back(i);
}
void combine(int a, int b){
	int aid1 = aid[a], aid2 = aid[b];
	if(aid1==aid2)
		return;
	if(dsu[aid1].size() < dsu[aid2].size()){
		int tm = aid1;
		aid1 = aid2, aid2 = tm;
	}
	forj(dsu[aid2].size()){
		int hd = dsu[aid2][j];
		aid[hd] = aid1;
		dsu[aid1].pb(hd);
	}
	dsu[aid2].clear();
}
void deal(){
	int n;
	double m;
	cin>>n>>m;
	double ar[n][2];
	forj(2)
		fori(n)
			cin>>ar[i][j];
	double a = 0, b= pow(10,9)+ 100;
	while((b-a)>eps){
		double c = (a+b)/2;
		double w = m + c;
		w -= w/ar[0][1];
//		cout<<w<<endl;
		for(int i=1; i<n; i++){
			forj(2){
				w-=w/ar[i][j];
//		cout<<w<<endl;
			}
		}
		w -= w/ar[0][0];
//		cout<<w<<endl;
		if(w<m)
			 a=c;
		else
			b=c;
	}
	if(a<=pow(10,9) + 10)
		cout<<setp(22)<<a;
	else
		cout<<-1;
}
int main(){
	in.open("i.txt");
	out.open("o.txt");
	deal();
}