#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,x;
ll y,ans[maxn][2];
vector<int> a;
void solve(vector<int> &v,int bit){
	if(v.empty()) return;
	if(bit==-1) return;
	vector<int> v1,v2;
	ll sum=0;
	int cnt=0;
	FOR(i,0,(int)v.size()-1){
		if((v[i]>>bit)&1) v2.PB(v[i]),cnt++;
		else v1.PB(v[i]),sum+=cnt;
	}
	ll tot=1ll*cnt*((int)v.size()-cnt);
	ans[bit][0]+=sum;
	ans[bit][1]+=tot-sum;
	solve(v1,bit-1);solve(v2,bit-1);
}
int main(){
	n=read();
	FOR(i,1,n) a.PB(read());
	solve(a,29);
	FOR(i,0,29){
		if(ans[i][0]<=ans[i][1]) y+=ans[i][0];
		else y+=ans[i][1],x|=1<<i;
	}
	printf("%lld %d\n",y,x);
}