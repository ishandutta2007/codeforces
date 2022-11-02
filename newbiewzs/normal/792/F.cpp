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
//#include<unordered_map>
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
#define int long long
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
struct TB{
	int x,y;
	friend bool operator < (TB u,TB v){
		if(u.x!=v.x)return u.x<v.x;
		else return u.y<v.y;
	}
	friend ll operator * (TB u,TB v){
		return u.x*v.y-u.y*v.x;
	}
	friend TB operator - (TB u,TB v){
		return (TB){u.x-v.x,u.y-v.y};
	}
};
set<TB>s;
int n,m,op,x,y,las;
void insert(int x,int y){
	TB u={x,y};
	auto it=s.lower_bound(u);
	auto iv=prev(it);
	if(it!=s.begin() && (*iv - u)*(*it - u)>=0)return ;
	while(it!=s.end() && next(it)!=s.end() && (u-*it)*(*next(it)-*it)>=0){
		++it;
		s.erase(prev(it));
	}
	while(iv!=s.begin() and (u-*prev(iv))*(*iv-*prev(iv))>=0){
		--iv;
		s.erase(next(iv));
	}
	s.insert(u);
}
int query(int x,int y){
	TB u={(long long)(ceil(1.0*y/x)),0ll};
	auto it=s.lower_bound(u);
	if(it==s.begin())return 0;
	auto iv=prev(it);
	//cout<<"sese: "<<it->x<<" "<<it->y<<" "<<iv->x<<" "<<iv->y<<endl;
	if(it==s.end())return 0;
	int at=u.x;
	if((y- x*iv->x)*(it->y - iv->y) + (iv->y * (it->x - iv->x)) * x <= m*(it->x - iv->x))return 1;
	else return 0;
}

signed main(){
	s.insert((TB){0,0});
	n=read();m=read();
	for(int i=1;i<=n;i++){
		op=read();x=(read()+las)%1000000+1;y=(read()+las)%1000000+1;
		if(op==1){
			insert(x,y);
		}
		else{
			if(query(x,y)){las=i;puts("YES");}
			else puts("NO");
		}
	}
	return 0;
}
/*
3 100
1 4 9
2 19 49
2 19 49

*/