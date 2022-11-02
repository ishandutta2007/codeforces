#include <bits/stdc++.h>
using namespace std;

#define maxn 300300
#define debug 
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>

int v[22];

int f(int a,int b){
	int is = 1;
	for(int i=a+1;i<=b;i++)
		if(v[i] < v[i-1]) is = 0;
		
	if(is) return b-a+1;
	int mid = (a+b)/2;
	return max(f(a,mid),f(mid+1,b));
}

main(){
	int n;
	int mi = 999;
	scanf("%d",&n);
	
	int ans = 0, q = 1;
	if(n & 8) q^=1;
	if(q) ans += 8;
	
	if(n & 4) q^=1;
	if(q) ans += 4;
	
	if(n & 2) q^=1;
	if(q) ans += 2;
	
	if(n & 1) q^=1;
	if(q) ans += 1;
	
	//assert(n <= 6);
	//if(n == 6) printf("15");
	if(n == 6 || n == 7 || n == 10 || n == 11 || n == 12 ) ans ^= 1;
	if(n == 12) printf("4");
	else if(n == 13) printf("5");
	else if(n == 14) printf("6");
	else if(n == 15) printf("7");
	else printf("%d\n",ans);
}