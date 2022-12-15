// 
//	
//		
//
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
#define eef(i,x)for(int i=head[x],y=e[i].to;i;i=e[i].next,y=e[i].to)
int read(){char c=getchar();int d=0,f=1;for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;for(;c>='0'&&c<='9';d=d*10+c-48,c=getchar());return d*f;}
char Read(){char c=getchar();while(c<'0'||c>'9')c=getchar();return c;}
void print(int s){if(!s){putchar('0');return;}if(s<0)putchar('-'),s=-s;int t[20],n=0;while(s)t[++n]=s%10,s/=10;def(i,n,1)putchar(t[i]+'0');}
int getdigit(char c){return (c<'0'||c>'9')?-1e9:(c-'0');}
typedef pair<int,int>PII;
typedef long long LL;
const int N=100001;
int n,m,a[N],ans[N];
int main(){
	n=read();m=read();
	ref(i,1,n)a[i]=read(),a[i]+=a[i-1];
	if(a[n]%m!=0){printf("No\n");return 0;}
	int s=a[n]/m,S=s;
	ref(i,1,n)if(a[i]==S)S+=s,ans[++ans[0]]=i;
	if(S>a[n]){
		printf("Yes\n");
		ans[0]=0;
		ref(i,1,m)printf("%d ",ans[i]-ans[i-1]);
		printf("\n");
	}else printf("No\n");
}