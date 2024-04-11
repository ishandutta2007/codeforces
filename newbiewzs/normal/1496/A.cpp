#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
#define pl pair<int,long long>
//#define int long long
using namespace std;
typedef long long ll;
int T,n,m;
char a[200];
int f[200][100];
bool check(int l,int r,int L,int R){
	if(r>=L)return 0;
	int top=R;
	for(int i=l;i<=r;i++){
		if(a[top]!=a[i]){
			return 0;
		}
		top--;
	}
	return 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		
		bool flag=0;
		scanf("%s",a+1);
		if(m==0){
			puts("YES");
			continue;
		}
		f[0][0]=1;
		for(int i=1;i<=n/2;i++){
			for(int k=0;k<i;k++){
				for(int j=0;j<m;j++){
					if(check(k+1,i,n-i+1,n-k) and f[k][j]){
						f[i][j+1]=1;
					}
				}
			}
		}
		if(n%2==0){
			for(int k=1;k<n/2;k++){
				if(f[k][m])flag=1;
			}
		}
		if(n%2==1){
			for(int k=1;k<=n/2;k++){
				if(f[k][m])flag=1;
			}
		}
		memset(f,0,sizeof(f));
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}