#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
namespace ACAM
{
	#define SUMLEN 5000
	struct Node {
	    int next[10];
	    int terminal,fail;
	}node[SUMLEN];
	int top;
	int newnode() {
	    top++;
	    for(int i=0;i<10;i++)node[top].next[i]=0;
	    node[top].terminal=node[top].fail=0;
	    return top;
	}
	void init(){top=-1;newnode(); newnode();}
	void add(int a[],int len) {
	    int x=1;
	    rep(i,len) {
	        int ind=a[i];
	        if (!node[x].next[ind])
	            node[x].next[ind]=newnode();
	        x=node[x].next[ind];
	    }
	    node[x].terminal=1;
	}
	int q[SUMLEN],head,tail;
	int trans[SUMLEN][10];
	void build() {
	    head=0,tail=1; q[1]=1;
	    while (head!=tail) {
	        int x=q[++head];
	        node[x].terminal|=node[node[x].fail].terminal;
	        for(int i=0;i<10;i++)
	            if (node[x].next[i]) {
	                if (x==1)node[node[x].next[i]].fail=1;
	                else {
	                    int y=node[x].fail;
	                    while (y) {
	                        if (node[y].next[i]) {
	                            node[node[x].next[i]].fail=node[y].next[i];
	                            break;
	                        }
	                        y=node[y].fail;
	                    }
	                    if (!node[node[x].next[i]].fail)node[node[x].next[i]].fail=1;
	                }
	                q[++tail]=node[x].next[i];
	            }
	    }
	    for(int i=1;i<=top;i++)
	        for(int j=0;j<10;j++){
	            int now=i;
	            while (now!=0 && node[now].next[j]==0)now=node[now].fail;
	            if (now!=0)now=node[now].next[j]; else now=1;
	            trans[i][j]=now;
	        }
	}
	int dp[2][SUMLEN];
	void update(int&x,int y){if(x<y)x=y;}
	int solve(char *s)
	{
		int len=strlen(s);
		rep(i,top)dp[0][i]=-100*len;
		dp[0][1]=0;
		for(int i=0;i<len;i++)
		{
			rep(j,top)dp[(i&1)^1][j]=dp[i&1][j];
			rep(j,top)if(!node[trans[j][s[i]-'0']].terminal)update(dp[(i&1)^1][trans[j][s[i]-'0']],dp[i&1][j]+1);
		}
		int ans=0;
		rep(i,top)update(ans,dp[len&1][i]);
		return len-ans;
	}
}
int f[21],cnt,x;
bool ok[1<<20];
int a[3010],b[30];
char s[1010];
int main()
{
	scanf("%s",s);
	scanf("%d",&x);
	rep(i,x-1)if(x%i==0)f[++cnt]=i;
	rep(i,(1<<(x-1)))
	{
		int msk=(i-1)|(1<<(x-1));
		rep(j,cnt)
		{
			if(ok[msk])break;
			if(msk&(1<<(f[j]-1))){ok[msk]=1;break;}
			rep(k,x-f[j])if((msk&(1<<(k-1)))&&(msk&(1<<(k+f[j]-1)))){ok[msk]=1;break;}
		}
	}
	int tot=0;
	rep(i,(1<<(x-1)))if(!ok[(i-1)|(1<<(x-1))])a[++tot]=(i-1)|(1<<(x-1));
	ACAM::init();
	rep(i,tot)
	{
		int len=0;
		rep(j,x)if(a[i]&(1<<(j-1)))b[++len]=j;
		for(int j=len;j;j--)b[j]-=b[j-1];
		bool flag=1;
		rep(j,len)if(b[j]>=10){flag=0;break;}
		if(flag)ACAM::add(b,len);
	}
	ACAM::build();
	printf("%d\n",ACAM::solve(s));
    return 0;
}