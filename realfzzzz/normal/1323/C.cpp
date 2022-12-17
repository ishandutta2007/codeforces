#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
    int x=0;
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
const int maxn=1e6+5;
int n;
char s[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    scanf("%s",s);
    int ans=0;
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
    	if(s[i]=='('){
    		cnt0++;
    		if(cnt2>=0) cnt2++;
		}
		else{
			cnt1++;
			if(cnt2>0) cnt2--;
			else cnt2=-1;
		}
		if(cnt0==cnt1){
			if(cnt2<0) ans+=cnt0+cnt1;
			cnt0=cnt1=cnt2=0;
		}
	}
	if(cnt0!=cnt1) printf("-1\n");
	else{
		if(cnt2<0) ans+=cnt0+cnt1;
		printf("%d\n",ans);
	}
    return 0;
}