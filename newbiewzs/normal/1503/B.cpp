#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	char c=getchar();
	int s=0,x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}

int T,n,x,sa,sb,xa,ya,xb,yb,flag;
const int N=3e5+55;
void out(int id,int x,int y){
	cout<<id<<" "<<x<<" "<<y<<endl;
	cout.flush(); 
	fflush(stdout);
}
signed main(){
//	freopen("data.in","r",stdin);
	T=1;
	cin>>n;
	xa=1;ya=1;xb=1;yb=2;
	while(T--){
		for(int i=1;i<=n*n;i++){
			cin>>x;
			if(x==1){
				if(sb!=n*n/2){
					out(2,xb,yb);flag=2;
				}
				else{
					out(3,xa,ya);flag=1;
				}
			}
			if(x==2){
				if(sa!=(n*(n)+1)/2){
					out(1,xa,ya);flag=1;
				}
				else{
					out(3,xb,yb);flag=2;
				}
			}
			if(x==3){
				if(sa!=(n*(n)+1)/2){
					out(1,xa,ya);flag=1;
				}
				else{
					out(2,xb,yb);flag=2;
				}
			}
			if(flag==1){
				if(ya+2>n){
					xa++;
					if(!(xa&1))ya=2;
					else ya=1;
				}
				else ya++,ya++;
				sa++;
			}
			if(flag==2){
				if(yb+2>n){
					xb++;
					if(!(xb&1))
					{
						yb=1;
					}
					else yb=2;
				}
				else yb++,yb++;
				sb++;
			}
		}
	}
	return 0;
}