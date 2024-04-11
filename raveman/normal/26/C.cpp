#pragma comment(linker, "/STACK:136777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
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

int n,m,a,b,c;
int r[111][111];
int z[111][111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	cin>>n>>m>>a>>b>>c;
	if((n*m)%2==1) puts("IMPOSSIBLE");
	else{
		int q = 0;
		REP(i,n) REP(j,m)if(!r[i][j]){
			if(i+1<n && j+1<m && c){
				c--;
				q++;
				r[i][j]=r[i+1][j]=r[i][j+1]=r[i+1][j+1]=q;
			}
		}
		if(n%2==1){
			REP(i,n) REP(j,m)if(!r[i][j]){
				if(i+1<n){
					if(b>=2) {q++;r[i][j]=r[i+1][j]=q;q++;r[i][j+1]=r[i+1][j+1]=q;b-=2;}
					else if(a>=2) {q++;r[i][j]=r[i][j+1]=q;q++;r[i+1][j]=r[i+1][j+1]=q,a-=2;}
				}else{
					if(a){
						q++;
						r[i][j]=r[i][j+1]=q;
						a--;
					}
				}
			}
		}else if(m%2==1){
			REP(i,n) REP(j,m)if(!r[i][j]){
				if(j+1<m){
					if(a>=2) {q++;r[i][j]=r[i][j+1]=q;q++;r[i+1][j]=r[i+1][j+1]=q,a-=2;}
					else if(b>=2) {q++;r[i][j]=r[i+1][j]=q;q++;r[i][j+1]=r[i+1][j+1]=q;b-=2;}
				}else{
					if(b){
						q++;
						r[i][j]=r[i+1][j]=q;
						b--;
					}
				}
			}
		}else{
			REP(i,n) REP(j,m)if(!r[i][j]){
				if(a>=2) {q++;r[i][j]=r[i][j+1]=q;q++;r[i+1][j]=r[i+1][j+1]=q,a-=2;}
				else if(b>=2) {q++;r[i][j]=r[i+1][j]=q;q++;r[i][j+1]=r[i+1][j+1]=q;b-=2;}
			}
		}
		bool h = 1;
		REP(i,n)REP(j,m)if(!r[i][j]) h=0;
		if(h){
			REP(i,n){
				
				REP(j,m){
						int rr = 1;
					if(!z[i][j]){
						set<int> f;
						FOR(dx,-1,3) FOR(dy,-1,3){
							int x = i + dx;
							int y = j + dy;
							if(x>=0 && x<n && y>=0 && y<m && z[x][y])
								f.insert(z[x][y]);
						}
						while(f.count(rr)) rr++;

						FOR(dx,0,2) FOR(dy,0,2){
							int x = i + dx;
							int y = j + dy;
							if(x>=0 && x<n && y>=0 && y<m && r[x][y]==r[i][j])
								z[x][y]=rr;
						}
					}

					if(z[i][j]) rr=z[i][j];
					printf("%c",char(rr+'a'-1));

				}

				puts("");
			}
		}else puts("IMPOSSIBLE");
	}

	return 0;
}