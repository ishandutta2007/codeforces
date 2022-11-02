#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

struct P{
	int x,y;
	int id,type;
	P(){}
	bool operator<(const P &s)const{
		return x<s.x || x==s.x && y<s.y;
	}
} p[444444];
int n;

int best = 1e9;
int v1,t1,v2,t2;


void go(vector<P> v){
	//cout<<v.size()<<endl;
	if(v.size()==0) return;
	if(v[0].x == v.back().x){
		REP(i,v.size()) REP(dx,4){
			int j = i - dx - 1;
			if(j>=0 && v[i].id!=v[j].id){
				if(best > (v[i].y-v[j].y)*(v[i].y-v[j].y)){
					best = (v[i].y-v[j].y)*(v[i].y-v[j].y);
					v1 = v[i].id;
					v2 = v[j].id;
					t1 = v[i].type;
					t2 = v[j].type;
				}
			}
		}
	}else{
		int X = (v[0].x+v.back().x);
		if(X<0) X--;
		X>>=1;
		vector<P> p1,p2;
		REP(i,v.size()) if(v[i].x<=X) p1.pb(v[i]);
		else p2.pb(v[i]);
		go(p1);
		go(p2);

		REP(i,p1.size()) if(((X+1)-p1[i].x)*((X+1)-p1[i].x)>=best){
			swap(p1[i],p1.back());
			p1.pop_back();
			i--;
		}
		REP(i,p2.size()) if((X-p2[i].x)*(X-p2[i].x)>=best){
			swap(p2[i],p2.back());
			p2.pop_back();
			i--;
		}
		REP(i,p1.size()) swap(p1[i].x,p1[i].y);
		REP(i,p2.size()) swap(p2[i].x,p2[i].y);
		SORT(p1),SORT(p2);
		REP(i,p1.size()) swap(p1[i].x,p1[i].y);
		REP(i,p2.size()) swap(p2[i].x,p2[i].y);
		
		int start2 = 0;
		REP(i,p1.size()){
			while(start2<p2.size() && p2[start2].y < p1[i].y && (p2[start2].y-p1[i].y)*(p2[start2].y-p1[i].y)>=best) start2++;
			for(int j = start2;j<p2.size();j++){
				if(p2[j].y > p1[i].y && (p2[j].y-p1[i].y)*(p2[j].y-p1[i].y)>=best) break;
				if(p1[i].id == p2[j].id) continue;
				int val = (p2[j].y-p1[i].y)*(p2[j].y-p1[i].y)+(p2[j].x-p1[i].x)*(p2[j].x-p1[i].x);
				if(val<best){
					best=val;
					v1=p1[i].id;
					v2=p2[j].id;
					t1=p1[i].type;
					t2=p2[j].type;
				}
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost
	freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d %d",&p[i].x,&p[i].y),p[i].id=i,p[i].type=0;
	REP(i,n) p[i+n]=p[i],p[i+n].x*=(-1),p[i+n].type=1;
	REP(i,n) p[i+2*n]=p[i],p[i+2*n].y*=(-1),p[i+2*n].type=2;
	REP(i,n) p[i+3*n]=p[i],p[i+3*n].y*=(-1),p[i+3*n].x*=(-1),p[i+3*n].type=3;

	vector<P> v(4*n);
	REP(i,4*n)v[i]=p[i];
	sort(v.begin(),v.end());
	go(v);
	cout<<v1+1<<' '<<t1+1<<' '<<v2+1<<' '<<4-t2<<endl;
	//cout<<best<<endl;
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}