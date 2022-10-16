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
int n,ans;
char mp[555][555];
int main(){
	n=read();
	FOR(i,1,n) scanf("%s",mp[i]+1);
	FOR(i,2,n-1) FOR(j,2,n-1)
		if(mp[i][j]=='X' && mp[i-1][j-1]=='X' && mp[i-1][j+1]=='X' && mp[i+1][j-1]=='X' && mp[i+1][j+1]=='X') ans++;
	printf("%d\n",ans);
}