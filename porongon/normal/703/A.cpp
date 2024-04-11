#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,a,b;

int main(){
	scanf("%d",&n);
	while(n--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)a++;
		else if(y>x)b++;
	}
	if(a>b)puts("Mishka");
	else if(b>a)puts("Chris");
	else puts("Friendship is magic!^^");
	return 0;
}