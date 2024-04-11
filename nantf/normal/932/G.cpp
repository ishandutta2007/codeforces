#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=1000000007;
#define PB push_back
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
int n,f[maxn];
char s[maxn];
namespace PAM{
	int cnt,cur,lst,fail[maxn],len[maxn],s[maxn],ch[maxn][26],at[maxn];
	int dif[maxn],to[maxn],sum[maxn][2];
	inline int newnode(int l){
		len[cnt]=l;
		return cnt++;
	}
	void init(){
		newnode(0);newnode(-1);
		fail[0]=1;
	}
	int jump(int p){
		while(cur-len[p]-1<1 || s[cur]!=s[cur-len[p]-1]) p=fail[p];
		return p; 
	}
	void extend(int c){
		s[++cur]=c;
		int tmp=jump(lst);
		if(!ch[tmp][c]){
			int now=newnode(len[tmp]+2);
			fail[now]=ch[jump(fail[tmp])][c];
			ch[tmp][c]=now;
		}
		lst=ch[tmp][c];
		at[cur]=lst;
	}
	void work(){
		FOR(i,2,cnt){
			dif[i]=len[i]-len[fail[i]];
			if(fail[i]<=1 || dif[i]!=dif[fail[i]]) to[i]=i;
			else to[i]=to[fail[i]];
		}
	}
	int calc(int i){
		int p=at[i],ans=0;
		while(p>1){
			if(to[p]!=p){
				sum[p][0]=sum[fail[p]][dif[p]&1];
				sum[p][1]=sum[fail[p]][(dif[p]&1)^1];
			}
			else sum[p][0]=sum[p][1]=0;
			(sum[p][len[to[p]]&1]+=f[i-len[to[p]]])%=mod;
//			printf("sum[%d][0]=%d,sum[%d][1]=%d,len[%d]=%d,fa[%d]=%d,to[%d]=%d\n",p,sum[p][0],p,sum[p][1],p,len[p],p,fail[p],p,to[p]);
			(ans+=sum[p][0])%=mod;
//			printf("add %d\n",p);
			p=fail[to[p]];
		}
		return ans;
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	PAM::init();
	FOR(i,1,n/2){
		PAM::extend(s[i]-'a');
		PAM::extend(s[n-i+1]-'a');
	}
	PAM::work();
	f[0]=1;
	FOR(i,1,n) f[i]=PAM::calc(i);
	printf("%d\n",f[n]);
}