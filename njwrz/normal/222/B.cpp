#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005];
inline int in(){
    int s=0,f=0;
    char ch=getchar();
    while(!isdigit(ch)) 
    	f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) 
    	s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
    return f?-s:s;
}
inline void out(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) out(x/10);
    putchar(x%10+'0');
}
int main(){
	int k,ti[1005],tj[1005];
	n=in();m=in();k=in();
	for(int i=1;i<=n;i++){
		ti[i]=i;
		for(int j=1;j<=m;j++)a[i][j]=in();
	}
	for(int j=1;j<=m;j++)tj[j]=j;
	char c;
	int x,y;
	for(int i=0;i<k;i++){
		c=getchar();
		x=in();y=in();
		if(c=='c'){
			swap(tj[x],tj[y]);
		}else if(c=='r'){
			swap(ti[x],ti[y]);
		}else out(a[ti[x]][tj[y]]),putchar('\n');
	}
	return 0;
}