#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define For(i,a) for(int i=1;i<=a;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dFor(i,a) for(int i=a;i>=1;--i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
int n,m,k;
int a[100001];
char str[105][105];
int l[105], p[105];
bool cmp(int i,int j){return l[i]<l[j];}
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%s",str[i]), l[i]=strlen(str[i]), p[i]=i;
	sort(p+1,p+n+1,cmp);
	F(i,2,n){
		int ok=0;
		F(j,0,l[p[i]]-l[p[i-1]]){
			int oo=1;
			F(k,0,l[p[i-1]]-1){
				if(str[p[i-1]][k]!=str[p[i]][j+k]) oo=0;
			}
			if(oo) ok=1;
		}
		if(!ok) {puts("NO"); return 0;}
	}
	puts("YES");
	F(i,1,n) printf("%s\n",str[p[i]]);
	return 0;
}