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
char s[100005],t[100005];
int now[26][2],lst[100005][26][2];

int main(){
	int T=readint();
	while(T--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		for(int i=0;i<26;i++) for(int j=0;j<2;j++) now[i][j]=0;
		for(int i=1;i<=n+1;i++){
			for(int j=0;j<26;j++)
				for(int k=0;k<2;k++)
					lst[i][j][k]=now[j][k];
			if(i<=n) now[s[i]-'a'][i&1]=i;
		}
		int pl=n+1;
		for(int i=m;i>=1;i--) pl=lst[pl][t[i]-'a'][!(pl&1)];
		if(!pl) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}