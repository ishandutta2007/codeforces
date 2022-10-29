#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=4e6+9;
int n,m;
char s[N],ans[N];
int sum[N],tree[N];
bool check(int t){
	int tot=(2*t+1)*(2*t+1);
	for(int i=m+2;i<(n+1)*(m+2);i+=m+2){
		rep(j,i+1,i+1+m)tree[j]=0;
	}
	rep(i,t+1,n-t+1){
		rep(j,t+1,m-t+1){
			int r1=i+t,r2=i-t-1,c1=j+t,c2=j-t-1;
			if(sum[r1*(m+2)+c1]+sum[r2*(m+2)+c2]-sum[r1*(m+2)+c2]-sum[r2*(m+2)+c1]==tot){
			//	if(t==1)cout<<i<<' '<<j<<"checkok\n";
				++tree[(r1+1)*(m+2)+c1+1];
				++tree[(r2+1)*(m+2)+c2+1];
				--tree[(r1+1)*(m+2)+c2+1];
				--tree[(r2+1)*(m+2)+c1+1];
			//	if(t==1)cout<<r2+1<<' '<<c2+1<<endl<<r1+1<<' '<<c1+1<<"where\n";
			}
		}
	}
	int flag=1;
	rep(i,1,n+1){
		rep(j,1,m+1){
			tree[i*(m+2)+j]+=tree[(i-1)*(m+2)+j]+tree[i*(m+2)+j-1]-tree[(i-1)*(m+2)+(j-1)];
		//	if(t==1)cout<<tree[i*(m+2)+j]<<' ';
			if(s[i*(m+2)+j]=='X'&&!tree[i*(m+2)+j])flag=0;
		}
		//cout<<endl;
	}
	return flag;
}
void Set(int t){
	int tot=(2*t+1)*(2*t+1);
	for(int i=m+2;i<(n+1)*(m+2);i+=m+2){
		rep(j,i+1,i+1+m)ans[j]='.';
	}
	rep(i,t+1,n-t+1){
		rep(j,t+1,m-t+1){
			int r1=i+t,r2=i-t-1,c1=j+t,c2=j-t-1;
			if(sum[r1*(m+2)+c1]+sum[r2*(m+2)+c2]-sum[r1*(m+2)+c2]-sum[r2*(m+2)+c1]==tot)ans[i*(m+2)+j]='X';
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)scanf("%s",s+i*(m+2)+1);
	int l=0,r=min(n,m)+1;
	rep(i,1,n+1){
		rep(j,1,m+1){
			if(s[i*(m+2)+j]=='X')sum[i*(m+2)+j]=sum[(i-1)*(m+2)+j]+sum[i*(m+2)+j-1]-sum[(i-1)*(m+2)+(j-1)]+1;
			else sum[i*(m+2)+j]=sum[(i-1)*(m+2)+j]+sum[i*(m+2)+j-1]-sum[(i-1)*(m+2)+(j-1)];
		//	cout<<sum[i*(m+2)+j];
		}
	//	cout<<endl;
	}
	//system("pause");
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)){
		//	cout<<mid<<' '<<1<<"check\n";
			l=mid+1;
		}
		else{
		//	cout<<mid<<' '<<0<<"check\n";
			r=mid;
		}
	}
	printf("%d\n",r-1);
	Set(r-1);
	rep(i,1,n+1)printf("%s\n",ans+i*(m+2)+1);
}