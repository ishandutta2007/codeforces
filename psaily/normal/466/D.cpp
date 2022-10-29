#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define gcd __gcd

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=2005;
const int mod=1e9+7;

int n,h;
ll ans=1,cnt;
int A[maxn],B[maxn];

int main(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),A[i]=h-A[i];
		for(int i=1;i<=n+1;i++)B[i]=A[i]-A[i-1];
	for(int i=1;i<=n+1;i++){// i <-> i-1
		if(B[i]==1){
			cnt++;			
		}else if(B[i]==0){
			ans*=(cnt+1);
		}else if(B[i]==-1){
			ans*=cnt;
			cnt--;
		}else{ans=0;break;}
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}