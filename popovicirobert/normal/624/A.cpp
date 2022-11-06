#include <cstdio>

int main()
{
    double d,l,v1,v2;
    scanf("%lf %lf %lf %lf" ,&d,&l,&v1,&v2);
    printf("%lf" ,(l-d)/(v1+v2));
    return 0;
}