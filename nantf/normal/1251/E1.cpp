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
int t,n,pre[maxn];
vector<int> v[maxn];
priority_queue<int,vector<int>,greater<int> > pq;
int main(){
	t=read();
	while(t--){
		n=read();
		FOR(i,1,n){
			int m=read(),p=read();
			v[m].push_back(p);
		}
		ll ans=0;
		int cnt=0;
		pre[0]=v[0].size();
		FOR(i,1,n-1) pre[i]=pre[i-1]+v[i].size();
		ROF(i,n-1,0){
			FOR(j,0,(int)v[i].size()-1) pq.push(v[i][j]);
			while((i==0?0:pre[i-1])+cnt<i){
				ans+=pq.top();
				pq.pop();
				cnt++;
			}
		}
		printf("%lld\n",ans);
		FOR(i,0,n-1) v[i].clear();
		while(!pq.empty()) pq.pop();
	}
}