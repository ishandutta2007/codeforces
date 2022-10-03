#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
char s[4],t[4];
int main(){
	puts("YES");
	scanf("%d%s%s",&n,s,t);
	if(s[0]==s[1]&&t[0]==t[1]){F(i,1,n)printf("abc");return 0;}
	if(t[0]==t[1])swap(s,t);
	if(s[0]==s[1]){
		char a=*s,b=t[1],c=t[0];
		if(t[0]==*s||t[1]==*s)c=t[0]^t[1]^*s,b='a'^'b'^'c'^a^c;
		F(i,1,n)printf("%c%c",a,b);
		F(i,1,n)printf("%c",c);
		return 0;
	}
	char a,b,c;
	if(s[1]==t[0]&&s[0]==t[1])a=s[0],c=s[1],b='a'^'b'^'c'^a^c;
	else if(s[0]==t[0]&&s[1]==t[1])a=s[1],b=s[0],c='a'^'b'^'c'^a^b;
	else if(s[1]==t[0])a=t[1],b=t[0],c=s[0];
	else if(t[1]==s[0])a=s[1],b=s[0],c=t[0];
	else if(s[0]==t[0])c=s[0],a=(c-'a'+1)%3+'a',b='a'^'b'^'c'^a^c;
	else if(s[1]==t[1])a=s[1],b=(a-'a'+1)%3+'a',c='a'^'b'^'c'^a^b;
	else a='a',b='b',c='c';
	F(i,1,n)printf("%c",a);
	F(i,1,n)printf("%c",b);
	F(i,1,n)printf("%c",c);
	return 0;
}