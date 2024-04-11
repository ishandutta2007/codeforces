#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
int n,a[maxn],l,r,al,pre;
char ans[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	l=1;r=n;
	while(l<r){
		if(max(a[l],a[r])<=pre) break;
		if(a[l]<a[r]){
			if(a[l]>pre) ans[++al]='L',pre=a[l++];
			else if(a[r]>pre) ans[++al]='R',pre=a[r--];
			else break;
		}
		else if(a[l]>a[r]){
			if(a[r]>pre) ans[++al]='R',pre=a[r--];
			else if(a[l]>pre) ans[++al]='L',pre=a[l++];
			else break;
		}
		else{
			int cl=1;
			FOR(i,l+1,r){
				if(a[i]<=a[i-1]) break;
				cl++;
			}
			int cr=1;
			ROF(i,r-1,1){
				if(a[i]<=a[i+1]) break;
				cr++;
			}
			if(cl<cr){
				FOR(i,1,cr) ans[++al]='R';
				break;
			}
			else{
				FOR(i,1,cl) ans[++al]='L';
				break;
			}
		}
	}
	if(l==r && a[l]>pre) ans[++al]='L';
	printf("%d\n",al);
	FOR(i,1,al) putchar(ans[i]);
}