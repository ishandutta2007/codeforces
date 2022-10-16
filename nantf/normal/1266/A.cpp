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
int q,n;
char s[maxn];
int main(){
	q=read();
	while(q--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int sum=0,cnt0=0,cnteven=0;
		FOR(i,1,n){
			sum+=s[i]-'0';
			if(s[i]-'0'==0) cnt0++;
			if((s[i]-'0')%2==0) cnteven++;
		}
		puts(sum%3==0 && cnt0 && cnteven>=2?"red":"cyan");
	}
}