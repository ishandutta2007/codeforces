//g++ -std=c++17 -Wall t.cpp -o test -g -O2
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define endl '\n'
#define teto(a,b) (a+b-1)/(b)
const int MAX=200010;
const ll MOD=1e9+7;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const ld EPS=1e-6;
const ld PI=acos(-1.0);
using namespace std;
struct seg{
	int xl, xr, y;
	bool operator<(const seg &o)const{
		return y<o.y;
	}
};
vector<seg> vet;
ld get_diff(ld ang){
	ld m=LLINF,M=-LLINF;
	for(auto v:vet){
		m=min(m,v.xl+ang*v.y);
		M=max(M,v.xr+ang*v.y);
	}
	return M-m;
}
int main(){
	int n,xl,xr,y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>xl>>xr>>y;
		seg a={xl,xr,y};
		vet.pb(a);
	}
	vector<pair<ld,int> > angs;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(vet[i].y<=vet[j].y){
				continue;
			}
			angs.eb((vet[j].xl-vet[i].xr)/(ld)(vet[i].y-vet[j].y),1);
			angs.eb((vet[j].xr-vet[i].xl)/(ld)(vet[i].y-vet[j].y),0);
		}
	}
	vector<ld> escolhas;
	if(angs.empty()){
		cout<<get_diff(0)<<endl;
		return 0;
	}
	else{
		int k=0;
		sort(angs.begin(),angs.end());
		for(auto a:angs){
			if((a.ss==1&&k==0)||(a.ss==0&&k==1)){
				escolhas.push_back(a.ff);
			}
			k+=(a.ss?1:-1);
		}
	}
	int l=0,r=(int)escolhas.size()-1;
    while(r-l>2){
		int m1=l+(r-l)/3;
		int m2=r-(r-l)/3;
		ld v1=get_diff(escolhas[m1]);
		ld v2=get_diff(escolhas[m2]);
		if(v1<=v2){
			r=m2;
		}
		if(v2<=v1){
			l=m1;
		}
	}
	ld ans=LLINF;
    for(int i=l;i<=r;i++){
		ans=min(ans,get_diff(escolhas[i]));
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}