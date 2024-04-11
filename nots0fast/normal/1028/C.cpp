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
#define ld long double
#define pb push_back
int inf = pow(10,9)+7;
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int Lz[20*MAX] = {};
int Mx[20*MAX] = {};
int all[MAX][4];
int back[MAX];
int n;
int found = -1, fl, fr;
bool J(vector<int>& a,vector<int>& b){
	if(a[1] != b[1])
		return a[1] < b[1];
	return a[0] > b[0];
}
void keep(int node){
	if(Lz[node]){
		Mx[node]+=Lz[node];
		Lz[node<<1]+=Lz[node];
		Lz[(node<<1)|1]+=Lz[node];
		Lz[node] = 0;
	}
}
void upd(int node,int l,int r,int a,int b,int vl){
	if(l>r || r<a || l>b)
		return;
	keep(node);
//	cout<<"updating "<<l<<" "<<r<<endl; 
	if(l>=a && r<=b){
		Mx[node]+=vl;
		Lz[node<<1]+=vl;
		Lz[(node<<1)|1]+=vl;
		if(Mx[node] == n-1){
			found = node;
			fl = l, fr = r;
		}
		return;
	}
	upd(node<<1,l,(l+r)/2,a,b,vl);
	upd((node<<1)|1,(l+r)/2+1,r,a,b,vl);
	Mx[node] = max(Mx[node<<1],Mx[(node<<1)|1]);
}
map<int,int> mp;
void fx(){
	map<int,int> :: iterator it = mp.begin();
	int index = 0;
	while(it!=mp.end()){
		(*it).ss = index;
		back[index] = (*it).ff;
		++it;
		++index;
	}
}
void go(int node,int l,int r){
	if(l==r){
		cout<<back[l]<<endl;
		return;
	}
	keep(node<<1);
	keep((node<<1)|1);
	if(Mx[node<<1] > Mx[(node<<1)|1])
		go(node<<1,l,(l+r)/2);
	else
		go((node<<1)|1,(l+r)/2+1,r);
}
void deal(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	vector<vector<int> > all1;
	fori(n){
		forj(4)
			cin>>all[i][j];
		vector<int> yn(4);
		yn[0] = 1, yn[1] = all[i][0], yn[2] = all[i][1], yn[3] = all[i][3];
		all1.pb(yn);
		yn[0] = -1, yn[1] = all[i][2];
		mp[yn[2]] = 1, mp[yn[3]] = 1;
		all1.pb(yn);
	}
	fx();
	sort(all1.begin(),all1.end(),J);
	fori(all1.size()){
//		cout<<"we are at x: "<<all1[i][1]<<endl;
		upd(1,0,2*n-1,mp[all1[i][2]],mp[all1[i][3]],all1[i][0]);
		if(found!=-1){
			cout<<all1[i][1]<<" ";
			go(found,fl,fr);
			return;
		}
	}
}
int main() {
	deal();
	return 0;
}