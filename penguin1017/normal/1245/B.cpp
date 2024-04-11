#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
const int N=105;
char s[N],ans[N];
int a,b,c;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d%d%d%d",&n,&a,&b,&c);
		scanf("%s",s);
		int tot=0;
		ans[n]=0;
		rep(i,0,n){
			ans[i]=0;
			if(s[i]=='R'&&b)ans[i]='P',b--,tot++;
			if(s[i]=='P'&&c)ans[i]='S',c--,tot++;
			if(s[i]=='S'&&a)ans[i]='R',a--,tot++; 
		}
		if(tot*2>=n){
			printf("YES\n");
			rep(i,0,n){
				if(!ans[i]){
					if(a){
						ans[i]='R';
						a--;
						continue;
					}
					if(b){
						ans[i]='P';
						b--;
						continue;
					}
					if(c){
						ans[i]='S';
						c--;
						continue;
					}
				}
			}
			printf("%s\n",ans);
		}
		else printf("NO\n");
	}
}