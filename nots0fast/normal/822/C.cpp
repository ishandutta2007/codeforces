#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(1)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define lli long long int
#define double long double
#define MAX 200001
int inf = pow(10,9);
ifstream in; 
ofstream out;
//#define cin in
//#define cout out
bool John(pair<int,int> a,pair<int,int> b){
	return a.ff < b.ff;
}
int main(){
	int n,x;
	cin>>n>>x;
	vector<pair<int,int> > uzunluq1[MAX], uzunluq2[MAX];
	int hamisi[n][3];
	fori(n){
		int a,b,c;
		cin>>a>>b>>c;
		hamisi[i][0] = a, hamisi[i][1] = b, hamisi[i][2] = c;
		uzunluq1[b-a+1].push_back(mp(a,c));
		uzunluq2[b-a+1].push_back(mp(b,c));
	}
	fori(MAX){
		uzunluq1[i].push_back(mp(-1,-1)), uzunluq1[i].push_back(mp(inf,-1));
		uzunluq2[i].push_back(mp(-1,-1)), uzunluq2[i].push_back(mp(inf,-1));
		sort(uzunluq1[i].begin(),uzunluq1[i].end(),John);
		sort(uzunluq2[i].begin(),uzunluq2[i].end(),John);
		for(int j=uzunluq1[i].size()-3; j>0; j--)
			uzunluq1[i][j].ss = min(uzunluq1[i][j].ss,uzunluq1[i][j+1].ss);
		for(int j=2; j<uzunluq2[i].size()-1; j++)
			uzunluq2[i][j].ss = min(uzunluq2[i][j].ss,uzunluq2[i][j-1].ss);
	}
	int minn = 2*inf+10;
	fori(n){
		if(hamisi[i][1]-hamisi[i][0]+1<=x){
			int ferq = x - (hamisi[i][1]-hamisi[i][0]+1);
			int a =  0, b = uzunluq1[ferq].size()-1;
			while(a<b){
				int c = (a+b)/2;
				if(uzunluq1[ferq][c].ff<=hamisi[i][1])
					a = c+1;
				else
					b = c;
			}
	//		cout<<i<<" "<<ferq<<endl;
	//		cout<<"uzunluq1: "<<uzunluq1[ferq][a].ff<<" "<<uzunluq1[ferq][a].ss<<"\n";
			if(uzunluq1[ferq][a].ss>-1 && hamisi[i][2]+uzunluq1[ferq][a].ss<minn)
				minn = hamisi[i][2]+uzunluq1[ferq][a].ss;
			a =  0, b = uzunluq2[ferq].size()-1;
			while(a<b){
				int c = (a+b)/2+1;
				if(uzunluq2[ferq][c].ff>=hamisi[i][0])
					b = c-1;
				else
					a = c;
			}
	//		cout<<"uzunluq2: "<<uzunluq2[ferq][a].ff<<" "<<uzunluq2[ferq][a].ss<<"\n";
			if(uzunluq2[ferq][a].ss>-1 && hamisi[i][2]+uzunluq2[ferq][a].ss<minn)
				minn = hamisi[i][2]+uzunluq2[ferq][a].ss;
		}
	}
	if(minn==2*inf+10)
		cout<<-1;
	else
		cout<<minn;
}