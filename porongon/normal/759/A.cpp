#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int p[200005];
bool vis[200005];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",p+i),p[i]--;
	int nb=0;
	fore(i,0,n){
		int b;
		scanf("%d",&b);
		if(b)nb++;
	}
	int nc=0;
	fore(i,0,n){
		if(!vis[i]){
			nc++;
			for(int j=i;!vis[j];j=p[j])vis[j]=true;
		}
	}
	int r=0;
	if(nc>1)r+=nc;
	if(nb%2==0)r++;
	printf("%d\n",r);
	return 0;
}