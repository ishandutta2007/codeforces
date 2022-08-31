#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int to,c1,c2;
	node(int to=0,int c1=0,int c2=0):to(to),c1(c1),c2(c2){}
};

int n;
int cnt[105][30],ans[105],chk[105],tmp[30];
bool vis[105];
vector<node> g[105];
char s[105];

void work(int l,int r){
	if(l>r||l<1) return;
	memset(cnt,0,sizeof(cnt));
	printf("? %d %d\n",l,r);
	fflush(stdout);
	for(int i=1;i<=(r-l+1)*(r-l+2)/2;i++){
		scanf("%s",s+1);
		int m=strlen(s+1);
		for(int j=1;j<=m;j++) cnt[m][s[j]-'a']++;
	}
	for(int i=r-l;i>=(r-l)/2;i--){
		vector<int> now(0);
		for(int j=0;j<26;j++){
			cnt[i][j]=(r-l-i+2)*cnt[r-l+1][j]-cnt[i][j];
			for(int k=i+1;k<=r-l;k++) cnt[i][j]-=cnt[k][j]*(k-i+1);
			for(int k=1;k<=cnt[i][j];k++) now.push_back(j);
		}
		assert(now.size()==2);
		g[l+i].push_back(node(r-i,now[0],now[1]));
		g[r-i].push_back(node(l+i,now[0],now[1]));
//		cout<<"test "<<l+i<<' '<<r-i<<' '<<now[0]<<' '<<now[1]<<endl;
	}
}

bool check(int u){
	for(auto r:g[u]){
		if(chk[u]==r.c1){
			if(chk[r.to]>=0&&chk[r.to]!=r.c2) return false;
			else if(vis[r.to]) continue;
			vis[r.to]=true;
			chk[r.to]=r.c2;
			if(!check(r.to)) return false;
		}
		else if(chk[u]==r.c2){
			if(chk[r.to]>=0&&chk[r.to]!=r.c1) return false;
			else if(vis[r.to]) continue;
			vis[r.to]=true;
			chk[r.to]=r.c1;
			if(!check(r.to)) return false;
		}
		else return false;
	}
	return true;
}

int main(){
	n=readint();
	work(1,n);
	work(1,n/2);
	work(n/2,n);
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=n;i++){
		memset(tmp,0,sizeof(tmp));
		bool fl=0;
		for(auto x:g[i]){
			if(x.c1==x.c2){
				ans[i]=x.c1;
				fl=1;
				break;
			}
		}
		if(fl) continue;
		for(auto x:g[i]) tmp[x.c1]++,tmp[x.c2]++;
		vector<int> now(0);
		for(int j=0;j<26;j++) if(tmp[j]==g[i].size()) now.push_back(j);
		for(auto x:now){
			memcpy(chk,ans,sizeof(chk));
			memset(vis,0,sizeof(vis));
			chk[i]=x,vis[i]=true;
			if(check(i)){
				ans[i]=x;
				break;
			}
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++) printf("%c",ans[i]+'a');
	printf("\n");
	fflush(stdout);
	return 0;
}