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
double start=clock();
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

int d[55],k,a[55][55],in[55],n;
P<int,int> p[55],ed[1300];
int fa[55];
int getfa(int x){
	RE (fa[x]==x)?x:(fa[x]=getfa(fa[x]));
}
void merge(int x,int y){
	x=getfa(x);
	y=getfa(y);
	fa[x]=y;
}
bool cmp(P<int,int> x,P<int,int> y){
	RE a[x.F][x.S]<a[y.F][y.S];
}
int ans=1e9;
void check(){
	int cnt=0;
	FOR(i,1,n)fa[i]=i,in[i]=0;
	FOR(i,1,n)FOR(j,i+1,n)ed[++cnt]=MP(i,j);
	sort(ed+1,ed+cnt+1,cmp);
	int len=0;
	FOR(i,1,cnt){
		if(getfa(ed[i].F)!=getfa(ed[i].S)){
			p[++len]=ed[i];
			merge(ed[i].F,ed[i].S);
			in[ed[i].F]++;in[ed[i].S]++;
		}
	}
	int val=0;
	FOR(i,1,k){
		val+=max(0,in[i]-d[i]);
	}
	while(val){
//		cout<<val<<' ';
		sort(p+1,p+len+1,cmp);
		P<int,int> era;
		for(int i=len;i>=1;i--)if(in[p[i].F]>d[p[i].F]||in[p[i].S]>d[p[i].S]){
			if(rand()%4!=0){
				in[p[i].F]--;in[p[i].S]--;era=p[i];
				len=0;
				FOR(j,1,n-1)if(j!=i){
					p[++len]=p[j];
				}
				break;
			}
		}
		if(len==n-1)continue;
		int t=rand()%8;
		FOR(i,1,n)fa[i]=i;
		FOR(i,1,len)merge(p[i].F,p[i].S);
		FOR(i,1,cnt)if(ed[i]!=era&&getfa(ed[i].F)!=getfa(ed[i].S)&&(!t||(in[ed[i].F]<=d[ed[i].F]&&in[ed[i].S]<=d[ed[i].S]))){
			if(rand()%4!=0){
				in[ed[i].F]++;in[ed[i].S]++;
				p[++len]=ed[i];
				break;
			}
		}
		if(len<n-1)p[++len]=era,in[era.F]++,in[era.S]++;
		val=0;
		FOR(i,1,k)val+=max(0,in[i]-d[i]);
	}
	int sum=0;
	FOR(i,1,n-1)sum+=a[p[i].F][p[i].S];
	gmin(ans,sum);
}
signed main(){
	srand(time(0));
	io.init();
	cin>>n>>k;
	FOR(i,1,k)cin>>d[i];
	FOR(i,k+1,n)d[i]=1e9;
	FOR(i,1,n){
		FOR(j,i+1,n)cin>>a[i][j],a[j][i]=a[i][j];
	}
	check();
	while(clock()<start+CLOCKS_PER_SEC*5.5)check();
	cout<<ans;
	io.out();
	RE 0;
}