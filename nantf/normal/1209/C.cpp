#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
struct item{
	int x,id;
	bool operator<(const item &i)const{
		if(x!=i.x) return x<i.x;
		return id<i.id;
	}
}it[maxn];
int t,n,ans[maxn],back[maxn];
vector<int> hhh[10];
bool in[maxn];
char s[maxn];
int main(){
	t=read();
	while(t--){
		n=read();
		scanf("%s",s+1);/*
		FOR(i,1,n) it[i]=(item){s[i]-'0',i},in[i]=false;
		sort(it+1,it+n+1);
		int lst=0,fst=0;
		FOR(i,1,n) if(it[i].id>it[i-1].id) ans[it[i].id]=1;
		lst=0;
		bool flag=true;
		FOR(i,1,n) if(!in[i]){
			if(it[i].id>it[lst].id) ans[it[i].id]=2;
			else{puts("-");flag=false;break;}
			lst=i;
		}
		if(flag){
			FOR(i,1,n) printf("%d",ans[i]);
			puts("");
		}*/
		bool flag=true;
		FOR(i,0,9) hhh[i].clear();
		FOR(i,1,n) hhh[s[i]-'0'].push_back(i);
		int pos=-1,lst=-1;
		FOR(i,0,9) if(hhh[i].size()){
			back[i]=hhh[i].back();
			FOR(j,0,(int)hhh[i].size()-1){
				if(pos!=-1) ans[hhh[i][j]]=2;
				else if(lst!=-1 && hhh[i][j]<hhh[lst].back()) ans[hhh[i][j]]=2,back[i]=hhh[i][j];
				else ans[hhh[i][j]]=1;
			}
			if(lst!=-1){
				if(pos==-1){
					if(hhh[i].front()<back[lst]) pos=i;
				}
				else{
					if(hhh[i].front()<back[lst]){puts("-");flag=false;break;}
				}
			}
			lst=i;
		}
		if(flag){
			FOR(i,1,n) printf("%d",ans[i]);
			puts("");
		}
	}
}
/*
10000
10
0120120120
*/