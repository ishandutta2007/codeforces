#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300030;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
int n,k,p;
ll ans;
map<int,int> cnt;
int main(){
	scanf("%d%d%d",&n,&p,&k);
	FOR(i,1,n){
		int x;
		scanf("%d",&x);
		cnt[(1ll*x*x%p*x%p*x%p-1ll*k*x%p+p)%p]++;
	}
	for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++){
		int x=it->second;
		ans+=1ll*x*(x-1)/2;
	}
	printf("%d\n",ans);
}