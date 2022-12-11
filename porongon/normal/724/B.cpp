#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m;
int x[32][32];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		fore(j,0,m){
			scanf("%d",&x[i][j]);
		}
	}
	bool can=true;
	fore(i,0,n){
		int r=0;
		fore(j,0,m){
			r+=x[i][j]!=j+1;
		}
		can=can&&r<=2;
	}
	if(can){
		puts("YES");
		return 0;
	}
	fore(j0,0,m){
		fore(j1,j0+1,m){
			fore(i,0,n)swap(x[i][j0],x[i][j1]);
			bool can=true;
			fore(i,0,n){
				int r=0;
				fore(j,0,m){
					r+=x[i][j]!=j+1;
				}
				can=can&&r<=2;
			}
			if(can){
				puts("YES");
				return 0;
			}
			fore(i,0,n)swap(x[i][j0],x[i][j1]);
		}
	}
	puts("NO");
	return 0;
}