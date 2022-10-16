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
#define MAX 100010 
#define ch 220
lli inf = pow(10,18);
lli modulo = pow(10,9)+7;
double eps = 1e-9;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
lli sy = 0;
lli fen[MAX] = {};
struct ara{
	pair<lli,lli> start;
	pair<lli,lli> end;
	lli index;
};
void upd(lli ind, lli vl){
	while(ind<MAX){
		fen[ind]+=vl;
		ind+=ind&-ind;
	}
}
lli que(lli ind){
	lli s = 0;
	while(ind){
		s+=fen[ind];
		ind-=ind&-ind;
	}
	return s;
}
lli gcd(lli a,lli b){
	return !b ? a : gcd(b,a%b);
}
void fix(pair<lli,lli>& a){
	lli ebob = gcd(a.ff,a.ss);
	a.ff/=ebob, a.ss/=ebob;
}
bool J(ara &a, ara &b){
	return a.start.ff * b.start.ss < a.start.ss * b.start.ff;
}
bool J1(ara& a, ara& b){
	return a.end.ff * b.end.ss < a.end.ss * b.end.ff;
}
void handle(vector<ara> &a){
	lli n = a.size();
	sort(a.begin(),a.end(),J1);
	lli keep  =1;
	fori(n){
		a[i].index = keep;
		upd(keep,1);
		if(i+1<n && !(!J1(a[i],a[i+1]) && !J1(a[i+1],a[i])))
			++keep;
	}
	sort(a.begin(),a.end(),J);;
	for(lli i=0; i<n;){
		lli st = i;
		while(st<n && !J(a[i],a[st]) && !J(a[st],a[i]))
			upd(a[st].index,-1), ++st;
		sy+=(st-i)*(st-i-1)/2;
//		cout<<"i st "<<i<<" "<<st<<endl;
		while(i<st){
			sy+=que(a[i].index);
//			cout<<"the index "<<a[i].index<<endl;
			++i;
		}
	}
}
lli ind(ara &aa, vector<ara > &all){
	lli a = 0, b = all.size()-1;
	if(!all.size() || J(aa,all[0]))
		return 0;
	while(a<b){
		lli c = (a+b)/2+1;
		if(J(aa,all[c]))
			b=c-1;
		else
			a=c;
	}
	return a+1;
}
void deal(){
	lli n,w;
	cin>>n>>w;
	vector<ara> all[2];
	fori(n){
		lli x,v;
		cin>>x>>v;
		ara a;
		lli kd = 0;
		if(x<0)
			x = -x;
		else
			v = -v, kd = 1;
		a.start.ff = x, a.end.ff = x;
		a.start.ss = (v+w), a.end.ss = v-w;
		fix(a.start); fix(a.end);
		all[kd].push_back(a);
//		cout<<(double)(x)/(double)(v-w)<<" "<<(double)(x)/(double)(v+w)<<endl;
	}
	sort(all[0].begin(),all[0].end(),J);
	sort(all[1].begin(),all[1].end(),J);
	for(lli kd=0; kd<2; ++kd)
		fori(all[kd].size()){
			lli ind1,ind2;
			ind1 = ind(all[kd][i],all[!kd]);
			pair<lli,lli> temp = all[kd][i].start;
			all[kd][i].start = all[kd][i].end;
			ind2 = ind(all[kd][i],all[!kd]);
			all[kd][i].start = temp;
	//		cout<<"for the guy "<<all[kd][i].ff<<" "<<all[kd][i].ss-w<<endl;
	//		cout<<"ind2 ind1 : "<<ind2<<" "<<ind1<<endl;
			sy+=ind2-ind1;
		}
	map<lli,lli> last;
	fori(all[0].size())
		all[0][i].start.ff*= 3*pow(10,5), last[all[0][i].start.ff + all[0][i].start.ss]++;
	fori(all[1].size())
		all[1][i].start.ff*=3*pow(10,5),  sy+=last[all[1][i].start.ff + all[1][i].start.ss];
	handle(all[0]); handle(all[1]);
	cout<<sy<<endl;
}
int main(){
	deal();
}