#include<bitset>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100000;
bitset<maxn+10> a[26],b;
char s[maxn+10],t[maxn+10]; int q,n;
int main(){
	scanf("%s%d",s,&q); n=strlen(s);
	for(int i=0;i<n;++i) a[s[i]-'a'][i]=1;
	for(int op,l,r;q--;){
		scanf("%d%d",&op,&l);
		if(op==1){
			--l;
			scanf("%s",t); a[s[l]-'a'][l]=0; a[(s[l]=t[0])-'a'][l]=1;
		}else{
			scanf("%d%s",&r,t); n=strlen(t); b.set();
			for(int i=0;i<n;++i) b&=a[t[i]-'a']>>i;
			printf("%d\n",r-l+1<n?0:(b>>l-1).count()-(b>>r-n+1).count());
		}
	}
}