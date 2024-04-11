#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int x[100005];
int n;
ll s[100005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	sort(x,x+n);
	s[0]=0;
	fore(i,0,n){
		s[i+1]=s[i]+x[i];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int a;
		scanf("%d",&a);
		int r=upper_bound(x,x+n,a)-x;
		printf("%d\n",r);
	}
	return 0;
}