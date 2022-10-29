#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=(int)2e3+9;
int vis[N],x[N],y[N],z[N];
bool check(int a,int b,int c){
	if(c>=min(a,b)&&c<=max(a,b))return 1;
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,1,n+1){
		scanf("%d%d%d",&x[i],&y[i] ,&z[i] );
	} 
	int p1,p2;
	rep(i,1,n+1){
		if(vis[i])continue;
		p1=i;
		rep(j,i+1,n+1){
			if(!vis[j]){
				p2=j;
				break;
			}
		}
		rep(j,p2+1,n+1){
			if(vis[j])continue;
			if(check(x[p1],x[p2],x[j])&&check(y[p1],y[p2],y[j])&&check(z[p1],z[p2],z[j])){
				p2=j;
			}
		}
		printf("%d %d\n",p1,p2);
		vis[p1]=1,vis[p2]=1;
	}
}