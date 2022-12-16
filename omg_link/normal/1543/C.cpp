#include <stdio.h>
#include <math.h>
#include <iostream>
typedef long double ld;
ld eps = 1e-15;

ld v;

ld search(ld c,ld m,ld p){
	ld ret = 1;
	if(c!=0){
		if(c<=v+eps){
			if(m==0){
				ret += c*search(0,0,1);
			}else{
				ret += c*search(0,m+c/2,p+c/2);
			}
		}else{
			if(m==0){
				ret += c*search(c-v,0,p+v);
			}else{
				ret += c*search(c-v,m+v/2,p+v/2);
			}
		}
	}
	if(m!=0){
		if(m<=v+eps){
			if(c==0){
				ret += m*search(0,0,1);
			}else{
				ret += m*search(c+m/2,0,p+m/2);
			}
		}else{
			if(c==0){
				ret += m*search(0,m-v,p+v);
			}else{
				ret += m*search(c+v/2,m-v,p+v/2);
			}
		}
	}
	return ret;
}

void solve(){
	ld c,m,p;
	std::cin >> c >> m >> p >> v;
	ld ans = search(c,m,p);
	printf("%.8lf\n",(double)ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}