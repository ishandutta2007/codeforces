#include<stdio.h>
#include<algorithm>
using namespace std;
pair<int,int> in[1010];
int main(){
    int n,t,i;
    int a=2;
    scanf("%d%d",&n,&t);
    for(i=0;i<n;i++)scanf("%d%d",&in[i].first,&in[i].second);
    sort(in,in+n);
    for(i=0;i<n-1;i++){
	int r=(2*(in[i+1].first-in[i].first)-in[i].second-in[i+1].second-2*t);
	a+=(r>=0)+(r>0);
    }
    printf("%d\n",a);
}