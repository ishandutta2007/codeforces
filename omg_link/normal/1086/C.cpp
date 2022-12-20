#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MN 1000000
int n,k,p[26];
bool e[26],u[26],te[26],tu[26];
char s[MN+5],a[MN+5],b[MN+5];
void autocomplete(){
	int i,j;
	for(i=0,j=0;i<k;i++){
		if(e[i]) continue;
		while(u[j]) j++;
		p[i]=j;
		e[i]=true;
		u[j]=true;
	}
	puts("YES");
	for(int i=0;i<k;i++)
		printf("%c",p[i]+'a');
	puts("");
}
bool bigger(int i){
	for(;i<=n;i++){
		if(e[s[i]-'a']){
			if(p[s[i]-'a']<a[i]-'a') return false;
			if(p[s[i]-'a']>a[i]-'a') return true;
		}else{
			for(int j=a[i]-'a'+1;j<k;j++)
				if(!u[j]){
					p[s[i]-'a']=j;
					e[s[i]-'a']=true;
					u[j]=true;
					return true;
				}
			if(!u[a[i]-'a']){
				p[s[i]-'a']=a[i]-'a';
				e[s[i]-'a']=true;
				u[a[i]-'a']=true;
				continue;
			}
			return false;
		}
	}
	return true;
}
bool smaller(int i){
	for(;i<=n;i++){
		if(e[s[i]-'a']){
			if(p[s[i]-'a']>b[i]-'a') return false;
			if(p[s[i]-'a']<b[i]-'a') return true;
		}else{
			for(int j=0;j<=b[i]-'a'-1;j++)
				if(!u[j]){
					p[s[i]-'a']=j;
					e[s[i]-'a']=true;
					u[j]=true;
					return true;
				}
			if(!u[b[i]-'a']){
				p[s[i]-'a']=b[i]-'a';
				e[s[i]-'a']=true;
				u[b[i]-'a']=true;
				continue;
			}
			return false;
		}
	}
	return true;
}
void solve(int T){
	scanf("%d%s%s%s",&k,&s[1],&a[1],&b[1]);
	n=strlen(&s[1]);
	memset(e,0,sizeof(e));
	memset(u,0,sizeof(u));
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]){
			if(!e[s[i]-'a']){
				if(!u[a[i]-'a']){
					p[s[i]-'a']=a[i]-'a';
					e[s[i]-'a']=true;
					u[a[i]-'a']=true;
				}else{
					puts("NO");
					return;
				}
			}else{
				if(p[s[i]-'a']!=a[i]-'a'){
					puts("NO");
					return;
				}
			}
		}else{
			if(e[s[i]-'a']){
				if(a[i]-'a'+1<=p[s[i]-'a']&&p[s[i]-'a']<=b[i]-'a'-1){
					autocomplete();
					return;
				}
				if(p[s[i]-'a']==a[i]-'a'){
					if(bigger(i+1)){
						autocomplete();
						return;
					}
				}
				if(p[s[i]-'a']==b[i]-'a'){
					if(smaller(i+1)){
						autocomplete();
						return;
					}
				}
				puts("NO");
				return;
			}else{
				for(int j=a[i]-'a'+1;j<=b[i]-'a'-1;j++)
					if(!u[j]){
						p[s[i]-'a']=j;
						e[s[i]-'a']=true;
						u[j]=true;
						autocomplete();
						return;
					}
				if(!u[a[i]-'a']){
					p[s[i]-'a']=a[i]-'a';
					for(int i=0;i<26;i++){
						te[i]=e[i];
						tu[i]=u[i];
					}
					e[s[i]-'a']=true;
					u[a[i]-'a']=true;
					if(bigger(i+1)){
						autocomplete();
						return;
					}
					for(int i=0;i<26;i++){
						e[i]=te[i];
						u[i]=tu[i];
					}
				}
				if(!u[b[i]-'a']){
					p[s[i]-'a']=b[i]-'a';
					e[s[i]-'a']=true;
					u[b[i]-'a']=true;
					for(int i=0;i<26;i++){
						te[i]=e[i];
						tu[i]=u[i];
					}
					if(smaller(i+1)){
						autocomplete();
						return;
					}
					for(int i=0;i<26;i++){
						e[i]=te[i];
						u[i]=tu[i];
					}
				}
				puts("NO");
				return;
			}
		}
	}
	autocomplete();
}
int main(){
	int T; scanf("%d",&T);
	for(int t=1;t<=T;t++) solve(t);
}