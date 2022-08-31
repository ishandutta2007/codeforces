#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
bool vis[500005];
vector<int> ans;

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=3*n;i++) vis[i]=0;
		int x,y;
		ans.clear();
		for(int i=1;i<=m;i++){
			x=readint(); y=readint();
			if(!vis[x]&&!vis[y]) vis[x]=true,vis[y]=true,ans.push_back(i);
		}
		if(ans.size()>=n){
			printf("Matching\n");
			for(int i=0;i<n;i++) printf("%d ",ans[i]);
			printf("\n");
		}
		else{
			printf("IndSet\n");
			int tmp=0;
			for(int i=1;i<=3*n;i++){
				if(!vis[i]){
					printf("%d ",i);
					tmp++;
					if(tmp==n) break;
				}
			}
			printf("\n");
		}
	}
	return 0;
}