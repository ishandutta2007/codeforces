#include <cstdio>
#include <algorithm>
using namespace std;

int dfcnt[5000];

int n;
int data[2010];

typedef long long ll;

ll df2[5000];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i) scanf("%d",data+i);
    sort(data,data+n);
    int j;
    for(i=0;i<n;++i){
        for(j=0;j<i;++j){
            ++dfcnt[data[i]-data[j]];
        }
    }
    for(i=1;i<5000;++i){
        for(j=1;i+j<5000;++j){
            df2[i+j]+=dfcnt[i]*1LL*dfcnt[j];
        }
    }
    ll anscnt=0;
    int cursum=0;
    for(i=4999;i>=1;--i){
        cursum+=dfcnt[i];
        anscnt += cursum*df2[i-1];
    }
    ll allchose=n*(n-1)/2;
    allchose = allchose*allchose*allchose;
    printf("%.10f\n",anscnt*1.0/allchose);
    return 0;
}