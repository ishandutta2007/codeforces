#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define maxn 400400
#define debug printf
typedef long long ll;
using namespace std;

int main(){

	int x,y,z,t1,t2,t3;
	scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
	int tel = abs(z-x) * t2 + abs(x-y) * t2 + 3*t3;
	int tst = abs(x-y) * t1;
	if(tst < tel)
		printf("NO\n");
	else
		printf("YES\n");
}