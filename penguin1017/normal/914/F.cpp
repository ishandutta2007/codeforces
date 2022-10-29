#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e5+9;
bitset<N> a[26],ans;
char s1[N],s2[N];
int main(){
	scanf("%s",s1+1);
	int len=strlen(s1+1);
	rep(i,1,len+1)a[s1[i]-'a'][i]=1;
	int q;
	scanf("%d",&q);
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int i;
			char c[2];
			scanf("%d%s",&i,c);
			a[s1[i]-'a'][i]=0;
			s1[i]=c[0];
			a[s1[i]-'a'][i]=1;
		}
		else{
			int l,r;
			scanf("%d%d%s",&l,&r,s2+1);
			len=strlen(s2+1);
			if(r-l+1<len){
				printf("0\n");
				continue;
			}
			ans.set();
			rep(i,1,len+1)ans&=a[s2[i]-'a']>>i;
			int res=(ans>>(l-1)).count()-(ans>>(r-len+1)).count();
			printf("%d\n",res);
		}
	}
}