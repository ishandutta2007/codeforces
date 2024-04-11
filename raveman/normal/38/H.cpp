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

int n,m,g1,g2,s1,s2;
int a[55][55];

pii mn[55];
pii mx[55];

const int inf = 1011111111;


bool u[55][3];
ll d[55][55];

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)REP(j,n) a[i][j]=inf;
	REP(i,m){
		int  x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		a[x][y]=a[y][x]=min(a[x][y],z);
	}
	REP(k,n)REP(i,n)REP(j,n) 
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	REP(i,n){
		REP(j,n)if(i!=j){
			if(mn[i].first==0 || mn[i].first > a[i][j])
				mn[i]=pii(a[i][j],i);
			if(mx[i].first < a[i][j])
				mx[i]=pii(a[i][j],i);
		}
	}

	cin>>g1>>g2>>s1>>s2;

	ll res = 0;
	REP(i,n)REP(j,n)if(i!=j){
		if(mn[i] > mx[j]) continue;

		CL(u,false);
		REP(k,n){
			REP(q,n) if(q!=k)
				if(pii(a[k][q],k) <= mn[i]) u[k][0] = 1;
				else if(pii(a[k][q],k) >= mx[j]) u[k][2] = 1;
				else u[k][1]=1;
		}
		CL(d,0);
		d[0][0]=1;
		
		REP(k,n){
			for(int g = g2; g>=0; g--) for(int s = s2;s>=0;s--)if(d[g][s]){
				if(k==i) d[g+1][s] += d[g][s],d[g][s]=0;
				else if(k==j){}
				else {
					if(u[k][0]) d[g+1][s] += d[g][s];
					if(u[k][1]) d[g][s+1] += d[g][s];

					if(!u[k][2]) d[g][s]=0;
				}
			}
		}
		FOR(g,g1,g2+1)FOR(s,s1,s2+1) if(d[g][s])
			res += d[g][s];
	}
	cout<<res<<endl;

	return 0;
}