#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int t,n,m;
char a[maxn],b[maxn];
int main(){
	t=read();
	while(t--){
		scanf("%s",a+1);scanf("%s",b+1);
		n=strlen(a+1);m=strlen(b+1);
		int at,ans=0;
		ROF(i,m,1) if(b[i]=='1'){at=n-(m-i);break;}
		while(a[at]=='0') at--,ans++;
		printf("%d\n",ans);
	}
}