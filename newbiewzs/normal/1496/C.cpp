#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<cmath>
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
#define pl pair<int,long long>
//#define int long long
using namespace std;
typedef long long ll;
const int N=3e5+55;
int T,n,m,a[N],b[N];
double dis(int x,int y,int dx,int dy){
	return sqrt(1.0*(x-dx)*(x-dx)+1.0*(y-dy)*(y-dy));
}
int top1,top2,x,y;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int top1=0,top2=0;
		for(int i=1;i<=2*n;i++){
			scanf("%d%d",&x,&y);
			if(!x)a[++top1]=abs(y);
			else b[++top2]=abs(x);
		}
		int aa=0;
		for(int i=1;i<=199;i++)aa++;
		int ssx=1134432,mzj=19260817;
		aa=min(ssx,mzj);
		sort(a+1,a+1+top1);
		sort(b+1,b+1+top2);
		double ans=0;
		for(int i=1;i<=n;i++)
		{
		ans+=sqrt(1.0*a[i]*a[i]+1.0*b[i]*b[i]);
		}
		printf("%.15lf\n",ans);
	}
	return 0;
}