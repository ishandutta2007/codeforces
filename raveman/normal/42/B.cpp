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
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int x[4];
int y[4];

bool under(int X,int Y){
	if(max(abs(x[2]-X),abs(y[2]-Y))==1) return 1;
	REP(i,2){
		if(x[i]==X){
			if(x[2]!=X || y[2] < min(y[i],Y) || y[2] > max(y[i],Y))
				return 1;
		}
		if(y[i]==Y){
			if(y[2]!=Y || x[2] < min(x[i],X) || x[2] >  max(x[i],X))
				return 1;
		}
	}
	return 0;
}

int pos;

bool has(int X,int Y){
	REP(i,3){
		pos = i;
		if(X==x[i] && Y==y[i])
			return 1;
	}
	return 0;
}

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
#endif
	REP(i,4){
		string s;
		cin>>s;
		x[i] = s[0] - 'a';
		y[i] = s[1] - '1';
	}

	if(under(x[3],y[3])){
		bool ch = 1;
		FOR(dx,-1,2)FOR(dy,-1,2){
			int nx = x[3] + dx;
			int ny = y[3] + dy;

			if(nx>=0 && nx<8 && ny>=0 && ny<8){
				if(has(nx,ny)){
					int tx = x[pos];
					int ty = y[pos];
					x[pos] = -10;
					y[pos] = -10;
					if(!under(nx,ny)){
						ch = 0;
					}
					x[pos] = tx;
					y[pos] = ty;
				}else{
					if(!under(nx,ny))
						ch = 0;
				}
			}
		}
		if(ch){
			puts("CHECKMATE");
			return 0;
		}
	}

	puts("OTHER");

	return 0;
}