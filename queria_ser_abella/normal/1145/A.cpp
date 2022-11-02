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
	for(int i=0;i<n;i++)
		scanf("%d",v+i);
	printf("%d\n",f(0,n-1));
}