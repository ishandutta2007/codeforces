#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int a, b;

int main(){
    scanf("%d %d", &a, &b);
    switch(max(a,b)){
        case 1: printf("1/1\n"); break;
        case 2: printf("5/6\n"); break;
        case 3: printf("2/3\n"); break;
        case 4: printf("1/2\n"); break;
        case 5: printf("1/3\n"); break;
        case 6: printf("1/6\n"); break;
    }
    return 0;
}