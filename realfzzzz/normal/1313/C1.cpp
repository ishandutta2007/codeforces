#include<algorithm>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
    int x=0;
    bool f=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-'){
        f=1;
        c=getchar();
    }
	while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f?-x:x;
}
const int maxn=5e5+5;
int n,m[maxn];
int st[maxn][30];
void get_st(){
	for(int i=1;i<=n;i++) st[i][0]=m[i];
	for(int i=1;(1<<i)<=n;i++) for(int j=1;j+(1<<i)-1<=n;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}
int rmq(int l,int r){
	int k=0;
	while((1<<(k+1))<=r-l+1) k++;
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
typedef long long ll;
ll res1[maxn],res2[maxn];
int a[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    for(int i=1;i<=n;i++) m[i]=readint();
    get_st();
    res1[0]=0;
    for(int i=1;i<=n;i++){
    	int l=0,r=i-1;
    	while(l<r){
    		int mid=l+(r-l+1)/2;
    		if(rmq(mid,i-1)<m[i]) l=mid;
    		else r=mid-1;
		}
		res1[i]=res1[r]+1ll*m[i]*(i-r);
	}
	res2[n+1]=0;
    for(int i=n;i>0;i--){
    	int l=i+1,r=n+1;
    	while(l<r){
    		int mid=l+(r-l)/2;
    		if(rmq(i+1,mid)<m[i]) r=mid;
    		else l=mid+1;
		}
		res2[i]=res2[r]+1ll*m[i]*(r-i);
	}
	ll c,ans=0;
	for(int i=1;i<=n;i++){
		ll res=m[i];
		int l=0,r=i-1;
    	while(l<r){
    		int mid=l+(r-l+1)/2;
    		if(rmq(mid,i-1)<m[i]) l=mid;
    		else r=mid-1;
		}
		res+=res1[r]+1ll*m[i]*(i-r-1);
    	l=i+1;
		r=n+1;
    	while(l<r){
    		int mid=l+(r-l)/2;
    		if(rmq(i+1,mid)<m[i]) r=mid;
    		else l=mid+1;
		}
		res+=res2[r]+1ll*m[i]*(r-i-1);
		if(res>ans){
			c=i;
			ans=res;
		}
	}
	a[c]=m[c];
	int mm=m[c];
	for(int i=c-1;i>0;i--){
		mm=min(mm,m[i]);
		a[i]=mm;
	}
	mm=m[c];
	for(int i=c+1;i<=n;i++){
		mm=min(mm,m[i]);
		a[i]=mm;
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
    return 0;
}