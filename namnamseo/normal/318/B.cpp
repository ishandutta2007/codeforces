#include <iostream>

char buffer[1000010];
long long ans = 0;

int state;
/// 0 : other
/// 1 ~ 5 : heavy
/// 6 ~ 10 : metal
char heavy[10]="heavy";
char metal[10]="metal";

int main()
{
    std::cin>>buffer;
    int heavycount = 0;
    state=0;
    int j;
    bool h,m;
    for(int i=4;buffer[i];i++){
        h=true; m=true;
        for(j=i-4;j<=i;j++){
            if(heavy[j-i+4]!=buffer[j]) h=false;
            if(metal[j-i+4]!=buffer[j]) m=false;
        }
        if(h) heavycount++;
        if(m) ans+=heavycount;
    }
    std::cout<<ans;
    return 0;
}