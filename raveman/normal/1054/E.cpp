#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	

int n,m;
string tmp[333][333];
string a[333][333];
int eo[333];
string b[333][333];
char t[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int s=0;
	cin>>n>>m;
	REP(i,n)REP(j,m){
		scanf("%s",t);
	
		a[i][j]=t;
		tmp[i][j]=t;
		s += a[i][j].size();
	}
	REP(i,n)REP(j,m){
		scanf("%s",t);
		b[i][j]=t;
	}
	vi r;
	// move out
	REP(i,a[0][0].size()){
		r.pb(0);r.pb(0);
		r.pb(0);r.pb(1);
	}
	a[0][1]=a[0][0]+a[0][1];
	a[0][0]="";

	REP(i,a[1][1].size()){
		r.pb(1);r.pb(1);
		r.pb(1);r.pb(0);
	}
	a[1][0]=a[1][1]+a[1][0];
	a[1][1]="";

	// sort
	REP(i,n)REP(j,m){
		if(i==1 && j==1) continue;
		if(i==1 && eo[j]){
			a[i][j]=string(eo[j],'1') + a[i][j];
			//cout<<i<<' '<<j<<endl;	puts("HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		while(!a[i][j].empty()){
			//cout<<i<<' '<<j<<' '<<a[i][j].size()<<' '<<a[i][j]<<endl;

			if(a[i][j].back()=='0'){
				r.pb(i);r.pb(j);
				if(i==0 || j==0){
				}else{
					r.pb(0);r.pb(j);
					r.pb(0);r.pb(j);
				}
				r.pb(0);r.pb(0);

				a[i][j].pop_back();
				a[0][0].pb('0');
			}else{
				r.pb(i);r.pb(j);
				if(i==1 || j==1){
				}else if(i==0){
					eo[j]++;
					r.pb(1);r.pb(j);
					a[i][j].pop_back();
					continue;
				}else{
					r.pb(1);r.pb(j);
					r.pb(1);r.pb(j);
				}
				r.pb(1);r.pb(1);
				a[i][j].pop_back();
				a[1][1].pb('1');
			}
		}
	}

	REP(i,n)REP(j,m)reverse(b[i][j].begin(),b[i][j].end());

	// move rest
	FOR(i,2,n)REP(j,m){
		REP(k,b[i][j].size()){
			if(b[i][j][k]=='0'){
				r.pb(0);r.pb(0);
				if(j!=0){
					r.pb(0);r.pb(j);
					r.pb(0);r.pb(j);
				}
				r.pb(i);r.pb(j);
			}else{
				r.pb(1);r.pb(1);
				if(j!=1){
					r.pb(1);r.pb(j);
					r.pb(1);r.pb(j);
				}
				r.pb(i);r.pb(j);
			}
		}
	}
	// first row
	FOR(j,2,m){
		REP(k,b[0][j].size()){
			if(b[0][j][k]=='0'){
				r.pb(0);r.pb(0);
				r.pb(0);r.pb(j);
			}else{
				r.pb(1);r.pb(1);
				r.pb(0);r.pb(1);
				r.pb(0);r.pb(1);
				r.pb(0);r.pb(j);
			}
		}
	}
	// second row
	FOR(j,2,m){
		REP(k,b[1][j].size()){
			if(b[1][j][k]=='0'){
				r.pb(0);r.pb(0);
				r.pb(1);r.pb(0);
				r.pb(1);r.pb(0);
				r.pb(1);r.pb(j);
			}else{
				r.pb(1);r.pb(1);
				r.pb(1);r.pb(j);
			}
		}
	}


	// move first 2
	string t1 = b[0][0] + b[0][1];
	REP(i,t1.size()){
		if(t1[i]=='0'){
			r.pb(0);r.pb(0);
			r.pb(0);r.pb(1);
		}else{
			r.pb(1);r.pb(1);
			r.pb(0);r.pb(1);
		}
	}
	string t2 = b[1][1] + b[1][0];
	REP(i,t2.size()){
		if(t2[i]=='0'){
			r.pb(0);r.pb(0);
			r.pb(1);r.pb(0);
		}else{
			r.pb(1);r.pb(1);
			r.pb(1);r.pb(0);
		}
	}
	
	
	// move first 2
	REP(i,b[0][0].size()){
		r.pb(0);r.pb(1);
		r.pb(0);r.pb(0);
	}
	REP(i,b[1][1].size()){
		r.pb(1);r.pb(0);
		r.pb(1);r.pb(1);
	}
	cout<<r.size()/4<<endl;
	REP(i,r.size()){
		printf("%d ",r[i]+1);
		if(i%4==3)puts("");
	}
	return 0;

	while (r.size()/4 > s * 4) puts("MASTER FUCK");

	REP(i,n)REP(j,m)reverse(b[i][j].begin(),b[i][j].end());

	for(int i=0;i<r.size();i+=4){
		int x1 = r[i];
		int y1 = r[i+1];
		int x2 = r[i+2];
		int y2 = r[i+3];
		cout<<i<<": "<<endl;
		while(tmp[x1][y1]=="") puts("FUCK");
		if(x1==x2 && y1==y2){puts("FUCK2");while(1);}
		tmp[x2][y2]=string(1,tmp[x1][y1].back())+tmp[x2][y2];
		tmp[x1][y1].pop_back();

		cout<<"step"<<endl;
		REP(ii,n){
			REP(jj,m) cout<<tmp[ii][jj]<<' ';
			puts("");
		}
	}
	REP(i,n)REP(j,m)if(tmp[i][j]!=b[i][j]){
		//cout<<i<<' '<<j<<" = " <<tmp[i][j]<<" "<<b[i][j]<<endl;
		puts("FUCK3");
	}
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}