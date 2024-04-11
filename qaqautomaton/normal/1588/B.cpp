/*
Author: QAQAutoMaton
Lang: C++
Code: B.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
using namespace std;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cp;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
	}
}__INIT___;

namespace run{
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	int a,b,c,ok=0;
	int C2(int x){
		return x*(x-1)>>1;
	}
	int D2(int x){
		int l=0,r=1000000000;
		x<<=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(mid*(mid-1)<=x)l=mid+1;
			else r=mid-1;
		}
		return l-1;
	}
	int getw(int l,int r,int l2,int r2){
		chkmax(l,l2);
		chkmin(r,r2);
		if(l<=r)return C2(r-l+1);
		return 0;
	}
	int query(int l,int r){
		if(l<1 || r>n)return rnd();
		//return getw(l,r,a,b-1)+getw(l,r,b,c);
		cout<<'?'<<' '<<l<<' '<<r<<endl;
		int w;
		cin>>w;
		if(w==-1)exit(0);
		return w;
	}
	void answer(int l,int mid,int r){
		/*assert(l==a && mid==b && r==c);
		assert(!ok);
		ok=1;*/
		cout<<'!'<<' '<<l<<' '<<mid<<' '<<r<<endl;
	}
	int st;
	void solve(int l,int r,int v){
		if(r-l<=5){
			int s=query(l,r);
			if(s==st){
				while(l+4<=r && query(l+1,r)==s)++l;
				while(l+4<=r && query(l,r-1)==s)--r;
				for(int i=l+1;i+1<r;++i)if(query(l,i)+query(i+1,r)==st){answer(l,i+1,r);return;}
			}
			else{
				int rm=st-s;
				if(v==0){
					answer(l-1,l+rm,l+rm+D2(st-C2(rm+1))-1);
					return;
				}
				else{
					answer(r-rm-D2(st-C2(rm+1))+1,r-rm+1,r+1);
					return;
				}
			}
		}
		else{
			int mid=(l+r)>>1;
			if(v==0){
				int w=query(l,mid);
				if(w==st){solve(l,mid,1);}
				else if(!w){solve(mid+1,r,0);}
				else{

					int s=query(l,r);
					if(s!=st){
						int rm=st-s;
						answer(l-1,l+rm,l+rm+D2(st-C2(rm+1))-1);
						return;
					}
					else{
						int w2=query(mid+1,r);
						if(C2(D2(w))==w){
							do{
								int v=D2(w);
								int s0=st-w-w2;
								if(s0%v)break;
								int rm=st-C2(v+s0/v);
								if(C2(D2(rm))==rm){
									int v2=D2(rm);
									if(query(mid-v+1,mid+s0/v)+query(mid+s0/v+1,mid+s0/v+v2)==st){
										answer(mid-v+1,mid+s0/v+1,mid+s0/v+v2);return;
									}
								}	
							}while(0);
						}
						if(C2(D2(w2))==w2){
							do{
								int v=D2(w2);
								int s0=st-w-w2;
								if(s0%v)break;
								int rm=st-C2(v+s0/v);
								if(C2(D2(rm))==rm){
									int v2=D2(rm);
									if(query(mid-v2-s0/v+1,mid-s0/v)+query(mid-s0/v+1,mid+v)==st){
										answer(mid-v2-s0/v+1,mid-s0/v+1,mid+v);return;
									}
								}	
							}while(0);	
						}
					}
				}
			}
			else{
				int w=query(mid+1,r);
				if(w==st){solve(mid+1,r,0);}
				else if(!w){solve(l,mid,1);}
				else{
					int s=query(l,r);
					if(s!=st){
						int rm=st-s;
						answer(r-rm-D2(st-C2(rm+1))+1,r-rm+1,r+1);
						return;
					}
					else{
						int w2=w;
						int w=query(l,mid);
						if(C2(D2(w))==w){
							do{
								int v=D2(w);
								int s0=st-w-w2;
								if(s0%v)break;
								int rm=st-C2(v+s0/v);
								if(C2(D2(rm))==rm){
									int v2=D2(rm);
									if(query(mid-v+1,mid+s0/v)+query(mid+s0/v+1,mid+s0/v+v2)==st){
										answer(mid-v+1,mid+s0/v+1,mid+s0/v+v2);return;
									}
								}	
							}while(0);
						}
						if(C2(D2(w2))==w2){
							do{
								int v=D2(w2);
								int s0=st-w-w2;
								if(s0%v)break;
								int rm=st-C2(v+s0/v);
								if(C2(D2(rm))==rm){
									int v2=D2(rm);
									if(query(mid-v2-s0/v+1,mid-s0/v)+query(mid-s0/v+1,mid+v)==st){
										answer(mid-v2-s0/v+1,mid-s0/v+1,mid+v);return;
									}
								}	
							}while(0);	
						}
					}
				}
			}
		}
	}

	bool main(){

		cin>>n;
		/*n=rnd()%10+4;
		//n=rnd()%1000000000+1;
		a=rnd()%(n-3);
		b=rnd()%(n-3);
		c=rnd()%(n-3);
		sort2(a,b);sort2(b,c);sort2(a,b);
		a+=1;b+=3;c+=4;
		ok=0;
		cout<<n<<' '<<a<<' '<<b<<' '<<c<<endl;*/

		st=query(1,n);
		solve(1,n,0);	
		//assert(ok);
		return 0;
	}
}
signed main(){
	int t;
	t=100000;
	cin>>t;
	for(;t;--t){
		run::main();
	}
	return 0;
}