#include<bits/stdc++.h>
#define int long long
#define fl fflush(stdout)
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=10005; 
int T,n,x,y;
#define mid ((l+r)>>1)
void cdq(int l,int r){
	if(l==r){
		cout<<"! "<<l;
		exit(0);
		return ;
	}
	if(l+1==r){
		cout<<"? "<<l<<" "<<r<<endl;
		fl;
		cin>>x;
		if(x==l)cout<<"! "<<r;
		else cout<<"! "<<l; 
		exit(0);
		return ;
	}
	cout<<"? "<<l<<" "<<r<<endl;
	fl;
	cin>>x;
	fl;
	if(x<=mid){
		if(l==mid){
			cdq(mid+1,r);
		}
		cout<<"? "<<l<<" "<<mid<<endl;
		fl;
		cin>>y;
		if(y!=x){
			cdq(mid+1,r);
		}
		else{
			cdq(l,mid);
		}
	}
	else{
		if(mid+1==r){
			cdq(l,mid);
		} 
		cout<<"? "<<mid+1<<" "<<r<<endl;
		fl;
		cin>>y;
		if(y!=x){
			cdq(l,mid);
		}
		else{
			cdq(mid+1,r);
		}	
	}
}
signed main(){
		n=read();
		cdq(1,n);
	return 0;
}