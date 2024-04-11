#include<bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(int i=(x),i##_END=(y);i<=i##_END;++i)
#define DOR(i,x,y) for(int i=(x),i##_END=(y);i>=i##_END;--i)
#define SFOR(i,x,y) for(int i=(x),i##_END=(y);i<i##_END;++i)
#define fi first
#define se second
#define pb push_back
typedef double db;
typedef long long LL;
typedef pair<int,int> PII;
typedef unsigned long long ull;
template<const int maxn,const int maxm>struct Link_list{
	int head[maxn],To[maxm],nxt[maxm],tot;
	void init(){memset(head,tot=0,sizeof head);}
	void add(int a,int b){nxt[++tot]=head[a];head[a]=tot;To[tot]=b;}
	int& operator [] (const int x){return To[x];}
	#define LFOR(i,x,a) for(int i=(a).head[x];i;i=(a).nxt[i])
};
template<class T>inline bool chk_mi(T &x,T y){return x>y?x=y,true:false;}
template<class T>inline bool chk_mx(T &x,T y){return x<y?x=y,true:false;}
template<class T>inline void Max(T x,T y){return x>y?x:y;}
template<class T>inline void Min(T x,T y){return x<y?x:y;}
inline void Rd(int &res){
	res=0;char c;
	while(c=getchar(),c<48);
	do res=(res<<3)+(res<<1)+(c&15);
	while(c=getchar(),47<c);
}
const int M=200005;
int A[M];

//priority_queue<int>Q;

int main(){
	int n;
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d",&A[i]);
	}
	
	int x,v;
	LL cnt=0;
	scanf("%d%d",&x,&v);
	
	FOR(i,1,n){
		if(A[i]<=x){
			continue;
		}
		int res=A[i]-x;
		cnt+=(res+x+v-1)/(x+v);
	}
	
	printf("%lld\n",1ll*cnt*v);
	
	return 0;
}