#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,lpos,rpos,lpos2,rpos2,ans;
char str[555555];
int main(){
	scanf("%s",str+1);n=strlen(str+1);
	FOR(i,1,n) if(str[i]=='['){lpos=i;break;}
	ROF(i,n,1) if(str[i]==']'){rpos=i;break;}
	if(!lpos || !rpos || lpos>rpos) return puts("-1"),0;
	FOR(i,lpos,rpos) if(str[i]==':'){lpos2=i;break;}
	ROF(i,rpos,lpos) if(str[i]==':'){rpos2=i;break;}
	if(!lpos2 || !rpos2 || lpos2>=rpos2) return puts("-1"),0;
	ans=4;
	FOR(i,lpos2,rpos2) if(str[i]=='|') ans++;
	printf("%d\n",ans);
}