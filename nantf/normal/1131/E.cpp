#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,cont[100010][26],s[26];
char str[maxn];
inline void chkmax(int &x,int y){
	if(y>x) x=y;
}
int main(){
	n=read();
	FOR(nn,1,n){
		scanf("%s",str+1);
		int len=strlen(str+1);
		int cnt=1;
		FOR(i,1,len)
			if(str[i]!=str[i+1]){
				chkmax(cont[nn][str[i]-'a'],cnt);
				cnt=1;
			}
			else cnt++;
		int lcnt=1,rcnt=1;
		FOR(i,2,len){
			if(str[i]==str[1]) lcnt++;
			else break;
		}
		ROF(i,len-1,1){
			if(str[i]==str[len]) rcnt++;
			else break;
		}
		if(nn!=1){
			if(lcnt==len && rcnt==len) chkmax(cont[nn][str[1]-'a'],len*(cont[nn-1][str[1]-'a']+1)+cont[nn-1][str[1]-'a']);
			else if(str[1]==str[len]){
				if(cont[nn-1][str[1]-'a']) chkmax(cont[nn][str[1]-'a'],lcnt+rcnt+1);
				else chkmax(cont[nn][str[1]-'a'],max(lcnt,rcnt)+1);
			}
			else{
				chkmax(cont[nn][str[1]-'a'],lcnt+!!cont[nn-1][str[1]-'a']);
				chkmax(cont[nn][str[len]-'a'],rcnt+!!cont[nn-1][str[len]-'a']);
			}
		}
		FOR(i,0,25) chkmax(cont[nn][i],!!cont[nn-1][i]);
	}
	int res=0;
	FOR(i,0,25) res=max(res,cont[n][i]);
	printf("%d\n",res);
}