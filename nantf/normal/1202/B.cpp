#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2000200,mod=998244353;
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
int n,ok[10][10][111],okk[10][10][10];
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	MEM(ok,0x3f);MEM(okk,0x3f);
	FOR(i,0,9) FOR(j,0,9){
		ok[i][j][0]=0;
		FOR(l,0,99){
			ok[i][j][l+i]=min(ok[i][j][l+i],ok[i][j][l]+1);
			ok[i][j][l+j]=min(ok[i][j][l+j],ok[i][j][l]+1);
		}
		FOR(k,1,110) okk[i][j][k%10]=min(okk[i][j][k%10],ok[i][j][k]);
		if(!i || !j) okk[i][j][0]=1;
//		FOR(k,0,9) printf("ok[%d][%d][%d]=%d\n",i,j,k,ok[i][j][k]);
	}
	FOR(i,0,9){
		FOR(j,0,9){
			int ans=0;
			bool flag=true;
			FOR(k,2,n){
				int x=okk[i][j][(s[k]-s[k-1]+10)%10];
				x=max(x-1,0);
				if(x>=1e9){printf("-1 ");flag=false;break;}
				ans+=x;
			} 
			if(flag) printf("%d ",ans);
		}
		puts("");
	}
}