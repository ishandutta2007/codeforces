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
int a[200005][26];
char s[200005];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++) for(int j=0;j<26;j++) a[i][j]=a[i-1][j]+(s[i]-'a'==j);
	q=readint();
	int l,r;
	while(q--){
		l=readint(); r=readint();
		if(l==r) printf("Yes\n");
		else if(s[l]!=s[r]) printf("Yes\n");
		else if(r-l+1<=3) printf("No\n");
		else{
			int cnt=0;
			for(int i=0;i<26;i++) if(i!=s[l]-'a'&&a[r][i]-a[l-1][i]>0) cnt++;
			if(cnt>=2) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}