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
using namespace std;
namespace io {

    #define in(a) a=read()
    #define out(a) write(a)
    #define outn(a) out(a),putchar('\n')

    #define I_int int 
    inline I_int read() {
        I_int x = 0 , f = 1 ; char c = getchar() ;
        while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; } 
        while( c >= '0' && c <= '9' ) { x = (x << 3) + (x << 1) + c - '0' ; c = getchar() ; } 
        return x * f ;
    } 
    char F[ 200 ] ;
    inline void write( I_int x ) {
        if( x == 0 ) { putchar( '0' ) ; return ; }
        I_int tmp = x > 0 ? x : -x ;
        if( x < 0 ) putchar( '-' ) ;
        int cnt = 0 ;
        while( tmp > 0 ) {
            F[ cnt ++ ] = tmp % 10 + '0' ;
            tmp /= 10 ;
        }
        while( cnt > 0 ) putchar( F[ -- cnt ] ) ;
    }
    #undef I_int

}
using namespace io ;
int type[200005],x[200005],y[200005],n,q,m; 
set<P<int,int>> num[200005];
P<int,int> nm;
void solve1(int &tx,int &ty){
	int t=ty;P<int,int> p=MP(tx,ty);
	while(t){
		num[t].insert(p);
		t-=t&-t;
	}
}
void solve2(int &tx,int &ty){
	int t=ty;;P<int,int> p=MP(tx,ty);
	while(t){
		num[t].erase(p);
		t-=t&-t;
	}
}
V<int> vx,vy;
void solve3(int &tx,int &ty){
	int t=ty;;P<int,int> p=MP(tx,ty);
	P<int,int> re=MP(n,m);
	while(t<=m){
		gmin(re,*num[t].lwb(p));
		t+=t&-t;
	}
	if(re==nm){
		outn(-1);
	}else{
		out(vx[re.F-1]);
		putchar(' ');
		outn(vy[re.S-1]);
	}
}
int main(){
	in(q);
	char s[10];
	FOR(i,1,q){
		scanf("%s",s);
		in(x[i]);in(y[i]);
		if(s[0]=='a')type[i]=1;
		else if(s[0]=='r')type[i]=2;
		else x[i]++,y[i]++,type[i]=3;
		vx.PB(x[i]);vy.PB(y[i]);
	}
	sort(ALL(vx));
	vx.erase(unique(ALL(vx)),vx.end());
	sort(ALL(vy));
	vy.erase(unique(ALL(vy)),vy.end());
	FOR(i,1,q){
		x[i]=lwb(ALL(vx),x[i])-vx.begin()+1;
		y[i]=lwb(ALL(vy),y[i])-vy.begin()+1;
	}
	n=vx.size()+1;m=vy.size()+1;nm=MP(n,m);
	FOR(i,1,m)num[i].insert(nm);
	FOR(i,1,q){
		if(type[i]==1){
			solve1(x[i],y[i]);
		}else if(type[i]==2){
			solve2(x[i],y[i]);
		}else{
			solve3(x[i],y[i]);
		}
	}
	RE 0;
}