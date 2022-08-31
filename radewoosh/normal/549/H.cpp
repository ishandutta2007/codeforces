#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long a, b, c, d;

double bsa, bsb, bss;

double zakla, zakpa;
double zaklb, zakpb;
double zaklc, zakpc;
double zakld, zakpd;

double zakle, zakpe;
double zaklf, zakpf;

int main()
{
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    bsa=0;
    bsb=1000000000.0;
    for (int h=1; h<=100000 && bsa<bsb; h++)
    {
        bss=(bsa+bsb)/2;
        zakla=a-bss;
        zakpa=a+bss;

        zaklb=b-bss;
        zakpb=b+bss;

        zaklc=c-bss;
        zakpc=c+bss;

        zakld=d-bss;
        zakpd=d+bss;

        zakle=min(min(zakla*zakld, zakla*zakpd) , min(zakpa*zakld, zakpa*zakpd));
        zakpe=max(max(zakla*zakld, zakla*zakpd) , max(zakpa*zakld, zakpa*zakpd));

        zaklf=min(min(zaklc*zaklb, zaklc*zakpb) , min(zakpc*zaklb, zakpc*zakpb));
        zakpf=max(max(zaklc*zaklb, zaklc*zakpb) , max(zakpc*zaklb, zakpc*zakpb));

        if (zakle<=zakpf && zakpe>=zaklf)
        {
            bsb=bss;
        }
        else
        {
            bsa=bss;
        }
    }
    printf("%.11lf", bsa);
    return 0;
}