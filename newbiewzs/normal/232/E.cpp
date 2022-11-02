#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
#include<unordered_map>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=505;
const int M=6e5+55;
int n,m,q,ans[M],s[N][N];
char c[N][N];
bitset<N>b[N][N],d[N][N];
struct node{
	int x,y,xx,yy,id;
}a[M],tmpa[M],tmpb[M],tmpc[M];
void solve(int l,int r,int L,int R,int x,int y){
	int topa=0,topb=0,topc=0;
	if(l==r)return ;
//	if(r-l>R-L){
		int mid=((l+r)>>1);
		for(int i=x;i<=y;i++){
			if(a[i].xx<mid)tmpa[++topa]=a[i];
			else if(a[i].x>mid)tmpb[++topb]=a[i];
			else tmpc[++topc]=a[i];
		}
		for(int k=mid;k>=l;k--){
			for(int j=R;j>=L;j--){
				if(c[k][j]=='#')continue;
				if(j!=R){
					if(c[k][j+1]!='#'){
						b[k][j]|=b[k][j+1];
						if(k==mid)b[k][j][j+1]=1;
					}
				}
				if(k!=mid and c[k+1][j]!='#'){
					b[k][j]|=b[k+1][j];
					if(k==mid-1)b[k][j][j]=1;
				}
			}
		}
		for(int k=mid;k<=r;k++){
			for(int j=L;j<=R;j++){
				if(c[k][j]=='#')continue;
				if(j!=L){
					if(c[k][j-1]!='#'){
						d[k][j]|=d[k][j-1];
						if(k==mid)d[k][j][j-1]=1;
					}
				}
				if(k!=mid and c[k-1][j]!='#'){
					d[k][j]|=d[k-1][j];
					if(k==mid+1)d[k][j][j]=1;
				}
			}
		}
		for(int i=1;i<=topc;i++){
			if((b[tmpc[i].x][tmpc[i].y]&d[tmpc[i].xx][tmpc[i].yy]).count())ans[tmpc[i].id]=1;
			if(tmpc[i].xx==mid){
				if(b[tmpc[i].x][tmpc[i].y][tmpc[i].yy])ans[tmpc[i].id]=1;
			}
			if(tmpc[i].x==mid){
				if(d[tmpc[i].xx][tmpc[i].yy][tmpc[i].y])ans[tmpc[i].id]=1;
			}
		}
		for(int i=1;i<=topa;i++){
			a[x+i-1]=tmpa[i];
		}
		for(int i=1;i<=topb;i++){
			a[x+topa+i-1]=tmpb[i];
		}
		for(int k=mid-1;k>=l;k--)for(int j=R;j>=L;j--)b[k][j].reset();
		for(int k=mid+1;k<=r;k++)for(int j=L;j<=R;j++)d[k][j].reset();
		solve(l,mid,L,R,x,x+topa-1);
		solve(mid+1,r,L,R,x+topa,x+topa+topb-1);
//	}
//	else{
//		int mid=((L+R)>>1);
		
//	}
}
int top;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			if(c[i][k]=='#')s[i][k]=1;
			s[i][k]+=s[i-1][k]+s[i][k-1]-s[i-1][k-1];
		}
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		a[++top].x=read(),a[top].y=read(),a[top].xx=read(),a[top].yy=read(),a[top].id=i;
		int xx=abs(a[top].x-a[top].xx);
		int yy=abs(a[top].y-a[top].yy);
		if(xx+yy<=1 and c[a[top].x][a[top].y]!='#' and c[a[top].xx][a[top].yy]!='#'){
			ans[i]=1;
		}
		if(a[top].x==a[top].xx)
		{
		if((s[a[top].x][a[top].yy]-s[a[top].x][a[top].y-1]-s[a[top].x-1][a[top].yy]+s[a[top].x-1][a[top].y-1])==0)ans[i]=1;
		}
		if(a[top].y==a[top].yy)if((s[a[top].xx][a[top].y]-s[a[top].xx][a[top].y-1]-s[a[top].x-1][a[top].y]+s[a[top].x-1][a[top].y-1])==0)ans[i]=1;
		if(ans[i])top--;
	}
	solve(1,n,1,m,1,top);
	for(int i=1;i<=q;i++){
		if(ans[i])puts("Yes");
		else puts("No");
	}
	return 0;
}