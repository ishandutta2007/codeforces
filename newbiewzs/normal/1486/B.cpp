#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=10005; 
int T,n;
int x[N],y[N];
struct node{
	int x,y;
}a[N];
int cmp(node x,node y){
	return x.x<y.x;
}
int cmpp(node x,node y){
	return x.y<y.y;
}
signed main(){
	cin>>T;
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i].x=read();a[i].y=read();
		}
		sort(a+1,a+n+1,cmp);
		int hh;
		if(n%2==0){
			hh=a[n/2+1].x-a[n/2].x+1;
		}
		else{
			hh=1;
		}
		int gg;
		sort(a+1,a+n+1,cmpp);
		if(n%2==0){
			gg=a[n/2+1].y-a[n/2].y+1;
		}
		else gg=1;
		cout<<gg*hh<<endl;
	}
	return 0;
}