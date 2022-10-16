#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long int llint;

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,x,a[N],al = 1;
llint s;


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie()
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
        if(a[i] % 2 == 1) al = 0;
        s += llint(x);
    }
    if(al){
        printf("Second\n");
    }
    else if(s % 2 == 1){
        printf("First\n");
    }
    else{
        printf("First\n");
    }
}