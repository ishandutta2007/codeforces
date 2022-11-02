#include<stdio.h>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
map<string,int> XD;
char tmp[100];
int main(){
    int n,m,i,j;
    double k;
    int c=0;
    scanf("%d%d%lf",&n,&m,&k);
    while(n--){
	int x;
	scanf("%s%d",tmp,&x);
	int nx=(int)(k*x+1e-8);
	if(nx>=100)XD[tmp]=nx;
    }
    while(m--){
	scanf("%s",tmp);
	if(XD.find(tmp)==XD.end())XD[tmp]=0;
    }
    printf("%d\n",XD.size());
    map<string,int>::iterator it;
    for(it=XD.begin();it!=XD.end();it++)printf("%s %d\n",it->first.c_str(),it->second);
}