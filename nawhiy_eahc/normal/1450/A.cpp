#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        char s[202];
        scanf("%d", &n);
        scanf("%s", s);
        sort(s, s+n);
        printf("%s\n", s);
    }
}