                            /* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

char in[200010];
char out[200010];
int p = 0;

int main(){
    gets(in);
    int len = strlen(in);
    for(int i = 0; i < len; i++){
        if(p > 0 && out[p-1] == in[i])
            p--;
        else out[p++] = in[i];

    }
    for(int i = 0; i < p; i++)
        printf("%c", out[i]);
    printf("\n");
    //cin >> p;
    return 0;
}