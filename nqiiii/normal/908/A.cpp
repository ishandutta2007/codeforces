#include<cstdio>
#include<cstring>
const int maxn=50;
char s[maxn+10]; int ans;
int main(){
	scanf("%s",s); int l=strlen(s);
	for(int i=0;i<l;++i)
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
			s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9') ++ans;
	printf("%d",ans); return 0;
}