#include<stdio.h>
#include<string.h>
int pow[12];
char in[100];
char c[100];
int rn,cn;

char tmp[100];
inline int ton(const char* s){
    int l=strlen(s),i,ans=0;
    for(i=1;i<l;i++)ans+=pow[i];
    for(i=0;i<l;i++)ans+=(s[i]-'A')*pow[l-1-i];
    return ans+1;
}
inline const char* tos(int n){
    n--;
    int i,l;
    for(l=1;;l++){
	if(n<pow[l])break;
	n-=pow[l];
    }
    for(i=0;i<l;i++){
	tmp[i]=(n/pow[l-1-i])%26+'A';
    }
    tmp[l]=0;
    return tmp;
}
int main(){
    int t,i,j;
    pow[0]=1;
    for(i=1;i<12;i++)pow[i]=pow[i-1]*26;
    scanf("%d",&t);
    while(t--){
	scanf("%s",in);
	tmp[0]=0;
	sscanf(in,"%[A-Z]%d%s",c,&rn,tmp);
	if(tmp[0]){
	    sscanf(in,"R%dC%d",&rn,&cn);
	    printf("%s%d\n",tos(cn),rn);
	}else{
	    printf("R%dC%d\n",rn,ton(c));
	}
    }
}
//1506308  1B  Spreadsheet  Accepted  GNU C++  190 ms  Apr 9, 2012 12:18:29 PM