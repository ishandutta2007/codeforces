#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=3030;
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
int n,k,cnt,tot;
bool vis[maxn];
vector<int> v[maxn*maxn];
char s[maxn];
bool check(){
	bool flag=false;
	FOR(i,1,n) if(s[i]=='L'){
		if(flag) return false;
	}
	else flag=true;
	return true;
}
int main(){
	n=read();k=read();
	scanf("%s",s+1);
	while(!check()){
		cnt++;
		FOR(i,1,n-1) vis[i]=false;
		FOR(i,1,n-1) if(s[i]=='R' && s[i+1]=='L') v[cnt].push_back(i),tot++,vis[i]=true;
		FOR(i,1,n-1) if(vis[i]) swap(s[i],s[i+1]);
	}
	if(k<cnt || k>tot) return puts("-1"),0;
	k-=cnt;
	FOR(i,1,cnt){
		if(k<(int)v[i].size()){
			FOR(j,0,k-1) printf("1 %d\n",v[i][j]);
			printf("%d ",(int)v[i].size()-k);
			FOR(j,k,(int)v[i].size()-1) printf("%d ",v[i][j]);
			puts("");
			k=0;
		}
		else{
			FOR(j,0,(int)v[i].size()-1) printf("1 %d\n",v[i][j]);
			k-=v[i].size()-1;
		}
	}
}