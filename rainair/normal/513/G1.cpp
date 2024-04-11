#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

double f[2][35][35];
int a[205],n,k;

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",a+i);
	int now = 0;
	FOR(i,1,n) FOR(j,i+1,n) if(a[i] > a[j]) f[now][i][j] = 1;
	FOR(i,1,k){
		CLR(f[now^1],0);
		FOR(x,1,n){
			FOR(y,x+1,n){
				double p = 1.0/(n*(n+1)/2);
				FOR(l,1,n){
					FOR(r,l,n){
						int tx = x,ty = y;
						if(l <= x && x <= r) tx = r-(x-l);
						if(l <= y && y <= r) ty = r-(y-l);
						if(tx > ty) std::swap(tx,ty);
						if(l <= x && y <= r){
							f[now^1][tx][ty] += (1-f[now][x][y])*p;
						}
						else{
							f[now^1][tx][ty] += f[now][x][y]*p;
						}
					}
				}
			}
		}
		now ^= 1;
	}
	double ans = 0;
	FOR(i,1,n){
		FOR(j,i+1,n){
			ans += f[now][i][j];
		}
	}
	printf("%.10f\n",ans);
	return 0;
}
/*
 (u,v)
 f[i][a][b] i,(u,v)
 
*/