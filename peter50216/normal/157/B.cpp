#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const double pi=acos(-1);
int s[1000];
inline bool cmp(int a,int b){return a>b;}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&s[i]);
    sort(s,s+n,cmp);
    if(n%2){
        s[n++]=0;
    }
    int ss=0;
    for(i=0;i<n;i+=2){
        ss+=s[i]*s[i]-s[i+1]*s[i+1];
    }
    printf("%.10lf\n",pi*ss);
}