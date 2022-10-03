#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
int a[MN];
char s[MN];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%s",s+1),n=strlen(s+1);
		F(i,1,n)a[i]=a[i-1]+(s[i]=='1');
		F(j,1,18){
			int t=0,k=1<<j;
			F(i,1,j-1)t=t*2+(s[i]=='1');
			F(i,j,n){
				t=t*2-k*(s[i-j]=='1')+(s[i]=='1');
				if(t>=j&&i>=t&&a[i-j]==a[i-t]&&s[i-j+1]=='1')++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}