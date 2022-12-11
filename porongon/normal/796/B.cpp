#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,tto=b;i<tto;++i)
using namespace std;
typedef long long ll;

int n,m,k;
bool h[1<<20];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	int r=0,f=-1;
	fore(i,0,m){
		int x;
		scanf("%d",&x);x--;
		h[x]=true;
	}
	if(h[0])f=0;
	while(k--){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		int q=-1;
		if(a==r)q=b;
		else if(b==r)q=a;
		if(q>=0){
			r=q;
			if(h[r]&&f<0)f=r;
		}
	}
	if(f>=0)r=f;
	printf("%d\n",r+1);
	return 0;
}