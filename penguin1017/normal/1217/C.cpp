#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define lowbit(x) ((x)&(-x)) 
#define pb push_back
using namespace std;
const int N=(int)2e5+9;
int l[N];
char s[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s); 
		int len=strlen(s);
		l[len]=(int)1e9;
		per(i,0,len){
			if(s[i]=='0')l[i]=l[i+1];
			else l[i]=i;
		}
		int ans=0;
		rep(i,0,len){
			int tot=0;
			rep(j,l[i],min(len,l[i]+20)){
				tot=tot*2+s[j]-48;
				if(tot==j-i+1)ans++;
			} 
		}
		printf("%d\n",ans);
	}
}