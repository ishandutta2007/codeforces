#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int n,m,t;
int main()
{
    int x;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        m--;
        int sum=0;
        for(int i=0;i<n-1;i++){
            scanf("%d",&x);
            sum+=x-1;
        }
        for(int i=0;i<n;i++){
            if((sum+i)%n==m){
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}