#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
const double eps=1e-6;
struct inout{
    static const int ibufl=1<<25;
    char in_buf[ibufl+5],out_buf[ibufl+5],*inf,*ouf;
    void init(){
        fread(in_buf,1,ibufl,stdin);
        inf=in_buf;
        ouf=out_buf;
    }
    inout& operator >>(int &a){
        int fh=1;
        while(!(isdigit(*inf)||*inf=='-'))++inf;
        if(*inf=='-')fh=-1,++inf;
        a=0;
        while(isdigit(*inf)){a=a*10+*inf-'0';++inf;}
        a*=fh;
        return *this;
    }
    inout& operator >>(char &a){
        while(*inf==' '||*inf=='\n')++inf;
        a=*inf;
        ++inf;
        return *this;
    }
    inout& operator >>(char *a){
        while(*inf==' '||*inf=='\n')++inf;
        while(!(*inf==' '||*inf=='\n')){*a=*inf;++inf;++a;}
        *a='\0';
        return *this;
    }
    inout& operator >>(double &a){
        int fh=1;
        double s;
        while(!(isdigit(*inf)||*inf=='-'))++inf;
        if(*inf=='-')fh=-1,++inf;
        a=0;
        while(isdigit(*inf)){a=a*10+*inf-'0';++inf;}
        if(*inf=='.'){
            s=0.1;
            ++inf;
            while(isdigit(*inf)){
                a+=s*(*inf-'0');
                ++inf;
                s*=0.1;
            }
        }
        a*=fh;
        return *this;
    }
    void writeint(int x){
        if(x/10)writeint(x/10);
        *ouf=x%10+'0';
        ++ouf;
    }
    inout& operator <<(int a){

        if(a<0){*ouf='-';++ouf;a=-a;}
        writeint(a);
        return *this;
    }
    static const int sz=2;
    inout& operator <<(char a){
        *ouf=a;++ouf;
        return *this;
    }
    inout& operator <<(char *a){
        while(*a){
            *ouf=*a;
            ++ouf;
            ++a;
        }
        return *this;
    }
    inout& operator <<(double a){
        if(a<-eps){*ouf='-';++ouf;a=-a;}
        writeint((int)a);
        a-=(int)a;
        *ouf='.';
        ++ouf;
        FOR(i,1,sz){
            a=a*10;
            *ouf=(int)a+'0';
            ++ouf;
            a-=(int)a;
        }
        return *this;
    }
    void out(){
        fwrite(out_buf,1,ouf-out_buf,stdout);
    }
};
inout io;
#define cin io
#define cout io

/*----------------------------------------------------------------------------------------------*/

int n;
int b[1005],a[1005];
int lst[30000000],num[30];
int sum1[1<<14],sum2[1<<14];
bool vis[1005];
int ans[1005];
signed main(){
	io.init();
	cin>>n;
	int it=0;
	FOR(i,1,n){
		cin>>b[i];
		if(!(b[i]&1)){
			it=i;
		}
	}
	if(n==2){
		if(b[1]==b[2]){
			cout<<"YES\n";
			cout<<0<<' '<<b[1];
		}else {
			cout<<"NO";
		}
		io.out();
		RE 0;
	}
	if(it){
		if(n==3&&((b[1]^b[2]^b[3])&1)){
			cout<<"NO\n";
		}else{
			int it1=0,it2=0;
			FOR(i,1,n){
				FOR(j,i+1,n)if(i!=it&&j!=it){
					if((b[i]&1)==(b[j]&1)){
						it1=i;it2=j;
					}
				}
			}
			int tn=0;
			int t1=b[it1]+b[it2]+b[it];
			t1/=2;
			ans[++tn]=t1-b[it1];
			ans[++tn]=t1-b[it2];
			ans[++tn]=t1-b[it];
			FOR(i,1,n)if(i!=it1&&i!=it2&&i!=it){
				ans[++tn]=b[i]-ans[1];
			}
			cout<<"YES\n";
			FOR(i,1,n)cout<<ans[i]<<' ';
		}
		io.out();
		RE 0;
	}
	int len=min(n,22);
	FOR(i,1,len){
		num[i-1]=b[i];
	}
	int mid=len/2;
	rep(i,1,1<<mid){
		rep(j,0,mid)if(i&(1<<j)){
			sum1[i]+=num[j];
		}
	}
	rep(i,1,1<<(len-mid)){
		rep(j,0,len-mid)if(i&(1<<j)){
			sum2[i]+=num[j+mid];
		}
	}
	int msk1=-1,msk2=-1;
	rep(i,1,1<<len)if(__builtin_popcount(i)==mid){
		int sum=sum1[i&((1<<mid)-1)]+sum2[i>>mid];
		if(lst[sum]){
			int t=i&lst[sum];
			msk1=i^t;
			msk2=lst[sum]^t;
			break;
		}
		lst[sum]=i;
	}
	if(msk1==-1){
		cout<<"NO";io.out();RE 0;
	}
	int tn=0,l=__builtin_popcount(msk1);
	V<int> v;
	rep(j,0,len){
		if(msk1&(1<<j))v.PB(j+1);
	}
	V<int> v2;
	rep(j,0,len){
		if(msk2&(1<<j))v2.PB(j+1);
	}
	V<int> tv;
	rep(i,0,l){
		tv.PB(v[i]);
		tv.PB(v2[i]);
		vis[v[i]]=vis[v2[i]]=1;
	}
	ans[++tn]=0;
	rep(i,0,tv.size()-1){
		ans[++tn]=b[tv[i]]-ans[tn];
	}
	FOR(i,1,n)if(!vis[i])ans[++tn]=b[i]-ans[1];
	cout<<"YES\n";
	FOR(i,1,n)cout<<ans[i]<<' ';
	io.out();
	RE 0;
}