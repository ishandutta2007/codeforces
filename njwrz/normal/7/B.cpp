#include<bits/stdc++.h>
using namespace std;
namespace io {

    #define in(a) a=read()
    #define out(a) write(a),putchar(' ')
    #define outn(a) out(a),putchar('\n')

    #define I_int int
    inline I_int read() {
        I_int x = 0 , f = 1 ; char c = getchar() ;
        while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; }
        while( c >= '0' && c <= '9' ) { x = x * 10 + c - '0' ; c = getchar() ; }
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
struct node{
	int f,id;
}a[101];
using namespace io ;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,i,k,t,ans=0,j;string s;
	cin>>n>>m;
	for(k=0;k<n;k++){
		cin>>s;
		if(s[0]=='a'){
			cin>>t;
			int l=0;bool x=1;
			for(i=1;i<=m;i++){
				if(a[i].f==0)l++;else l=0;
				if(l==t){
					ans++;
					for(j=i-t+1;j<=i;j++){
						a[j].f=1;a[j].id=ans;
					}
					cout<<ans<<'\n';x=0;break;
				}
			}
			if(x){
				cout<<"NULL"<<'\n';
			}
		}else if(s[0]=='e'){
			cin>>t;bool x=1;
			for(i=1;i<=m;i++){
				if(a[i].id==t&&a[i].f){
					a[i].f=0;a[i].id=0;x=0;
				}
			}
			if(x){
				cout<<"ILLEGAL_ERASE_ARGUMENT\n";
			}
		}else{
			t=1;
			for(i=1;i<=m;i++){
				if(a[i].f){
					int abc=a[i].id;a[i].f=0;a[i].id=0;
					a[t].f=1;a[t].id=abc;t++;
				}
			}
		}
	}
	return 0;
}