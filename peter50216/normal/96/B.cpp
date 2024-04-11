#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char in[100100];
int cont7[100100];
int less4[100100];
int main(){
    gets(in+2);
    int n=strlen(in+2);
    in[0]=in[1]='0';
    int i,j;
    for(i=n+1;i>=2;i--){
	if(in[i]>='8'){
	    in[i]='0';
	    in[i-1]++;
	}
    }
    int l=2;
    if(in[l-1]>'0'){
	l--;
	n++;
    }
    if(n%2==1){
	l--;
	n++;
    }
    int cc=0;
    for(i=l;i<l+n;i++){
	if(in[i]>'4')cc++;
	else break;
    }
    if(cc>n/2){
	l-=2;
	n+=2;
    }
    cont7[n+l]=0;
    less4[n+l]=1;
    for(i=n+l-1;i>=l;i--){
	if(in[i]>'4')cont7[i]=cont7[i+1]+1;
	else cont7[i]=0;
    }
    for(i=n+l-1;i>=l;i--){
	if(in[i]>'4')less4[i]=0;
	else if(in[i]<'4')less4[i]=1;
	else{
	    less4[i]=less4[i+1];
	}
    }
    int cnt4=n/2,cnt7=n/2;
    bool flag=0;
    for(i=l;i<l+n;i++){
	if(in[i]=='7'){
	    cnt7--;
	}else if(in[i]=='4'){
	    if(cnt4){
		if(cont7[i+1]>cnt7){
		    flag=1;
		    break;
		}else if(cont7[i+1]==cnt7){
		    if(!less4[i+1+cont7[i+1]]){
			flag=1;
			break;
		    }
		}
		cnt4--;
	    }else break;
	}else break;
    }
    if(i<l+n){
	if(in[i]>'4'||cnt4==0||flag){
	    in[i]='7';
	    cnt7--;
	}else{
	    in[i]='4';
	    cnt4--;
	}
	i++;
	for(;cnt4--;i++)in[i]='4';
	for(;cnt7--;i++)in[i]='7';
    }
    puts(in+l);
}