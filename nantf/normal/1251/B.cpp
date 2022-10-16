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
int q,n,cnt[2],len[maxn];
char s[maxn];
int main(){
	q=read();
	while(q--){
		n=read();
		MEM(cnt,0);
		FOR(i,1,n){
			scanf("%s",s+1);
			len[i]=strlen(s+1);
			FOR(j,1,len[i]) cnt[s[j]-'0']++;
		}
		sort(len+1,len+n+1);
		int ans=0,cnt1=0,cnt2=0;
		FOR(i,1,n){
			if(len[i]%2==1) cnt1++;
			cnt2+=len[i]/2;
			if(cnt[0]/2+cnt[1]/2>=cnt2 && cnt[0]+cnt[1]-2*cnt2>=cnt1) ans=max(ans,i);
		}
		printf("%d\n",ans);
	}
}