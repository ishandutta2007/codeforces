#include<cstdio>
using namespace std;

int main(){
    double L,p,q;
    scanf("%lf%lf%lf",&L,&p,&q);
    printf("%.15lf\n",p*L/(p+q));
    return 0;
}