#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

typedef long long LL;

int n;
bool started;
bool inside;
char buff[100010];

int main(){
    scanf("%[^\n]", buff);
    int n = strlen(buff);
    started = inside = 0;
    FWD(i,0,n)
        switch(buff[i]){
            case '"':
                if(inside){
                    printf(">\n");
                    started = 0;
                }else{
                    printf("<");
                    started = 1;
                }
                inside = !inside;
                break;
            case ' ':
                if(inside)
                    printf(" ");
                else if(started){
                    printf(">\n");
                    started = 0;
                }   
                break;
            default:
                if(!started){
                    printf("<");
                    started = 1;
                }
                printf("%c", buff[i]);
        }
    if(started)
        printf(">\n");
    return 0;
}