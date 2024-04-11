#include<bits/stdc++.h>
using namespace std;
int n,d,m;
int main(){
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(y>=abs(d-x) && y<=n-abs(n-d-x)) puts("YES");
		else puts("NO");
	}
}