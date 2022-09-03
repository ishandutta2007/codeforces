#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=23;
int n,m;
struct s{
	   int k,v;
	   s():v(),k(0){}
	   s(int k,int v):v(v),k(k){}
	   bool operator < (const s&t)const {return v>t.v;}
};
priority_queue<s> pq;
int a[maxn],b[maxn];
int mark[maxn];
ll t[maxn];
ll res;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",a+i);
	for(i=0;i<n;i++)scanf("%d",b+i);
	int depth=0;
	ll cost=0;
	ll tmp=0;
	for(i=0,j=0;i<n*3;i++,j=(j<n-1)?(j+1):0){
		--depth;
		if(!mark[j]++)pq.push(s(j,a[j]-b[j]));
		cost+=b[j];
		if(depth<0){
					s t=pq.top();
					if(!--mark[t.k])pq.pop();
					cost+=t.v;
					depth+=2;
		}
		
		if((i+1)%n==0){
					   t[i/n]=cost;
		}
	}
	--m;
	res+=(-t[0]+t[2])*(m/2);
	res+=t[1];
	printf("%I64d\n",res);
	return 0;
}