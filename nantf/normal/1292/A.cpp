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
int n,q,cnt[2][maxn];
ll tot;
map<PII,bool> vis;
int main(){
	n=read();q=read();
	while(q--){
		int r=read()-1,c=read();
		if(!vis[MP(r,c)]){
			vis[MP(r,c)]=true;
			tot+=cnt[r^1][c-1]+cnt[r^1][c]+cnt[r^1][c+1];
			cnt[r][c]++;
		}
		else{
			vis[MP(r,c)]=false;
			tot-=cnt[r^1][c-1]+cnt[r^1][c]+cnt[r^1][c+1];
			cnt[r][c]--;
		}
		puts(tot?"No":"Yes");
	}
}