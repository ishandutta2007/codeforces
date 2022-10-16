#include <iostream>
#include <cstdio>

using namespace std;

typedef long long int llint;

llint sol = 0,cnt = 0;

int main(){
    llint n,cur;
    scanf("%I64d%I64d",&n,&cnt);
    for(int i = 0;i<n;i++){
        char c;
        cin >> c >> cur;
        if(c == '+') cnt+=cur;
        else{
            if(cur > cnt) sol++;
            else cnt-=cur;
        }
    }
    printf("%I64d %I64d\n",cnt,sol);
}