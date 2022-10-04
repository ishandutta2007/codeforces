#include<bits/stdc++.h>
const int mod=1000000007;
#define mul(x,y) ((long long)(x)*(y)%mod)
using namespace std;
int mu(int n){
	int cnt=0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			cnt++;
			n/=i;
			if(n%i==0)return 0;
		}
	}
	if(n>1)cnt++;
	if(cnt%2==0)return 1;
	else return -1;
}
int p2(int e){
	if(!e)return 1;
	int x=p2(e/2);
	x=mul(x,x);
	if(e&1)x=mul(x,2);
	return x;
}
int main(){
	int x,y;scanf("%d%d",&x,&y);
	if(y%x != 0)return puts("0"),0;
	y/=x;
	int ans=0;
	vector<int> D;
	int i;
	for(i=1;i*i<y;i++){
		if(y%i==0)D.push_back(i),D.push_back(y/i);
	}
	if(i*i==y)D.push_back(i);
	for(auto &x:D){
		ans += mul(p2(x-1),mu(y/x));
		if(ans>mod)ans-=mod;
		if(ans<0)ans+=mod;
	}
	printf("%d\n",ans);
}