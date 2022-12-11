#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,tto=b;i<tto;++i)
using namespace std;
typedef long long ll;

int n,m,k;

int main(){
	scanf("%d%d%d",&n,&m,&k);m--;
	int r=123123;
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		if(x&&x<=k)r=min(r,abs(i-m));
	}
	printf("%d\n",r*10);
	return 0;
}