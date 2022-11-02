#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define maxn 400400
#define debug printf
typedef long long ll;
using namespace std;

int main(){

	map<int,int> has;
	
	int n;
	scanf("%d",&n);
	int mex =0 ;
	
	for(int i=1;i<=n;i++){
		
		int x;
		scanf("%d",&x);
		if(x > mex){
			printf("%d\n",i);
			return 0;		
		}

		has[x] = 1;
		while(has[mex]) mex++;
	
	}
	
	printf("-1\n");
}