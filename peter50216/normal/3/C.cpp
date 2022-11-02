#include<stdio.h>
char in[4][4];
int oc=0,xc=0;
int whowin(){
    int i,j;
    int ret=0;
    for(i=0;i<3;i++){
	for(j=0;j<3;j++){
	    if(in[i][j]!=in[i][0])break;
	}
	if(j==3&&in[i][0]!='.'){
	    if(in[i][0]=='0')ret|=2;
	    else ret|=1;
	}
	for(j=0;j<3;j++){
	    if(in[j][i]!=in[0][i])break;
	}
	if(j==3&&in[0][i]!='.'){
	    if(in[0][i]=='0')ret|=2;
	    else ret|=1;
	}
    }
    for(j=0;j<3;j++){
	if(in[j][j]!=in[0][0])break;
    }
    if(j==3&&in[0][0]!='.'){
	if(in[0][0]=='0')ret|=2;
	else ret|=1;
    }
    for(j=0;j<3;j++){
	if(in[j][2-j]!=in[0][2])break;
    }
    if(j==3&&in[0][2]!='.'){
	if(in[0][2]=='0')ret|=2;
	else ret|=1;
    }
    return ret;
}
int main(){
    int i,j;
    for(i=0;i<3;i++)scanf("%s",in[i]);
    for(i=0;i<3;i++){
	for(j=0;j<3;j++){
	    if(in[i][j]=='0')oc++;
	    else if(in[i][j]=='X')xc++;
	}
    }
    try{
	bool flag=0;
	bool cand[2]={0,0};
	if(xc!=oc&&xc!=oc+1)throw "illegal";
	if(xc==0&&oc==0)throw "first";
	for(i=0;i<3;i++){
	    for(j=0;j<3;j++){
		char c=in[i][j];
		in[i][j]='.';
		int f=whowin();
		in[i][j]=c;
		if(!f){
		    flag=1;
		    if(c=='0')cand[1]=1;
		    else if(c=='X')cand[0]=1;
		}
	    }
	}
	if(!flag)throw "illegal";
	if(xc==oc){
	    if(cand[1]){
		if(whowin()==2)throw "the second player won";
		throw "first";
	    }else throw "illegal";
	}else{
	    if(cand[0]){
		if(whowin()==1)throw "the first player won";
		if(xc+oc==9)throw "draw";
		else throw "second";
	    }else throw "illegal";
	}
    }catch(const char* s){
	puts(s);
    }
}