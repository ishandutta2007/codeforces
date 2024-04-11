#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define PB push_back
using namespace std;

//:2
//:x6

/*
int (p+x)(1-x) 
*/

struct node{
	int x,y,state;
	bool operator <(const node &a)const{
		if (x!=a.x) return x<a.x;
		if (y!=a.y) return y<a.y;
		return state<a.state;
	} 
};
vector<node > vec[1000][20];
int n,nx[1000],ny[1000];
double x,y;
int getSX(int x,int a,int b){
	bool bo=0;
	if (a>b){
		swap(a,b);
		bo=1;
	}
	int ans=3*x+1+6*x*a+3*a;
	if (!bo) ans++;
	return ans;
}
int getSY(int x,int a,int b){
	if (a>b) swap(a,b);
	return 3*a*a+3*a+1;
}
int counter;
void getr(int state,int p,int x,int S,int sx,int sy){
	if (p<0){
		++counter;
		//cout<<state<<' '<<S<<' '<<p<<' '<<sx<<' '<<sy<<endl;
		vec[S][x].PB((node){sx,sy,state});
		return; 
	}
	if (x)
	getr(state       ,p-1,x-1,S+(x)+(x-1),sx+getSX(n+p,x-1,x),sy+getSY(n+p,x-1,x));
	getr(state|(1<<p),p-1,x+1,S+(x)+(x+1),sx+getSX(n+p,x+1,x),sy+getSY(n+p,x+1,x));
}
void found(int s1,int s2){
	//cout<<s1<<' '<<s2<<endl;
	For(i,0,n-1) putchar(((s1>>i)&1)?')':'(');
	For(i,0,n-1) putchar(((s2>>i)&1)?')':'(');
	exit(0);
}
void getl(int state,int p,int x,int S,int sx,int sy){
	if (p==n){
		for (int S2=S&1;S2<=n*n;S2+=2){
			int SS=(S+S2)/2;
			if (nx[SS]){
				node temp=(node){nx[SS]-sx,ny[SS]-sy,-1};
				int p2=lower_bound(vec[S2][x].begin(),vec[S2][x].end(),temp)-vec[S2][x].begin();
				if (p2!=vec[S2][x].size()){
					node temp2=vec[S2][x][p2];
					if (temp2.x==temp.x&&temp2.y==temp.y)
						found(state,temp2.state);
				}
			}
		}
		return; 
	}
	if (x)
	getl(state|(1<<p),p+1,x-1,S+(x)+(x-1),sx+getSX(p,x,x-1),sy+getSY(p,x,x-1));
	getl(state       ,p+1,x+1,S+(x)+(x+1),sx+getSX(p,x,x+1),sy+getSY(p,x,x+1));
}

/*
1 )
0 ( 
*/
int main(){
	scanf("%d%lf%lf",&n,&x,&y);
	n/=2;
	for (int i=1;i<=2*n*n;i++){
		double tx=x*i*6,ty=y*i*6;
		if (floor(tx+1e-6)-tx<2e-6)
			if (floor(ty+1e-6)-ty<2e-6){
				nx[i]=floor(tx+1e-6);
				ny[i]=floor(ty+1e-6);
			}
	}
	getr(0,n-1,0,0,0,0);
	For(i,1,n*n) For(j,0,n) sort(vec[i][j].begin(),vec[i][j].end());
	getl(0,0  ,0,0,0,0);
}