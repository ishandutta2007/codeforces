#include <cstdio>

using namespace std;

int n,m[100],r[100];
double sum1,sum2;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&m[i]);
    }
    for(int i = 0;i<n;i++){
        scanf("%d",&r[i]);
    }
    for(int i = 0;i<1000000;i++){
        double x=1;
        for(int j = 0;j<n;j++) if(i%m[j]==r[j]) {sum1+=1.0;x=0;break;}
        sum2+=x;
    }
    printf("%f",sum1/1000000);
}