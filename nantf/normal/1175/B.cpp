#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int l,stk[maxn],tp;
char op[maxn][10];
bool hhh[maxn];
ll x,y[maxn],a[maxn];
int main(){
	l=read();
	FOR(i,1,l){
		scanf("%s",op[i]+1);
		if(op[i][1]=='f') a[i]=read();
	}
	y[0]=1;
	FOR(i,1,l){
		if(op[i][1]=='f'){
			stk[++tp]=i;
			y[i]=y[i-1]*a[i];
			if(hhh[i-1] || y[i]>=(1ll<<32)) hhh[i]=true;
		}
		else{
			if(op[i][1]=='e') y[i]=y[stk[tp]-1],hhh[i]=hhh[stk[tp]-1],tp--;
			else{
				y[i]=y[i-1];hhh[i]=hhh[i-1];
				if(hhh[i]) return puts("OVERFLOW!!!"),0;
				x+=y[i];
				if(x>=(1ll<<32)) return puts("OVERFLOW!!!"),0;
			}
		}
	}
	cout<<x<<endl;
}