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
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int q,n;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	q=read();
	while(q--){
		n=read();
		int c=1;
		while(c<=n) c<<=1;
		if(n!=c-1) printf("%d\n",c-1);
		else{
			bool flag=false;
			for(int i=2;i*i<=n;i++)
				if(n%i==0){printf("%d\n",n/i);flag=true;break;}
			if(!flag) printf("1\n");
		} 
	}
}