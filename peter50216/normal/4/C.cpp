#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
char in[1010];
char tmp[1010];
map<string,int> XD;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
	scanf("%s",in);
	if(XD.find(in)==XD.end()){
	    XD[in]=1;
	    puts("OK");
	}else{
	    printf("%s%d\n",in,XD[in]++);
	}
    }
}