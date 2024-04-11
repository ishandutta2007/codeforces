#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cmath>  
#include <cstring>  
#include <string>  
#include <vector>  
#include <map>  
#include <set>  
#include <iomanip>  
using namespace std;  
  
#define _ ios::sync_with_stdio(false)  
const int MAXN = 200010;  
const int INF=0x7fffffff;  
  
int n,k;  
double a[MAXN];  
double sum=0;  
int main(){  
    scanf("%d%d",&n,&k);  
    a[0]=0;  
    double s=0;  
    for(int i=1;i<=n;i++){  
        scanf("%lf",a+i);  
        sum+=a[i];  
        if(i>=k){  
            sum-=a[i-k];  
            s+=sum;  
        }  
    }  
    double y=n-k+1;  
    s/=y;  
    printf("%.12f\n",s);  
}