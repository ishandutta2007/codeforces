#include <stdio.h>
#include <string.h>
#include <algorithm>
typedef long long ll;
const int INF = 0x7fffffff;

using std::min;

int n,k,a[10];
char s[20];

ll fun3(int cp,ll tt,bool hd,bool gt){
	if(s[cp]=='\0') return tt;
	if(gt) return fun3(cp+1,tt*10+a[0],false,true);
	ll ret = INF;
	for(int i=0;i<k;i++){
		if(a[i]<s[cp]-'0') continue;
		if(a[i]==0&&hd) continue;
		if(a[i]==s[cp]-'0')
			ret = fun3(cp+1,tt*10+a[i],false,false);
		if(a[i]>s[cp]-'0')
			return min(ret,fun3(cp+1,tt*10+a[i],false,true));
	}
	return ret;
}

int fun2(){
	return min(fun3(0,0,true,false),fun3(1,0,true,false));
}

int fun1(int uk,int w){
	if(uk==k) return fun2();
	if(w>9) return INF;
	int ret = fun1(uk,w+1);
	a[uk] = w;
	return min(ret,fun1(uk+1,w+1));
}

void solve(){
	scanf("%s%d",&s[1],&k);
	s[0] = '0';
	n = strlen(&s[1]);
	printf("%d\n",fun1(0,0));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}