#include<algorithm>
#include<cctype>
#include<cstdio>
using namespace std;
typedef long long ll;
inline ll readint(){
    ll x=0;
    bool f=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-'){
        f=1;
        c=getchar();
    }
	while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f?-x:x;
}
const int maxn=3e5+5;
int n;
ll a[maxn],b[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    while(t--){
    	n=readint();
    	for(int i=0;i<n;i++){
    		a[i]=readint();
    		b[i]=readint();
		}
		ll ans=0;
		for(int i=0;i<n;i++) if(b[i]<a[(i+1)%n]){
			ans+=a[(i+1)%n]-b[i];
			a[(i+1)%n]=b[i];
		}
		ll res=9e18;
		for(int i=0;i<n;i++) res=min(res,a[i]);
		printf("%lld\n",ans+res);
	}
    return 0;
}