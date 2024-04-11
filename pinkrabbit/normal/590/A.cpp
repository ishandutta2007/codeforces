#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int n,Ans;
int a[500001],b[100001];

int h[100001],nxt[200001],to[200001],tot;
void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	int j=0;
	F(i,2,n){
		if(a[i]!=a[i-1]){
			++j;
			if(i==n){
				Ans=max(Ans,j/2);
				if(j%2==0){
					F(k,i-j+1,i-1) a[k]=a[i];
				}
				else{
					F(k,i-j+1,i-j+j/2) a[k]=1-a[i];
					F(k,i-j+j/2+1,i) a[k]=a[i];
				}
				j=0;
			}
		}
		else{
			Ans=max(Ans,j/2);
			if(j%2==0){
				F(k,i-j,i-1) a[k]=a[i];
			}
			else{
				F(k,i-j,i-j+j/2-1) a[k]=1-a[i];
				F(k,i-j+j/2,i-2) a[k]=a[i];
			}
			j=0;
		}
	} printf("%d\n",Ans);
	F(i,1,n) printf("%d ",a[i]);
	return 0;
}