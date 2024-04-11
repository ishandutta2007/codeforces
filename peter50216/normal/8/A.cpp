#include<stdio.h>
long long ha[100100];
char in[100100];
char a[100100],b[100100];
long long pow[100100];
const long long p=51451451;
inline long long hash(int a,int l){
    return ha[a+l]-ha[a]*pow[l];
}
inline bool match(int i,long long as,int al){
    return hash(i,al)==as;
}
int main(){
    int i,j;
    scanf("%s%s%s",in,a,b);
    ha[0]=0;
    pow[0]=1;
    for(i=0;in[i];i++){
	pow[i+1]=pow[i]*p;
	ha[i+1]=ha[i]*p+in[i];
    }
    int l=i;
    long long aa=0,bb=0;
    for(i=0;a[i];i++)aa=aa*p+a[i];
    int al=i;
    for(i=0;b[i];i++)bb=bb*p+b[i];
    int bl=i;
    int f=0;
    for(i=0;i<=l-al;i++)if(match(i,aa,al))break;
    if(i<=l-al){
	for(i=i+al;i<=l-bl;i++)if(match(i,bb,bl))break;
	if(i<=l-bl)f++;
    }
    for(i=0,j=l-1;i<j;i++,j--){
	char t=in[i];in[i]=in[j];in[j]=t;
    }
    for(i=0;in[i];i++){
	ha[i+1]=ha[i]*p+in[i];
    }
    for(i=0;i<=l-al;i++)if(match(i,aa,al))break;
    if(i<=l-al){
	for(i=i+al;i<=l-bl;i++)if(match(i,bb,bl))break;
	if(i<=l-bl)f+=2;
    }
    puts(f==3?"both":f==2?"backward":f==1?"forward":"fantasy");
}