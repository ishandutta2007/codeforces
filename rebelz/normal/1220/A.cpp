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
int ch[130],cnt[1005];
char s[100005];

int main(){
	n=readint();
	scanf("%s",s+1);
	ch['z']=1,ch['e']=2,ch['r']=3,ch['o']=4,ch['n']=5;
	for(int i=1;i<=n;i++) cnt[ch[s[i]]]++;
	int num0=cnt[ch['z']];
	int num1=cnt[ch['n']];
	for(int i=1;i<=num1;i++) printf("1 ");
	for(int i=1;i<=num0;i++) printf("0 ");
	printf("\n");
	return 0;
}