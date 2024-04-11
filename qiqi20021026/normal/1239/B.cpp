#include<bits/stdc++.h>

using namespace std;

#define N 320000

int n,a[N],b[N],mn,cnt,ans,cyc,l,r;
char s[N];

int main(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;++i){
		a[i]=s[i]=='('?1:-1;
		b[i]=b[i-1]+a[i];
		mn=min(mn,b[i]);
	}
	if (b[n]!=0){
		puts("0");
		puts("1 1");
		return 0;
	}
	for (int i=1;i<=n;++i){
		if (b[i]==mn){
			cyc=i;
			rotate(a+1,a+i+1,a+n+1);
			for (int j=1;j<=n;++j) b[j]=b[j-1]+a[j];
			break;
		}
	}
	for (int i=1;i<=n;++i){
		if (b[i]==0) ++cnt;
	}
	ans=cnt; l=r=1;
	for (int i=1;i<=n;++i){
		if (a[i]==1){
			int j=i,sum=0;
			for (;j<=n;++j){
				if (a[j]==-1){
					int tmp=cnt+sum;
					if (tmp>ans){
						ans=tmp;
						l=i; r=j;
					}
				}
				if (b[j]<=1){
					break;
				}
				sum+=b[j]==2;
			}
			i=j;
		}
	}
	for (int i=1;i<=n;++i){
		if (a[i]==1){
			int j=i,sum=0;
			for (;j<=n;++j){
				if (a[j]==-1){
					int tmp=sum;
					if (tmp>ans){
						ans=tmp;
						l=i; r=j;
					}
				}
				if (b[j]==0){
					break;
				}
				sum+=b[j]==1;
			}
			i=j;
		}
	}
	printf("%d\n%d %d\n",ans,(l+cyc+n-1)%n+1,(r+cyc+n-1)%n+1);
	
	return 0;
}