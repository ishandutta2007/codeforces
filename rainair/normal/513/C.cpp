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

const int MAXN = 10000+5;
int l[MAXN],r[MAXN],n;
int L[MAXN],R[MAXN];
long double pro[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d",l+i,r+i);
	/*
	
	 >=x   >=x 
	>=x01
	*/
	FOR(x,1,10000){
		pro[x] = 1;
		//  0 
		long double t = 1;
		FOR(i,1,n){
			if(l[i] >= x) t = 0;
			else t = t*(std::min(x,r[i]+1)-l[i])/(r[i]-l[i]+1);
		}
		pro[x] -= t;
		//  1 
		FOR(i,1,n){ // x
			t = 1;
			FOR(j,1,n){
				if(i == j){
					if(r[j]-x+1 <= 0) t = 0;
					else t = t*(r[j]-std::max(x,l[j])+1)/(r[j]-l[j]+1);
				}
				else{
					if(x-l[j] <= 0) t = 0;
					else t = t*(std::min(x,r[j]+1)-l[j])/(r[j]-l[j]+1);
				}
			}
			pro[x] -= t;
		}
	}
	long double ans = 0;
	FOR(x,1,10000) ans += (pro[x]-pro[x+1])*x;//,printf("%.10f\n",(double)(pro[x]-pro[x+1]));
	printf("%.10f\n",(double)ans);
	return 0;
}