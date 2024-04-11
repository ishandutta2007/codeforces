#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=(int)1e6+9;
int nex[N];
char s[N],ans[N];
void getnex(char p[]){
	int plen=strlen(p);
	nex[0]=-1;
	int i=0,j=-1;
	while(i<plen-1){
		if(j==-1||p[i]==p[j]){
			i++,j++;
			if(p[i]!=p[j])nex[i]=j;
			else nex[i]=nex[j];
		}
		else j=nex[j];
	}
}
int KMP(char s[],char p[]){
	int i=0,j=0,slen=strlen(s),plen=strlen(p);
	while(i<slen&&j<plen){
		if(j==-1||s[i]==p[j])i++,j++;
		else j=nex[j];
	}
	return j;
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",ans);
	int len1=strlen(ans);
	rep(i,1,n){
		scanf("%s",s);
		int len2=strlen(s),pos=0;
		getnex(s);
		if(len2<len1)pos=len1-len2;
		int pp=KMP(ans+pos,s);
		rep(j,pp,len2)ans[len1++]=s[j];
	}
	printf("%s",ans);
}