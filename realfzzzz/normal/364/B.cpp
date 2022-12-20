#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=50+5,maxc=1e4+5;
int n,d,c[maxn];
bitset<maxn*maxc> dp;
int mx[maxn*maxc];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	d=readint();
	dp[0]=1;
	for(int i=0;i<n;i++) dp|=dp<<readint();
	for(int i=1;i<maxn*maxc;i++) mx[i]=dp[i]?i:mx[i-1];
	int cur=0,cnt=0;
	while(mx[cur+d]!=cur){
		cur=mx[cur+d];
		cnt++;
	}
	printf("%d %d\n",cur,cnt);
	return 0;
}