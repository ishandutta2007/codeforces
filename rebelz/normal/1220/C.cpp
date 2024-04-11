#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[500005];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	printf("Mike\n");
	int now=s[1]-'a';
	for(int i=2;i<=n;i++){
		if(s[i]-'a'>now) printf("Ann\n");
		else printf("Mike\n");
		now=min(now,s[i]-'a');
	}
	return 0;
}