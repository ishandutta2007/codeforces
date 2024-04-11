#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int llint;

int mx = -1;
int s,k,n;
llint t;
int lim;
int mi = 1000000005;

int g[300005];
int cara[300005];
int carb[300005];

int c(int x){
	llint sol = 0;
	int last = 0;
	for(int i = 0;i<k+1;i++){
		int z = g[i] - last;
		if(z > x){
			return 0;
		}
		else if(x/2 >= z){
			sol += z;
		}
		else{
			sol += x-z + (z-(x-z))*2;
		}
		last = g[i];
	}
//	printf("%d => %d\n",x,sol);
	return sol <= t;
}

void bin(int lo,int hi){
	int mid = (lo+hi)/2;
	if(c(mid)){
		mi = min(mid,mi);
		bin(lo,mid);	
	}
	else if(lo+1 == hi) return;
	else{
		bin(mid,hi);
	}
}



int main(){
	scanf("%d %d %d %I64d\n",&n,&k,&s,&t);
	for(int i = 0;i<n;i++){
		scanf("%d %d",&cara[i],&carb[i]);
	}
	for(int i = 0;i<k;i++) scanf("%d",&g[i]);
	g[k] = s;
	sort(g,g+k+1);
	bin(0,1000050000);
	//printf("%d\n",mi);
	for(int i = 0;i<n;i++){
		if(carb[i] < mi) continue;
		if(mx == -1 || cara[i] < mx) mx = cara[i];
	}
	printf("%d\n",mx);
	
}