#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 1000005
#define ll long long
#define mod 998244353
int n,m,q,k;
char str[MN],cho[MN],mid;
int main(){
	scanf("%s",str+1),n=strlen(str+1);
	int l=1,r=n;
	while(l<=r){
		if(r-l+1<=3){mid=str[l];break;}
		else{
			if(str[l]==str[r])cho[++k]=str[l],++l,--r;
			else if(str[l+1]==str[r])cho[++k]=str[r],l+=2,--r;
			else if(str[l]==str[r-1])cho[++k]=str[l],++l,r-=2;
			else cho[++k]=str[l+1],l+=2,r-=2;
		}
	}
	printf("%s",cho+1);
	if(mid)printf("%c",mid);
	reverse(cho+1,cho+k+1);
	printf("%s",cho+1);
	return 0;
}