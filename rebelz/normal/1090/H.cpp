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

int n,q;
char s[200005];
int cnt0[200005][20],cnt1[200005][20];

int main(){
	n=readint();
	scanf("%s",s+1);
	for(int i=n;i>=1;i--) s[i]=((s[i]-'0')^(s[i-1]-'0'))+'0';
	for(int i=0;(1<<i)<=n;i++){
		for(int j=(1<<i);j<=n;j++){
			cnt0[j][i]=cnt0[j-(1<<i)][i]+(s[j]=='0');
			cnt1[j][i]=cnt1[j-(1<<i)][i]+(s[j]=='1');
		}
	}
	q=readint();
	int l,r;
	while(q--){
		l=readint()+1; r=readint()+1;
		int now=0;
		for(int i=0;(1<<(i+1))<r-l+1;i++){
			int tmp=min(cnt0[r-(1<<i)+1][i+1]-cnt0[l+(1<<i)][i+1]+(s[l+(1<<i)]=='0')
			,cnt1[r-(1<<i)+1][i+1]-cnt1[l+(1<<i)][i+1]+(s[l+(1<<i)]=='1'));
			now+=tmp;
		}
		printf("%d\n",(now+1)/2);
	}
	return 0;
}