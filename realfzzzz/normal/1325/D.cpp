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
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    ll u,v;
    u=readint();
    v=readint();
    if(u>v||u%2!=v%2) printf("-1\n");
	else if(u==0&&v==0) printf("0\n");
	else if(u==v) printf("1\n%lld\n",u);
	else if(!(u&(v-u)/2)) printf("2\n%lld %lld\n",u+(v-u)/2,(v-u)/2);
	else printf("3\n%lld %lld %lld\n",u,(v-u)/2,(v-u)/2);
    return 0;
}