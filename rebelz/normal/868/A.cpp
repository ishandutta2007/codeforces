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

int n;
char s[105],t[105];
int a[105],b[105];

int main(){
	scanf("%s",s+1);
	n=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",t+1);
		a[t[2]-'a']=1,b[t[1]-'a']=1;
		if(s[1]==t[1]&&s[2]==t[2]) return printf("YES\n"),0;
	}
	if(a[s[1]-'a']&&b[s[2]-'a']) return printf("YES\n"),0;
	printf("NO\n");
	return 0;
}