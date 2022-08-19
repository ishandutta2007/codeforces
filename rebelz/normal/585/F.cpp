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

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,m,ncnt;
ll ch[50005][10],dep[50005],fail[5005],d[55][50005][2][2][2],q[50005];
char s[1005],x[55],y[55];
bool fl[50005];

void gettrie(char *s){
	int p=0;
	for(int i=1;i<=m/2;i++){
		if(!ch[p][s[i]-'0']) ch[p][s[i]-'0']=++ncnt;
		p=ch[p][s[i]-'0'];
	}
	fl[p]=1;
}

void getfail(){
	int front=0,rear=0;
	q[rear++]=0;
	while(front<rear){
		int t=q[front++];
		fl[t]|=fl[fail[t]];
		for(int i=0;i<10;i++){
			if(ch[t][i]){
				q[rear++]=ch[t][i];
				fail[ch[t][i]]=t?ch[fail[t]][i]:t;
			}
			else ch[t][i]=t?ch[fail[t]][i]:t;
		}
	}
}

void upd(ll &x,ll y){x+=y; x=x>=cys?x-cys:x;}

ll getans(){
	d[0][0][0][1][1]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<=ncnt;j++)
			for(int k=0;k<=1;k++)
				for(int c1=0;c1<=1;c1++)
					for(int c2=0;c2<=1;c2++)
						for(int num=(c1?x[i+1]-'0':0);num<=(c2?y[i+1]-'0':9);num++)
							upd(d[i+1][ch[j][num]][k|fl[ch[j][num]]][c1&(num==x[i+1]-'0')][c2&(num==y[i+1]-'0')],d[i][j][k][c1][c2]);
	ll ret=0;
	for(int i=0;i<=ncnt;i++)
		for(int c1=0;c1<=1;c1++)
			for(int c2=0;c2<=1;c2++)
				upd(ret,d[m][i][1][c1][c2]);
	return ret;
}

int main(){
	scanf("%s%s%s",s+1,x+1,y+1);
	n=strlen(s+1); m=strlen(x+1);
	for(int i=1;i<=n-m/2+1;i++) gettrie(s+i-1);
	getfail();
	printf("%lld\n",getans());
	return 0;
}