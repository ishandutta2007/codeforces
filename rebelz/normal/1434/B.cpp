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

int n,m;
int ans[100005];
pair<char,int> a[200005];
priority_queue<int,vector<int>,greater<int> > q;

int main(){
	n=readint();
	int x;
	for(int i=1;i<=n+n;i++){
		char ch=getchar();
		while(ch!='+'&&ch!='-') ch=getchar();
		if(ch=='-') x=readint();
		else x=0;
		a[i]=mp(ch,x);
	}
	reverse(a+1,a+n+n+1);
	for(int i=1;i<=n+n;i++){
		if(a[i].fi=='-'){
			if(!q.empty()&&q.top()<a[i].se) return printf("NO\n"),0;
			q.push(a[i].se);
		}
		else{
			if(q.empty()) return printf("NO\n"),0;
			ans[++m]=q.top(); q.pop();
		}
	}
	reverse(ans+1,ans+m+1);
	printf("YES\n");
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}