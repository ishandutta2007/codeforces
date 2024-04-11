#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=1e5+9;
int vis[N],val[N],flag;
char s[2]={'.','*'};
int n,m,k;
int id(int i,int j){
	return i*m+j; 
}
bool connect(){
	rep(i,0,n*m)vis[i]=0;
	vi q;
	rep(i,0,n*m){
		if(val[i]){
			q.pb(i);
			vis[i]=1;
			break;
		}
	} 
	rep(_,0,q.size()){
		int u=q[_];
		int i=u/m,j=u%m;
		if(i&&!vis[id(i-1,j)]&&val[id(i-1,j)]){
			vis[id(i-1,j)]=1;
			q.pb(id(i-1,j));
		}
		if(i<n-1&&!vis[id(i+1,j)]&&val[id(i+1,j)]){
			vis[id(i+1,j)]=1;
			q.pb(id(i+1,j));
		}
		if(j&&!vis[id(i,j-1)]&&val[id(i,j-1)]){
			vis[id(i,j-1)]=1;
			q.pb(id(i,j-1));
		}
		if(j<m-1&&!vis[id(i,j+1)]&&val[id(i,j+1)]){
			vis[id(i,j+1)]=1;
			q.pb(id(i,j+1));
		}
	}
	rep(i,0,n*m)if(vis[i]^val[i]){
	//	cout<<i<<"??\n";
		return 0;
	}
	return 1;
}
int count(){
	int res=0;
	rep(i,1,n)rep(j,1,m){
		int p=id(i,j);
		res+=val[p]&val[p-1]&val[p-m];
		res+=val[p]&val[p-1]&val[p-1-m];
		res+=val[p]&val[p-m]&val[p-1-m];
		res+=val[p-1]&val[p-m]&val[p-1-m];
	}
	return res;
}
bool solve(){
	flag=n<m; 
	if(n<m)swap(n,m);
	int sum=4*(n-1)*(m-1)-k;
	if(sum<0)return 0;
	if(n==3||m==3){
		if(sum==1||sum==2||sum==4||sum==5)return 0;
	}
	else{
		if(sum==1||sum==2||sum==4||sum==5||sum==8)return 0;
	}
	int l=1,r=n*m+1;
	while(l<r){
		int mid=l+r>>1;
		rep(i,0,mid)val[i]=1;
		rep(i,mid,n*m)val[i]=0;
		if(count()<=k)l=mid+1;
		else r=mid;
	}
	--l;
	rep(i,0,l)val[i]=1;
	rep(i,l,n*m)val[i]=0;
	int cur=count();
	if(cur==k)return 1;
	vi vec,vec2;
//	cout<<l<<' '<<n<<' '<<m<<"check\n";
	rep(i,0,n){
		rep(j,0,m){
			if(!i||abs(i-l/m)<=1){
			//	cout<<l<<' '<<i<<' '<<j<<"check\n"; 
				if(val[id(i,j)])vec.pb(id(i,j));
				else vec2.pb(id(i,j));
			}
		}
	}
	while(cur^k){
	//	cout<<cur<<"check\n";
		if(cur<k){
			int _=rand()%vec2.size();
			int x=vec2[_];
		//	cout<<_<<' '<<x<<"case1\n";
			val[x]=1;
			if(!connect()){
				val[x]=0;
				continue;
			}
			vec2.erase(vec2.begin()+_);
			vec.pb(x);
		}
		else{
			int _=rand()%vec.size();
			int x=vec[_];
			val[x]=0;
			if(!connect()){
				val[x]=1;
				continue;
			}
			vec.erase(vec.begin()+_);
			vec2.pb(x);
		}
		cur=count();
	}
	return 1;
} 
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		if(solve()){
			if(flag){
				rep(j,0,m){
					rep(i,0,n)putchar(s[val[id(i,j)]]);
					puts("");
				}
			}
			else{
				rep(i,0,n){
					rep(j,0,m)putchar(s[val[id(i,j)]]);
					puts("");
				}
			}
		}
		else puts("-1");
	}
}