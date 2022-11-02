#include<stdio.h>
#include<algorithm>
using namespace std;
char in[10];
char all[800][10];
inline bool id(char* a,char* b){
    int i;
    for(i=0;i<6;i++)if(a[i]!=b[i])return 0;
    return 1;
}
inline void rot(char* a){
    char c=a[1];a[1]=a[2];a[2]=a[3];a[3]=a[4];a[4]=c;
}
inline void rot2(char* a){
    char c=a[0];a[0]=a[2];a[2]=a[5];a[5]=a[4];a[4]=c;
}
inline void rot3(char* a){
    char c=a[0];a[0]=a[3];a[3]=a[5];a[5]=a[1];a[1]=c;
}
inline bool same(char* a,char* b){
    char c[6];
    int i,j;
    for(i=0;i<6;i++)c[i]=b[i];
    for(i=0;i<4;i++){
	for(j=0;j<4;j++){
	    if(id(a,c))return 1;
	    rot(c);
	}
	rot2(c);
    }
    for(i=0;i<4;i++){
	for(j=0;j<4;j++){
	    if(id(a,c))return 1;
	    rot(c);
	}
	rot3(c);
    }
    return 0;
}
int main(){
    scanf("%s",in);
    sort(in,in+6);
    int ac=0;
    do{
	int i;
	for(i=0;i<ac;i++)if(same(all[i],in))break;
	if(i==ac){
	    for(i=0;i<6;i++)all[ac][i]=in[i];
	    ac++;
	}
    }while(next_permutation(in,in+6));
    printf("%d\n",ac);
}