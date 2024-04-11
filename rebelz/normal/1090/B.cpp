#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,now,tot,ord,len;
char s[100005],ans[105][100005];
int d[105];
string tmp,r[105];
map<string,int> mp;

int main(){
	bool flag=false,cor=true;
	while(1){
		gets(s);
		n=strlen(s);
		if(strcmp(s,"\\begin{thebibliography}{99}")==0){
			flag=true;
			continue;
		}
		if(strcmp(s,"\\end{thebibliography}")==0) break;
		if(!flag){
			for(int i=0;i<n-5;i++){
				if(s[i]=='\\'&&s[i+1]=='c'&&s[i+2]=='i'&&s[i+3]=='t'&&s[i+4]=='e'&&s[i+5]=='{'){
					now=i+6,tot++;
					r[tot].resize(100);
					while(s[now]!='}') r[tot][d[tot]++]=s[now++];
					mp[r[tot]]=tot;
				}
			}
			continue;
		}
		if(s[0]!='\\'||s[1]!='b'||s[2]!='i'||s[3]!='b'||s[4]!='i'||s[5]!='t'||s[6]!='e'||s[7]!='m'||s[8]!='{') continue;
		now=9,len=0,ord++;
		tmp.clear(); tmp.resize(100);
		while(s[now]!='}') tmp[len++]=s[now++];
		if(mp[tmp]!=ord) cor=false;
		strcpy(ans[mp[tmp]],s);
	}
	if(!cor){
		printf("Incorrect\n\\begin{thebibliography}{99}\n");
		for(int i=1;i<=tot;i++) puts(ans[i]);
		printf("\\end{thebibliography}\n");
	}
	else printf("Correct\n");
	return 0;
}