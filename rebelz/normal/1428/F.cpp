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
	int l,r,len; ll val;
	node(int l=0,int r=0,int len=0,ll val=0):l(l),r(r),len(len),val(val){}
}stk[500005];

int n,top;
ll sum[500005];
char s[500005];

int main(){
	n=readint();
	scanf("%s",s+1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			node tmp;
			if(top&&stk[top].r==i-1) tmp=stk[top],tmp.r++,tmp.len++,top--;
			else tmp=node(i,i,1,0);
			while(top&&stk[top].len<=tmp.len) top--;
			if(!top) tmp.val=1ll*(tmp.l-1)*tmp.len;
			else tmp.val=1ll*(tmp.r-stk[top].r)*tmp.len+1ll*(stk[top].len-tmp.len)*(stk[top].len+tmp.len+1)/2;
			stk[++top]=tmp;
			sum[top]=sum[top-1]+stk[top].val;
		}
		if(top) ans+=1ll*sum[top]+1ll*stk[top].len*(stk[top].len+1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}