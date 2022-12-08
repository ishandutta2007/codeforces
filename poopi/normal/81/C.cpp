                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define P pair<int, int>

int n, a, b;
P num[100010];
int out[100010];

int main(){
    cin >> n >> a >> b;
    int sg = 1;
    if(a < b)
        sg = -1;
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i].first);
        num[i].first *= sg;
        num[i].second = i;
    }
    sort(num, num + n);
    for(int i = 0; i < a; i++)
        out[num[i].second] = 1;
    for(int i = a; i < a + b; i++)
        out[num[i].second] = 2;
    if(a == b){
        for(int i = 0; i < a; i++)
            out[i] = 1;
        for(int i = a; i < a + b; i++)
            out[i] = 2;
    }
    for(int i = 0; i < n; i++){
        if(i > 0)
            printf(" ");
        printf("%d", out[i]);
    }
    printf("\n");
    return 0;
}