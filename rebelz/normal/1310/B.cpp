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

int n,k;
int a[300000],d[300000][2][2];

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=k;i++) a[((1<<n)+readint()-1)/2]++;
	memset(d,-0x3f,sizeof(d));
	for(int i=1;i<=(1<<(n-1));i++){
		int id=(1<<(n-1))+i-1;
		if(a[id]==0) d[id][0][0]=0;
		else if(a[id]==1) d[id][0][1]=d[id][1][0]=1;
		else if(a[id]==2) d[id][1][1]=1;
	}
	for(int i=(1<<(n-1))-1;i>=1;i--){
		int id1=i<<1,id2=i<<1|1;
		chkmax(d[i][0][0],d[id1][0][0]+d[id2][0][0]);
		chkmax(d[i][0][1],max(d[id1][0][0]+d[id2][0][1]+2,d[id1][0][1]+d[id2][0][0]+2));
		chkmax(d[i][0][1],max(d[id1][0][0]+d[id2][1][0]+2,d[id1][1][0]+d[id2][0][0]+2));
		chkmax(d[i][0][1],d[id1][0][1]+d[id2][0][1]+2);
		chkmax(d[i][1][0],max(d[id1][0][0]+d[id2][1][0]+1,d[id1][1][0]+d[id2][0][0]+1));
		chkmax(d[i][1][1],max(d[id1][0][0]+d[id2][1][1]+3,d[id1][1][1]+d[id2][0][0]+3));
		chkmax(d[i][1][1],max(d[id1][0][1]+d[id2][1][0]+3,d[id1][1][0]+d[id2][0][1]+3));
		chkmax(d[i][1][1],d[id1][1][0]+d[id2][1][0]+2);
		chkmax(d[i][1][1],max(d[id1][0][1]+d[id2][1][1]+3,d[id1][1][1]+d[id2][0][1]+3));
		chkmax(d[i][1][1],max(d[id1][1][0]+d[id2][1][1]+3,d[id1][1][1]+d[id2][1][0]+3));
		chkmax(d[i][1][1],d[id1][1][1]+d[id2][1][1]+3);
	}
	printf("%d\n",max(max(d[1][0][0],d[1][0][1]+1),max(d[1][1][0]+1,d[1][1][1]+1)));
	return 0;
}