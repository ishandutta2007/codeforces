#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a,b,sol = 0;

int main() {
    scanf("%d %d",&a,&b);
    while(a <= b){
        a *= 3;
        b *= 2;
        sol++;
    }
    printf("%d\n",sol);
}