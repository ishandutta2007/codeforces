#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
ll all[2001000];
inline ll lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}
string name[2]={"Dasha","Masha"};
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b){
    swap(a,b);
    swap(name[0],name[1]);
    }
    ll t=lcm(a,b);
    int c=0;
    ll i;
    for(i=1;i<=t/a;i++)all[c++]=i*a;
    int mc=c;
    for(i=0;i<t/b;i++)all[c++]=i*b;
    inplace_merge(all,all+mc,all+c);
    ll t1=0,t2=0;
    for(i=0;i<c-1;i++){
    if(all[i+1]%b==0)t2+=all[i+1]-all[i];
    else t1+=all[i+1]-all[i];
    }
    puts(t1==t2?"Equal":t1>t2?name[0].c_str():name[1].c_str());
}