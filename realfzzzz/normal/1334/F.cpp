#include<algorithm>
#include<vector>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
    int x=0;
    bool f=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-'){
        f=1;
        c=getchar();
    }
	while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f?-x:x;
}
const int maxn=5e5+5;
int n,m,b[maxn],p[maxn];
vector<int> v[maxn];
typedef long long ll;
ll dp[maxn];
bool g[maxn];
ll c[maxn];
inline int lowbit(int x){
	return x&-x;
}
void modify(int x,ll k){
	while(x<=n){
		c[x]+=k;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll s=0;
	while(x>0){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
const ll inf=9e18;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    for(int i=1;i<=n;i++) v[readint()].push_back(i);
    for(int i=1;i<=n;i++) p[i]=readint();
    m=readint();
    for(int i=1;i<=m;i++) b[i]=readint();
    int lst=0;
    for(int i=1;i<=m;i++){
    	lst=upper_bound(v[b[i]].begin(),v[b[i]].end(),lst)-v[b[i]].begin();
    	if(lst==(int)v[b[i]].size()){
    		printf("NO\n");
    		return 0;
		}
		lst=v[b[i]][lst];
	}
	printf("YES\n");
	for(int i=1;i<=n;i++) if(p[i]<0) modify(i,p[i]);
	for(int i=b[m]+1;i<=n;i++) for(int j=0;j<(int)v[i].size();j++){
		int x=v[i][j];
		if(p[x]>0) modify(x,p[x]);
	}
	for(int i=m;i>0;i--){
		for(int j=(int)v[b[i]].size()-1;j>=0;j--){
			int x=v[b[i]][j];
			g[x]=0;
			dp[x]=inf;
			if(i==m){
				g[x]=1;
				dp[x]=query(n)-query(x);
			}
			else{
				int y=upper_bound(v[b[i+1]].begin(),v[b[i+1]].end(),x)-v[b[i+1]].begin();
				if(y<(int)v[b[i+1]].size()){
					y=v[b[i+1]][y];
					if(g[y]){
						g[x]=1;
						dp[x]=min(dp[x],dp[y]+query(y-1)-query(x));
					}
				}
			}
		}
		if(i==0) for(int j=1;j<=b[i];j++) for(int k=0;k<(int)v[j].size();k++){
			int x=v[j][k];
			if(p[x]>0) modify(x,p[x]);
		}
		else for(int j=b[i-1]+1;j<=b[i];j++) for(int k=0;k<(int)v[j].size();k++){
			int x=v[j][k];
			if(p[x]>0) modify(x,p[x]);
		}
		for(int j=(int)v[b[i]].size()-1;j>=0;j--){
			int x=v[b[i]][j];
			if(j<(int)v[b[i]].size()-1){
				int y=v[b[i]][j+1];
				if(g[y]){
					g[x]=1;
					dp[x]=min(dp[x],dp[y]+query(y-1)-query(x-1));
				}
			}
		}
	}
	printf("%lld\n",dp[v[b[1]][0]]+query(v[b[1]][0]-1));
    return 0;
}