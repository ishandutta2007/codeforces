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
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct item{
	int sum,minp;
	bool operator<(const item &i)const{
		if(sum!=i.sum) return sum>i.sum;
		return minp>i.minp;
	}
}it[maxn];
int n,ans;char s[maxn*5];
int main(){
	n=read();
	FOR(i,1,n){
		scanf("%s",s+1);
		int l=strlen(s+1),sum=0,minp=INT_MAX;
		FOR(j,1,l) sum+=s[j]=='('?1:-1,minp=min(minp,sum);
		it[i]=(item){sum,minp};
	}
	sort(it+1,it+n+1);int cur=n;
	FOR(i,1,n){
		if(cur<=i) break;
		if(it[i].minp<0) continue;
		while(cur>i && it[i].sum+it[cur].sum<0) cur--;
		if(cur<=i || it[i].sum+it[cur].sum!=0) continue;
		int j=cur;bool flag=false;
		while(j>i && it[j].sum==it[cur].sum){
			if(it[i].sum+it[j].minp>=0){ans++;cur=j-1;flag=true;break;}
			j--;
		}
		if(!flag) cur=j;
	}
	printf("%d\n",ans);
}