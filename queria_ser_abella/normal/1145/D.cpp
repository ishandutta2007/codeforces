#include <bits/stdc++.h>
using namespace std;

#define maxn 300300
#define debug 
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>

main(){
	int n;
	int mi = 999;
	scanf("%d",&n);
	int r = 0;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		mi = min(mi,a);
		if(i == 2) r = a;
	}
	r ^= mi;
	printf("%d\n",r+2);
}