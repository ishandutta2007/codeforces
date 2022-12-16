#include <stdio.h>
#include <unordered_map>
#include <vector>
#define MN 200000
#define MA 200000
const int mod = 1000000007;

int n,q,ans=1;
std::vector<int> v[MA+5];
std::unordered_map<int,int> a[MN+5];

void ppush(int p,int c){
	if(v[p].size()<c)
		v[p].push_back(0);
	c--;
	if(++v[p][c]==n)
		ans = (1ll*ans*p)%mod;
}

void push(int id,int x){
	for(int i=2;i*i<=x;i++){
		while(x%i==0){
			ppush(i,++a[id][i]);
			x /= i;
		}
	}
	if(x!=1)
		ppush(x,++a[id][x]);
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		push(i,x);
	}
	while(q--){
		int i,x;
		scanf("%d%d",&i,&x);
		push(i,x);
		printf("%d\n",ans);
	}
}