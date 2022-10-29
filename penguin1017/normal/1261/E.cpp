#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e3+9;
char ans[N][N];
int a[N],ord[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]),ord[i]=i;
	sort(ord+1,ord+1+n,cmp);
	rep(i,1,n+2)rep(j,1,n+1)ans[i][j]='0';
	rep(i,1,n+1){
		if(a[ord[i]]>i){
			rep(j,1,a[ord[i]]+2){
				if(j==i+1)continue;
				ans[j][ord[i]]='1';
			}
		}
		else{
			rep(j,0,a[ord[i]]){
				ans[i-j][ord[i]]='1';
			}
		}
	}
	int cnt=n;
	rep(i,1,n+1)if(ans[n+1][i]=='1'){
		cnt=n+1;
		break;
	}
	printf("%d\n",cnt);
	rep(i,1,cnt+1)printf("%s\n",ans[i]+1);
}