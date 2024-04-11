#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a,qwer=n;i<qwer;i++)
#define pb push_back
#define snd second
#define fst first
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

pair<int,int> x[300005];
int r[300005];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int k;
		scanf("%d",&k);
		x[i]=mp(k,i);
	}
	sort(x,x+n);
	int q=1;
	fore(i,0,n){
		r[x[i].snd]=max(x[i].fst,q);
		q=r[x[i].snd]+1;
	}
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",r[i]);
	}
	puts("");
	return 0;
}