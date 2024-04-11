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
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,cnt[26],ans;
char s[25];
int main(){
	n=read();
	FOR(i,1,n) scanf("%s",s+1),cnt[s[1]-'a']++;
	FOR(i,0,25){
		int x=cnt[i]/2,y=cnt[i]-x;
		ans+=x*(x-1)/2+y*(y-1)/2;
	}
	printf("%d\n",ans);
}