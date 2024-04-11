#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<string,int> XD,XDD;
char in[1010][35];
int sc[1010];
int main(){
    int n,i;
    scanf("%d",&n);
    int ma=0;
    for(i=0;i<n;i++){
	scanf("%s%d",in[i],&sc[i]);
	XD[in[i]]+=sc[i];
    }
    for(i=0;i<n;i++)ma=max(ma,XD[in[i]]);
    for(i=0;i<n;i++){
	XDD[in[i]]+=sc[i];
	if(XD[in[i]]==ma&&XDD[in[i]]>=ma)break;
    }
    printf("%s\n",in[i]);
}