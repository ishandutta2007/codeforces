#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
using namespace std;
const int INF=0x3f3f3f3f;

int n,ans=INF;

int np[1000001]={1,1},pr[1000001],cnt;
int maxp[1000001];

void init(int num){
	F(i,2,num){
		if(!np[i]) pr[++cnt]=i, maxp[i]=i;
		F(j,1,cnt){
			if(i*pr[j]>num) break;
			np[i*pr[j]]=1;
			maxp[i*pr[j]]=maxp[i];
			if(i%pr[j]==0) break;
		}
	}
}

int main(){
	init(1000000);
	scanf("%d",&n);
	F(i,n-maxp[n]+1,n)
		if(maxp[i]!=i) ans=min(ans,i-maxp[i]+1);
	printf("%d",ans);
	return 0;
}