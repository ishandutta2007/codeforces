#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int n,k,tl,tmp[maxn];
char s[maxn]; 
void solve(){
	n=read();k=read();
	scanf("%s",s+1);
	bool flag=false;
	FOR(i,1,n) if(s[i]=='W') flag=true; 
	if(!flag) printf("%d\n",max(0,2*k-1));
	else{
		tl=0;
		int cnt=0,cnt2=0;
		bool hhh=false;
		FOR(i,1,n) if(s[i]=='W'){
			if(cnt){
				if(hhh) tmp[++tl]=cnt-1;
				else cnt2+=cnt;
				cnt=0;
			}
			hhh=true;
		}
		else cnt++;
		cnt2+=cnt;
		sort(tmp+1,tmp+tl+1);
		int ans=0;
		FOR(i,1,tl){
			while(k && tmp[i]) ans+=2,k--,tmp[i]--;
			if(k) ans+=3,k--; 
		}
		while(k && cnt2) ans+=2,k--,cnt2--;
		FOR(i,1,n) if(s[i]=='W'){
			ans++;
			if(s[i-1]=='W') ans++; 
		}
		printf("%d\n",ans);
	}
}
int main(){
	int T=read();
	while(T--) solve(); 
}