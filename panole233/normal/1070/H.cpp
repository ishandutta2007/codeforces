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
const int N=10001;
char s[N][10];
int n,q,r[10],ct[360001];char str[10];
int cnt; pair<LL,int> t[360001];
int getrk(char c){
	if(c=='.')return 1;
	if(c>='0'&&c<='9')return c-'0'+2;
	if(c>='a'&&c<='z')return c-'a'+12;
}
int main(){
	n=read();
	ref(i,1,n){
		scanf("%s",s[i]+1);
		int len=strlen(s[i]+1);
		ref(x,1,len)r[x]=getrk(s[i][x]);
		ref(x,1,len){
			LL S=0;
			ref(y,x,len){
				S=S*40+r[y];
				t[++cnt]=mp(S,i);
			}
		}
	}
	sort(t+1,t+cnt+1);
	ref(i,1,cnt) if(i==1||t[i].fi!=t[i-1].fi)ct[i]=1;else ct[i]=ct[i-1]+(t[i]!=t[i-1]);
	q=read();
	ref(i,1,q){
		scanf("%s",str+1);
		int len=strlen(str+1);
		LL S=0;
		ref(i,1,len)S=S*40+getrk(str[i]);
		int L=1,R=cnt;
		while(L<R){
			int mid=(L+R+1)>>1;
			if(t[mid].fi>S)R=mid-1;else L=mid;
		}
		if(t[L].fi==S){
			printf("%d ",ct[L]);int id=t[L].se;
			ref(i,1,(int)strlen(s[id]+1))putchar(s[id][i]);
			putchar('\n');
		}else printf("0 -\n");
	}
}