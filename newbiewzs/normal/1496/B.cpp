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
const int N=1e5+55;
int T,n,m;
int a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		map<int,int>ma;
		ma.clear();
		scanf("%d%d",&n,&m);int js=n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			ma[a[i]]=1;
		}
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		int mex=0;
		int maxx=0;
		if(a[1]!=0){
			mex=0;
		}
		else{
			for(int i=2;i<=n;i++){
				if(a[i]!=a[i-1]+1){
					mex=a[i-1]+1;
				}
			}
			if(!mex)mex=a[n]+1;
		}
		if(m==0){
			printf("%d\n",n);
			continue;
		}
		if(mex==0){
			if(ma[ceil(1.0*a[n]/2)])printf("%d\n",n);
			else printf("%d\n",n+1);
		}
		else if(ceil(1.0*(mex+a[n])/2)<=a[n]){
			if(ma[ceil(1.0*(mex+a[n])/2)])printf("%d\n",n);
			else printf("%d\n",n+1);
		}
		else {
			printf("%d\n",n+m);
		}
		for(int i=1;i<=js;i++)a[i]=0;
	}
	return 0;
}