#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define lowbit(x) ((x)&(-x)) 
#define pb push_back
using namespace std;
void upd(int &a,int b){
	if(a<b)a=b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,x,maxn=0,maxn2=0;
		scanf("%d%d",&n,&x);
		rep(i,0,n){
			int d,h;;
			scanf("%d%d",&d,&h);
			upd(maxn,d);
			upd(maxn2,d-h);
		} 
		int ans=0;
		x-=maxn;
		ans++;
		if(x<=0){
			printf("%d\n",ans);
			continue;
		}
		if(maxn2<=0){
			printf("-1\n");
			continue;
		}
		ans+=x/maxn2;
		if(x%maxn2)ans++;
		printf("%d\n",ans);
	}
}