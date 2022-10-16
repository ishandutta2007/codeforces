#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=155555;
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
int t,n,ans[maxn],al;
bool re[maxn];
char s[maxn];
int main(){
	t=read();
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		FOR(i,1,n) re[i]=false;
		al=0;
		FOR(i,2,n-1){
			if(s[i-1]=='t' && s[i]=='w' && s[i+1]=='o'){
				ans[++al]=i;
				re[i]=true;
			}
			else if(i>=2 && i<=n-2 &&  s[i-2]=='t' && s[i-1]=='w' && s[i]=='o' && s[i+1]=='n' && s[i+2]=='e'){
				if(re[i-1]) re[i-1]=false,al--;
				ans[++al]=i;
				re[i]=true;
			}
			else if(s[i-1]=='o' && s[i]=='n' && s[i+1]=='e'){
				if(re[i-1]) continue;
				ans[++al]=i;
				re[i]=true;
			}
		}
		printf("%d\n",al);
		FOR(i,1,al) printf("%d ",ans[i]);
		puts("");
	}
}