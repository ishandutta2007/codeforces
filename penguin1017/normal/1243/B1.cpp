#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
using namespace std;
const int N=(int)1e5+9;
char s[N],t[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		scanf("%s",t);
		int p1,p2,flag=0,tot=0;
		rep(i,0,n){
			if(s[i]!=t[i]){
				p1=i;
				flag=1;
				tot++;
				break;
			}
		}
		if(!flag){
			printf("Yes\n");
			continue;
		}
		rep(i,p1+1,n){
			if(s[i]!=t[i]){
				p2=i;
				tot++;
			}
		}
		if(tot==1||tot>=3){
			printf("No\n");
			continue;
		}
		if(s[p1]==s[p2]&&t[p1]==t[p2])printf("Yes\n");
		else printf("No\n");
	}
 }