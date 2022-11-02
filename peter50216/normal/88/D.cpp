#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
using namespace std;
map<string,int> XD;
void print(int x){
    if(x==-1)puts("errtype");
    else{
	printf("void");
	while(x--)printf("*");
	puts("");
    }
}
int resolve(string s){
    int i;
    for(i=0;s[i]=='&';i++);
    int dc=i;
    for(i=s.size()-1;s[i]=='*';i--);
    int cc=(s.size()-1-i);
    string tmp=s.substr(dc,i-dc+1);
    cc-=dc;
    if(XD.find(tmp)==XD.end())return -1;
    if(XD[tmp]==-1)return -1;
    return max(XD[tmp]+cc,-1);
}
char a[1000],b[1000];
int main(){
    int q;
    scanf("%d",&q);
    XD["void"]=0;
    XD["errtype"]=-1;
    while(q--){
	char cmd[10];
	scanf("%s",cmd);
	if(strcmp(cmd,"typedef")==0){
	    scanf("%s%s",a,b);
	    XD[b]=resolve(a);
	}else{
	    scanf("%s",a);
	    print(resolve(a));
	}
    }
}