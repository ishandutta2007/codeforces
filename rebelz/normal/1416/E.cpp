#include<bits/stdc++.h>

#define int long long
#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,l,r,rev,rg;
int a[500005];
set<int> s;

void clear(){
	s.clear();
	rev=0,l=1,r=0,rg=0;
}

int get(int x){
	if(rev) return rg-x;
	else return rg+x;
}

int bget(int x){
	if(rev) return rg-x;
	else return x-rg;
}

bool in(int x){
	if(s.size()){
		auto it=s.lower_bound(bget(x));
//		cout<<"??? "<<rev<<' '<<rg<<' '<<bget(x)<<' '<<*it<<endl;
		if(it!=s.end()&&*it==bget(x)) return true;
	}
	return l<=x&&x<=r;
}

bool empty(){
	return l>r&&s.empty();
}

void insert(int x){
	s.insert(bget(x));
}

void rotate(int x){
	rev^=1;
	int tl=l,tr=r;
	l=x-tr,r=x-tl;
	rg=x-rg;
}

void del(int x){
	chkmin(r,x);
	while(!s.empty()){
		auto it=rev==0?(--s.end()):s.begin();
		if(get(*it)>x) s.erase(it);
		else return;
	}
}

signed main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		int ans=0;
		clear();
		for(int i=1;i<=n;i++){
			del(a[i]-1);
			if(a[i]%2==0&&in(a[i]/2)){
				ans+=2;
				clear();
				insert(a[i]/2);
				l=1,r=0;
			}
			else if(empty()){
				if(a[i]%2==0){
					ans++;
					clear();
					insert(a[i]/2);
					l=1,r=0;
				}
				else{
					clear();
					r=a[i]-1;
				}
			}
			else{
				ans++;
				if(a[i]%2==0) insert(a[i]/2);
			}
			rotate(a[i]);
//			cout<<"ans "<<ans<<' '<<l<<' '<<r<<endl;
//			for(auto r:s) cout<<get(r)<<' ';
//			cout<<endl;
		}
		printf("%d\n",2*n-ans);
	}
	return 0;
}