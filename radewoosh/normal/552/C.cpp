#include <cstdio>
#include <vector>
using namespace std;

long long n, w;

vector <long long> wek;

long long x;

int main()
{
    scanf("%lld%lld", &w, &n);
    if (w==2)
    {
        printf("YES");
        return 0;
    }
    while(n)
    {
        wek.push_back(n%w);
        n/=w;
    }
    for (int i=0; i<wek.size(); i++)
    {
        if (wek[i]<-1 || wek[i]>1)
        {
            if (i+1==wek.size())
            wek.push_back(0);
            if (wek[i]<-1 && wek[i]+w>1)
            {
                printf("NO");
                return 0;
            }
            if (wek[i]>1 && wek[i]-w<-1)
            {
                printf("NO");
                return 0;
            }
            if (wek[i]<-1)
            {
                x=(-wek[i])/w;
                wek[i]+=x*w;
                wek[i+1]-=x;
            }
            if (wek[i]>1)
            {
                x=wek[i]/w;
                wek[i]-=x*w;
                wek[i+1]+=x;
            }
            while(wek[i]<-1)
            {
                wek[i]+=w;
                wek[i+1]--;
            }
            while(wek[i]>1)
            {
                wek[i]-=w;
                wek[i+1]++;
            }
        }
        else
        {
            if (i==wek.size()-1)
            {
                break;
            }
        }
        if (wek.size()>1000)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}