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
int a[5005],b[5005],ta[5005],tb[5005],ans[5005];

int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return readint();
}

int main(){
	n=readint();
	for(int i=0;i<n;i++) tb[i]=ask(0,i);
	for(int i=0;i<n;i++) ta[i]=ask(i,0);
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) b[j]=i^tb[j];
		for(int j=0;j<n;j++) a[j]=b[0]^ta[j];
		bool fl=1;
		for(int j=0;j<n;j++) if(a[j]>=n||b[j]>=n) fl=0;
		if(!fl) continue;
		for(int j=0;j<n;j++) if(a[b[j]]!=j) fl=0;
		if(fl){
			cnt++;
			for(int j=0;j<n;j++) ans[j]=a[j];
		}
	}
	printf("!\n");
	fflush(stdout);
	printf("%d\n",cnt);
	fflush(stdout);
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}