#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,k;
char s[200005];
int q[200005],t,a[200005];
int v[200005];

int main(){
	scanf("%d%d%s",&n,&k,s+1);
	int x=(n-k)/2;
	F(i,1,n){
		if(s[i]=='(') q[++t]=i;
		else a[q[t]]=i, a[i]=q[t--];
	}
	F(i,1,n){
		if(s[i]=='('&&x) v[a[i]]=1, --x;
		else {
			if(!v[i])
				putchar(s[i]);
		}
	}
	return 0;
}