#include<string.h>
#include<stdio.h>
char in[110][110];
char str[110];
char ori[110];
char tmp[110];
void tolow(char& a){
    if(a>='A'&&a<='Z')a-=(int)'A'-'a';
}
void tohigh(char& a){
    if(a>='a'&&a<='z')a-=(int)'a'-'A';
}
void tosame(char* a,char* b){
    for(int i=0;a[i];i++){
	if(b[i]>='a'&&b[i]<='z')tolow(a[i]);
	else tohigh(a[i]);
    }
}
inline int cnt(char* a,char c){
    int r=0;
    for(int i=0;a[i];i++)if(a[i]==c)r++;
    return r;
}
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%s",in[i]);
	for(j=0;in[i][j];j++)tolow(in[i][j]);
    }
    scanf("%s",str);
    strcpy(ori,str);
    for(i=0;str[i];i++)tolow(str[i]);
    char cc[2],c;
    scanf("%s",cc);
    c=cc[0];
    strcpy(tmp,str);
    for(i=0;i<n;i++){
	int l=strlen(str),n=strlen(in[i]);
	if(n>l)continue;
	for(j=0;j<=l-n;j++){
	    if(strncmp(str+j,in[i],n)==0){
		for(k=j;k<j+n;k++){
		    if(str[k]==c){
			if(c=='a')tmp[k]='b';
			else tmp[k]='a';
		    }else{
			tmp[k]=c;
		    }
		}
	    }
	}
    }
    tosame(tmp,ori);
    puts(tmp);
}