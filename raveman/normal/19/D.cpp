#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n;
char s[222222][10];
int x[222222],y[222222];

vector<pii> p;
vi          m;

void add(int x,int y){
	int z = lower_bound(p.begin(), p.end(), pii(x,y)) - p.begin();
	z += p.size();
	while(z) m[z] = max(m[z], y),z >>= 1;
}

void remove(int x,int y){
	int z = lower_bound(p.begin(), p.end(), pii(x,y)) - p.begin();
	z += p.size();
	while(z){
		m[z] = -1111111111;
		if(2*z < 2*p.size()) m[z] = max(m[z], m[2*z]);
		if(2*z+1 < 2*p.size()) m[z] = max(m[z], m[2*z+1]);
		z>>=1;
	}
}

int get(int p1,int p2){
	int val = -1111111111;
	while(p1<=p2){
		val = max(val, m[p1]);
		val = max(val, m[p2]);
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return val;
}

pii go(int x,int y){
	int pos = lower_bound(p.begin(), p.end(), pii(x+1,y+1)) - p.begin();
	int end = p.size() - 1;
	pos += p.size(), end += p.size();
	if(get(pos,end)<=y) return pii(-1,-1);
	int best = -1;
	while(pos<=end){
		int s = (pos+end)/2;
		if(get(pos,s)>y) best = s,end=s-1;
		else pos=s+1;
	}
	return p[pos-p.size()];
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n) scanf(" %s %d %d",s[i],&x[i],&y[i]);
	REP(i,n) if(s[i][0]!='f') p.pb(pii(x[i],y[i]));
	UN(p);
	m.resize(2*p.size(), -1111111111);
	REP(i,n){
		if(s[i][0]=='a') add(x[i],y[i]);
		else if(s[i][0]=='r') remove(x[i],y[i]);
		else {
			pii res = go(x[i], y[i]);
			if(res.first == -1) puts("-1");
			else printf("%d %d\n",res.first,res.second);
		}
	}

	return 0;
}