#include<stdio.h>
int n,s,c;
int cd;
char tmp[100];
int dt=-1;
inline void wc(){
    if(c==1)cd=1;
    else if(c==n)cd=-1;
    c+=cd;
}
char in[10000];
inline int nt(int x){
    if(x==c)return 0;
    else if(cd==1){
	if(x>c)return x-c;
	return c-x+n;
    }else{
	if(x<c)return c-x;
	return x-c+n;
    }
}
inline void w0(int t){
    if(dt!=-1)return;
    int mt=-1,mp=-2;
    for(int d=-1;d<=1;d++){
	if(s+d>0&&s+d<=n&&nt(s+d)>mt){
	    mt=nt(s+d);
	    mp=s+d;
	}
    }
    s=mp;
    wc();
    if(c==s)dt=t;
}
inline void w1(int t){
    if(dt!=-1)return;
    wc();
    int mt=-1,mp=-2;
    for(int i=1;i<=n;i++){
	if(nt(i)>mt){
	    mt=nt(i);
	    mp=i;
	}
    }
    s=mp;
    if(c==s)dt=t;
}
int main(){
    scanf("%d%d%d",&n,&s,&c);
    scanf("%*s%s",tmp);
    if(tmp[0]=='h')cd=-1;
    else cd=1;
    scanf("%s",in);
    for(int i=0;in[i];i++){
	if(in[i]=='0')w0(i);
	else w1(i);
    }
    if(dt==-1)puts("Stowaway");
    else printf("Controller %d\n",dt+1);
}