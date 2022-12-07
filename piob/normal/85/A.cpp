#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#define FWD(a,b,c) for(int a=(b); a<(c); a++)
#define BCK(a,b,c) for(int a=(b); a>(c); a--)
#define FE(a,b) for(typeof(b.end()) a=b.begin(); a!=b.end(); a++)
#define ALL(a) a.begin(), a.end()
#define RINT(a) scanf("%d", &a)
#define RLL(a) scanf("%lld", &a)
#define RSTR(a) scanf("%s", a)
#define RDUB(a) scanf("%lf", &a)q
#define UNIQUE(a) erase(unique(a.begin(), a.end()), a.end())
#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define PACKS(a) int a; scanf("%d", &a); a++; while(--a)

//#define DEBUG
#ifdef DEBUG
    #define debug printf
#else
    #define debug
#endif

using namespace std;

char a, b, c, d;

int main(){
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("a\na\nb\nb\n");
    }else{
        if(n == 2){
            printf("aa\nbb\ncc\ndd\n");
        }else{
            a = 'b';
            b = 'c';
            c = 'e';
            d = 'f';
            printf("a");
            FWD(i,0,(n-1)/2){
                printf("%c%c", a, a);
                a = 'z' - a + 'a';
            }
            if(n%2==0)
                printf("a");
            printf("\n");
            printf("a");
            FWD(i,0,(n-1)/2){
                printf("%c%c", b, b);
                b = 'z' - b + 'a';
            }
            if(n%2==0)
                printf("a");
            printf("\n");
            FWD(i,0,n/2){
                printf("%c%c", c, c);
                c = 'z' - c + 'a';
            }
            if(n&1)
                printf("d");
            printf("\n");
            FWD(i,0,n/2){
                printf("%c%c", d, d);
                d = 'z' - d + 'a';
            }
            if(n&1)
                printf("d");
            printf("\n");
        }
    }
}