#pragma GCC optimize(2)
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

int dfs(int x,int k){
	string s;
	stringstream ss;
	ss<<x;
	ss>>s;
	int cnt[10]={},t=-1,num=0;
	V<int> v;
	rep(i,0,s.size()){
		num+=cnt[s[i]-'0']==0;
		cnt[s[i]-'0']++;
		if(num>k){
			cnt[s[i]-'0']=0;t=i;
			break;
		}
	}
	if(t==-1)RE x;
	FOR(i,0,9)if(cnt[i])v.PB(i);
	v.PB(100);
	bool eq=1;
	int re=0;
	rep(i,0,t)re=re*10+s[i]-'0';
	rep(i,t,s.size()){
		if(!eq){
			re=re*10+v[0];
		}else{
			int now=*lwb(ALL(v),s[i]-'0');
			if(now==100){
				int t=dfs(re+1,k);
				int mini=100;
				int tp=t;
				num=0;
				FILL(cnt,0);
				while(tp){
					gmin(mini,tp%10);cnt[tp%10]++;
					tp/=10;
				}
				FOR(j,0,9)num+=cnt[j]>0;
				if(num<k)rep(j,i,s.size())t*=10;
				else rep(j,i,s.size())t=t*10+mini;
				RE t;
			}
			re=re*10+now;
			if(now!=s[i]-'0')eq=0;
		}
	}
	RE re;
}
void solve(){
	int n,k;
	cin>>n>>k;
	cout<<dfs(n,k)<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	int T;
	cin>>T;
	while(T--)solve();
	io.out();
	RE 0;
}