#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[5005],t[5005];

bool same(int l1,int r1,int l2,int r2){
	for(int i=l1,j=l2;i<=r1;i++,j++) if(s[i]!=s[j]) return false;
	return true;
}

bool pal(){
	for(int i=1;i<=n;i++) if(t[i]!=t[n-i+1]) return false;
	return true;
}

bool cmp(){
	for(int i=1;i<=n;i++) if(s[i]!=t[i]) return true;
	return false;
}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) t[j-i]=s[j];
		for(int j=1;j<=i;j++) t[n-i+j]=s[j];
		if(pal()&&cmp()) return printf("1\n"),0;
	}
	for(int i=1;i<=n/2;i++){
		if(!same(1,i,n-i+1,n)){
			if(i==n-i) return printf("1\n"),0;
			else return printf("2\n"),0;
		}
	}
	printf("Impossible\n");
	return 0;
}